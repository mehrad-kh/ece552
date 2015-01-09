/* cache.c - cache module routines */

/* SimpleScalar(TM) Tool Suite
 * Copyright (C) 1994-2003 by Todd M. Austin, Ph.D. and SimpleScalar, LLC.
 * All Rights Reserved. 
 * 
 * THIS IS A LEGAL DOCUMENT, BY USING SIMPLESCALAR,
 * YOU ARE AGREEING TO THESE TERMS AND CONDITIONS.
 * 
 * No portion of this work may be used by any commercial entity, or for any
 * commercial purpose, without the prior, written permission of SimpleScalar,
 * LLC (info@simplescalar.com). Nonprofit and noncommercial use is permitted
 * as described below.
 * 
 * 1. SimpleScalar is provided AS IS, with no warranty of any kind, express
 * or implied. The user of the program accepts full responsibility for the
 * application of the program and the use of any results.
 * 
 * 2. Nonprofit and noncommercial use is encouraged. SimpleScalar may be
 * downloaded, compiled, executed, copied, and modified solely for nonprofit,
 * educational, noncommercial research, and noncommercial scholarship
 * purposes provided that this notice in its entirety accompanies all copies.
 * Copies of the modified software can be delivered to persons who use it
 * solely for nonprofit, educational, noncommercial research, and
 * noncommercial scholarship purposes provided that this notice in its
 * entirety accompanies all copies.
 * 
 * 3. ALL COMMERCIAL USE, AND ALL USE BY FOR PROFIT ENTITIES, IS EXPRESSLY
 * PROHIBITED WITHOUT A LICENSE FROM SIMPLESCALAR, LLC (info@simplescalar.com).
 * 
 * 4. No nonprofit user may place any restrictions on the use of this software,
 * including as modified by the user, by any other authorized user.
 * 
 * 5. Noncommercial and nonprofit users may distribute copies of SimpleScalar
 * in compiled or executable form as set forth in Section 2, provided that
 * either: (A) it is accompanied by the corresponding machine-readable source
 * code, or (B) it is accompanied by a written offer, with no time limit, to
 * give anyone a machine-readable copy of the corresponding source code in
 * return for reimbursement of the cost of distribution. This written offer
 * must permit verbatim duplication by anyone, or (C) it is distributed by
 * someone who received only the executable form, and is accompanied by a
 * copy of the written offer of source code.
 * 
 * 6. SimpleScalar was developed by Todd M. Austin, Ph.D. The tool suite is
 * currently maintained by SimpleScalar LLC (info@simplescalar.com). US Mail:
 * 2395 Timbercrest Court, Ann Arbor, MI 48105.
 * 
 * Copyright (C) 1994-2003 by Todd M. Austin, Ph.D. and SimpleScalar, LLC.
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "host.h"
#include "misc.h"
#include "machine.h"
#include "cache.h"

/* cache access macros */
#define CACHE_TAG(cp, addr)	((addr) >> (cp)->tag_shift)
#define CACHE_SET(cp, addr)	(((addr) >> (cp)->set_shift) & (cp)->set_mask)
#define CACHE_BLK(cp, addr)	((addr) & (cp)->blk_mask)
#define CACHE_TAGSET(cp, addr)	((addr) & (cp)->tagset_mask)

/* extract/reconstruct a block address */
#define CACHE_BADDR(cp, addr)	((addr) & ~(cp)->blk_mask)
#define CACHE_MK_BADDR(cp, tag, set)					\
  (((tag) << (cp)->tag_shift)|((set) << (cp)->set_shift))

/* index an array of cache blocks, non-trivial due to variable length blocks */
#define CACHE_BINDEX(cp, blks, i)					\
  ((struct cache_blk_t *)(((char *)(blks)) +				\
			  (i)*(sizeof(struct cache_blk_t) +		\
			       ((cp)->balloc				\
				? (cp)->bsize*sizeof(byte_t) : 0))))

/* cache data block accessor, type parameterized */
#define __CACHE_ACCESS(type, data, bofs)				\
  (*((type *)(((char *)data) + (bofs))))

/* cache data block accessors, by type */
#define CACHE_DOUBLE(data, bofs)  __CACHE_ACCESS(double, data, bofs)
#define CACHE_FLOAT(data, bofs)	  __CACHE_ACCESS(float, data, bofs)
#define CACHE_WORD(data, bofs)	  __CACHE_ACCESS(unsigned int, data, bofs)
#define CACHE_HALF(data, bofs)	  __CACHE_ACCESS(unsigned short, data, bofs)
#define CACHE_BYTE(data, bofs)	  __CACHE_ACCESS(unsigned char, data, bofs)

/* cache block hashing macros, this macro is used to index into a cache
   set hash table (to find the correct block on N in an N-way cache), the
   cache set index function is CACHE_SET, defined above */
#define CACHE_HASH(cp, key)						\
  (((key >> 24) ^ (key >> 16) ^ (key >> 8) ^ key) & ((cp)->hsize-1))

/* copy data out of a cache block to buffer indicated by argument pointer p */
#define CACHE_BCOPY(cmd, blk, bofs, p, nbytes)	\
  if (cmd == Read)							\
    {									\
      switch (nbytes) {							\
      case 1:								\
	*((byte_t *)p) = CACHE_BYTE(&blk->data[0], bofs); break;	\
      case 2:								\
	*((half_t *)p) = CACHE_HALF(&blk->data[0], bofs); break;	\
      case 4:								\
	*((word_t *)p) = CACHE_WORD(&blk->data[0], bofs); break;	\
      default:								\
	{ /* >= 8, power of two, fits in block */			\
	  int words = nbytes >> 2;					\
	  while (words-- > 0)						\
	    {								\
	      *((word_t *)p) = CACHE_WORD(&blk->data[0], bofs);	\
	      p += 4; bofs += 4;					\
	    }\
	}\
      }\
    }\
  else /* cmd == Write */						\
    {									\
      switch (nbytes) {							\
      case 1:								\
	CACHE_BYTE(&blk->data[0], bofs) = *((byte_t *)p); break;	\
      case 2:								\
        CACHE_HALF(&blk->data[0], bofs) = *((half_t *)p); break;	\
      case 4:								\
	CACHE_WORD(&blk->data[0], bofs) = *((word_t *)p); break;	\
      default:								\
	{ /* >= 8, power of two, fits in block */			\
	  int words = nbytes >> 2;					\
	  while (words-- > 0)						\
	    {								\
	      CACHE_WORD(&blk->data[0], bofs) = *((word_t *)p);		\
	      p += 4; bofs += 4;					\
	    }\
	}\
    }\
  }

/* bound sqword_t/dfloat_t to positive int */
#define BOUND_POS(N)		((int)(MIN(MAX(0, (N)), 2147483647)))

/* unlink BLK from the hash table bucket chain in SET */
static void
unlink_htab_ent(struct cache_t *cp,		/* cache to update */
		struct cache_set_t *set,	/* set containing bkt chain */
		struct cache_blk_t *blk)	/* block to unlink */
{
  struct cache_blk_t *prev, *ent;
  int index = CACHE_HASH(cp, blk->tag);

  /* locate the block in the hash table bucket chain */
  for (prev=NULL,ent=set->hash[index];
       ent;
       prev=ent,ent=ent->hash_next)
    {
      if (ent == blk)
	break;
    }
  assert(ent);

  /* unlink the block from the hash table bucket chain */
  if (!prev)
    {
      /* head of hash bucket list */
      set->hash[index] = ent->hash_next;
    }
  else
    {
      /* middle or end of hash bucket list */
      prev->hash_next = ent->hash_next;
    }
  ent->hash_next = NULL;
}

/* insert BLK onto the head of the hash table bucket chain in SET */
static void
link_htab_ent(struct cache_t *cp,		/* cache to update */
	      struct cache_set_t *set,		/* set containing bkt chain */
	      struct cache_blk_t *blk)		/* block to insert */
{
  int index = CACHE_HASH(cp, blk->tag);

  /* insert block onto the head of the bucket chain */
  blk->hash_next = set->hash[index];
  set->hash[index] = blk;
}

/* where to insert a block onto the ordered way chain */
enum list_loc_t { Head, Tail };

/* insert BLK into the order way chain in SET at location WHERE */
static void
update_way_list(struct cache_set_t *set,	/* set contained way chain */
		struct cache_blk_t *blk,	/* block to insert */
		enum list_loc_t where)		/* insert location */
{
  /* unlink entry from the way list */
  if (!blk->way_prev && !blk->way_next)
    {
      /* only one entry in list (direct-mapped), no action */
      assert(set->way_head == blk && set->way_tail == blk);
      /* Head/Tail order already */
      return;
    }
  /* else, more than one element in the list */
  else if (!blk->way_prev)
    {
      assert(set->way_head == blk && set->way_tail != blk);
      if (where == Head)
	{
	  /* already there */
	  return;
	}
      /* else, move to tail */
      set->way_head = blk->way_next;
      blk->way_next->way_prev = NULL;
    }
  else if (!blk->way_next)
    {
      /* end of list (and not front of list) */
      assert(set->way_head != blk && set->way_tail == blk);
      if (where == Tail)
	{
	  /* already there */
	  return;
	}
      set->way_tail = blk->way_prev;
      blk->way_prev->way_next = NULL;
    }
  else
    {
      /* middle of list (and not front or end of list) */
      assert(set->way_head != blk && set->way_tail != blk);
      blk->way_prev->way_next = blk->way_next;
      blk->way_next->way_prev = blk->way_prev;
    }

  /* link BLK back into the list */
  if (where == Head)
    {
      /* link to the head of the way list */
      blk->way_next = set->way_head;
      blk->way_prev = NULL;
      set->way_head->way_prev = blk;
      set->way_head = blk;
    }
  else if (where == Tail)
    {
      /* link to the tail of the way list */
      blk->way_prev = set->way_tail;
      blk->way_next = NULL;
      set->way_tail->way_next = blk;
      set->way_tail = blk;
    }
  else
    panic("bogus WHERE designator");
}

/* create and initialize a general cache structure */
struct cache_t *			/* pointer to cache created */
cache_create(char *name,		/* name of the cache */
	     int nsets,			/* total number of sets in cache */
	     int bsize,			/* block (line) size of cache */
	     int balloc,		/* allocate data space for blocks? */
	     int usize,			/* size of user data to alloc w/blks */
	     int assoc,			/* associativity of cache */
	     enum cache_policy policy,	/* replacement policy w/in sets */
	     /* block access function, see description w/in struct cache def */
	     unsigned int (*blk_access_fn)(enum mem_cmd cmd,
					   md_addr_t baddr, int bsize,
					   struct cache_blk_t *blk,
					   tick_t now, int prefetch),
	     unsigned int hit_latency,	/* latency in cycles for a hit */
	     int prefetch_type)		/* prefetcher type */
{
  struct cache_t *cp;
  struct cache_blk_t *blk;
  int i, j, bindex;

  /* check all cache parameters */
  if (nsets <= 0)
    fatal("cache size (in sets) `%d' must be non-zero", nsets);
  if ((nsets & (nsets-1)) != 0)
    fatal("cache size (in sets) `%d' is not a power of two", nsets);
  /* blocks must be at least one datum large, i.e., 8 bytes for SS */
  if (bsize < 8)
    fatal("cache block size (in bytes) `%d' must be 8 or greater", bsize);
  if ((bsize & (bsize-1)) != 0)
    fatal("cache block size (in bytes) `%d' must be a power of two", bsize);
  if (usize < 0)
    fatal("user data size (in bytes) `%d' must be a positive value", usize);
  if (assoc <= 0)
    fatal("cache associativity `%d' must be non-zero and positive", assoc);
  if ((assoc & (assoc-1)) != 0)
    fatal("cache associativity `%d' must be a power of two", assoc);
  if (!blk_access_fn)
    fatal("must specify miss/replacement functions");
  if (prefetch_type < 0)
    fatal("prefetcher type `%d'must be a positive number", prefetch_type);

  /* allocate the cache structure */
  cp = (struct cache_t *)
    calloc(1, sizeof(struct cache_t) + (nsets-1)*sizeof(struct cache_set_t));
  if (!cp)
    fatal("out of virtual memory");

  /* initialize user parameters */
  cp->name = mystrdup(name);
  cp->nsets = nsets;
  cp->bsize = bsize;
  cp->balloc = balloc;
  cp->usize = usize;
  cp->assoc = assoc;
  cp->policy = policy;
  cp->hit_latency = hit_latency;
  cp->prefetch_type = prefetch_type;


  /* ECE552 Assignment 4 - BEGIN CODE */
  if(prefetch_type == 2)
  {
    // Open ended prefetcher
    cp->ghb = (struct GHB_entry *)malloc(sizeof(struct GHB_entry));
    cp->ghb->miss_address = 0;
    cp->ghb->next = cp->ghb;
    cp->ghb->prev = cp->ghb;
    cp->ghb->CZone_next = cp->ghb;
    cp->ghb->CZone_prev = cp->ghb;
    cp->ghb_size = 0;
    cp->ghb_tail = cp->ghb;

    cp->it = (struct IT_entry *)malloc(IT_SIZE * sizeof(struct IT_entry));
    for(i = 0; i < IT_SIZE; i++)
    {
      cp->it[i].tag = 0;
      cp->it[i].linked_entry = NULL;
    }
  }

  if(prefetch_type > 2)
  {
    // stride prefetcher
    cp->rpt = (struct rpt *)malloc(sizeof(struct rpt));
    cp->rpt->size = prefetch_type;
    cp->rpt->index_size = log_base2(prefetch_type);
    cp->rpt->table = (struct rpt_entry *)calloc(prefetch_type, sizeof(struct rpt_entry));
  }
  /* ECE552 Assignment 4 - END CODE */

  /* miss/replacement functions */
  cp->blk_access_fn = blk_access_fn;

  /* compute derived parameters */
  cp->hsize = CACHE_HIGHLY_ASSOC(cp) ? (assoc >> 2) : 0;
  cp->blk_mask = bsize-1;
  cp->set_shift = log_base2(bsize);
  cp->set_mask = nsets-1;
  cp->tag_shift = cp->set_shift + log_base2(nsets);
  cp->tag_mask = (1 << (32 - cp->tag_shift))-1;
  cp->tagset_mask = ~cp->blk_mask;
  cp->bus_free = 0;

  /* print derived parameters during debug */
  debug("%s: cp->hsize     = %d", cp->name, cp->hsize);
  debug("%s: cp->blk_mask  = 0x%08x", cp->name, cp->blk_mask);
  debug("%s: cp->set_shift = %d", cp->name, cp->set_shift);
  debug("%s: cp->set_mask  = 0x%08x", cp->name, cp->set_mask);
  debug("%s: cp->tag_shift = %d", cp->name, cp->tag_shift);
  debug("%s: cp->tag_mask  = 0x%08x", cp->name, cp->tag_mask);

  /* initialize cache stats */
  cp->hits = 0;
  cp->misses = 0;
  cp->replacements = 0;
  cp->writebacks = 0;
  cp->invalidations = 0;

  cp->read_hits = 0;
  cp->read_misses = 0;
  cp->prefetch_hits = 0;
  cp->prefetch_misses = 0;

  /* blow away the last block accessed */
  cp->last_tagset = 0;
  cp->last_blk = NULL;

  /* allocate data blocks */
  cp->data = (byte_t *)calloc(nsets * assoc,
			      sizeof(struct cache_blk_t) +
			      (cp->balloc ? (bsize*sizeof(byte_t)) : 0));
  if (!cp->data)
    fatal("out of virtual memory");

  /* slice up the data blocks */
  for (bindex=0,i=0; i<nsets; i++)
    {

      cp->sets[i].way_head = NULL;
      cp->sets[i].way_tail = NULL;
      /* get a hash table, if needed */
      if (cp->hsize)
	{
	  cp->sets[i].hash =
	    (struct cache_blk_t **)calloc(cp->hsize,
					  sizeof(struct cache_blk_t *));
	  if (!cp->sets[i].hash)
	    fatal("out of virtual memory");
	}
      /* NOTE: all the blocks in a set *must* be allocated contiguously,
	 otherwise, block accesses through SET->BLKS will fail (used
	 during random replacement selection) */
      cp->sets[i].blks = CACHE_BINDEX(cp, cp->data, bindex);
      
      /* link the data blocks into ordered way chain and hash table bucket
         chains, if hash table exists */
      for (j=0; j<assoc; j++)
	{
	  /* locate next cache block */
	  blk = CACHE_BINDEX(cp, cp->data, bindex);
	  bindex++;

	  /* invalidate new cache block */
	  blk->status = 0;		
	  blk->tag = 0;
	  blk->ready = 0;
	  blk->user_data = (usize != 0
			    ? (byte_t *)calloc(usize, sizeof(byte_t)) : NULL);

	  /* insert cache block into set hash table */
	  if (cp->hsize)
	    link_htab_ent(cp, &cp->sets[i], blk);

	  /* insert into head of way list, order is arbitrary at this point */
	  blk->way_next = cp->sets[i].way_head;
	  blk->way_prev = NULL;
	  if (cp->sets[i].way_head)
	    cp->sets[i].way_head->way_prev = blk;
	  cp->sets[i].way_head = blk;
	  if (!cp->sets[i].way_tail)
	    cp->sets[i].way_tail = blk;
	}
    }
  return cp;
}

/* parse policy */
enum cache_policy			/* replacement policy enum */
cache_char2policy(char c)		/* replacement policy as a char */
{
  switch (c) {
  case 'l': return LRU;
  case 'r': return Random;
  case 'f': return FIFO;
  default: fatal("bogus replacement policy, `%c'", c);
  }
}

/* print cache configuration */
void
cache_config(struct cache_t *cp,	/* cache instance */
	     FILE *stream)		/* output stream */
{
  fprintf(stream,
	  "cache: %s: %d sets, %d byte blocks, %d bytes user data/block\n",
	  cp->name, cp->nsets, cp->bsize, cp->usize);
  fprintf(stream,
	  "cache: %s: %d-way, `%s' replacement policy, write-back, %d prefetcher type\n",
	  cp->name, cp->assoc,
	  cp->policy == LRU ? "LRU"
	  : cp->policy == Random ? "Random"
	  : cp->policy == FIFO ? "FIFO"
	  : (abort(), ""),
	  cp->prefetch_type);
}

/* register cache stats */
void
cache_reg_stats(struct cache_t *cp,	/* cache instance */
		struct stat_sdb_t *sdb)	/* stats database */
{
  char buf[512], buf1[512], *name;

  /* get a name for this cache */
  if (!cp->name || !cp->name[0])
    name = "<unknown>";
  else
    name = cp->name;

  sprintf(buf, "%s.accesses", name);
  sprintf(buf1, "%s.hits + %s.misses", name, name);
  stat_reg_formula(sdb, buf, "total number of accesses", buf1, "%12.0f");
  sprintf(buf, "%s.hits", name);
  stat_reg_counter(sdb, buf, "total number of hits", &cp->hits, 0, NULL);
  sprintf(buf, "%s.misses", name);
  stat_reg_counter(sdb, buf, "total number of misses", &cp->misses, 0, NULL);
  sprintf(buf, "%s.replacements", name);
  stat_reg_counter(sdb, buf, "total number of replacements",
		 &cp->replacements, 0, NULL);
  sprintf(buf, "%s.writebacks", name);
  stat_reg_counter(sdb, buf, "total number of writebacks",
		 &cp->writebacks, 0, NULL);
  sprintf(buf, "%s.invalidations", name);
  stat_reg_counter(sdb, buf, "total number of invalidations",
		 &cp->invalidations, 0, NULL);
  sprintf(buf, "%s.miss_rate", name);
  sprintf(buf1, "%s.misses / %s.accesses", name, name);
  stat_reg_formula(sdb, buf, "miss rate (i.e., misses/ref)", buf1, NULL);
  sprintf(buf, "%s.repl_rate", name);
  sprintf(buf1, "%s.replacements / %s.accesses", name, name);
  stat_reg_formula(sdb, buf, "replacement rate (i.e., repls/ref)", buf1, NULL);
  sprintf(buf, "%s.wb_rate", name);
  sprintf(buf1, "%s.writebacks / %s.accesses", name, name);
  stat_reg_formula(sdb, buf, "writeback rate (i.e., wrbks/ref)", buf1, NULL);
  sprintf(buf, "%s.inv_rate", name);
  sprintf(buf1, "%s.invalidations / %s.accesses", name, name);
  stat_reg_formula(sdb, buf, "invalidation rate (i.e., invs/ref)", buf1, NULL);

  sprintf(buf, "%s.read_accesses", name);
  sprintf(buf1, "%s.read_hits +  %s.read_misses", name, name);
  stat_reg_formula(sdb, buf, "total number of read accesses", buf1, "%12.0f");
  sprintf(buf, "%s.read_hits", name);
  stat_reg_counter(sdb, buf, "total number of read hits", &cp->read_hits, 0, NULL);
  sprintf(buf, "%s.read_misses", name);
  stat_reg_counter(sdb, buf, "total number of read misses", &cp->read_misses, 0, NULL);
  sprintf(buf, "%s.read_miss_rate", name);
  sprintf(buf1, "%s.read_misses / %s.read_accesses", name, name);
  stat_reg_formula(sdb, buf, "read miss rate", buf1, NULL);
  
  sprintf(buf, "%s.prefetch_accesses", name);
  sprintf(buf1, "%s.prefetch_hits +  %s.prefetch_misses", name, name);
  stat_reg_formula(sdb, buf, "total number of prefetch accesses", buf1, "%12.0f");
  sprintf(buf, "%s.prefetch_hits", name);
  stat_reg_counter(sdb, buf, "total number of prefetch hits", &cp->prefetch_hits, 0, NULL);
  sprintf(buf, "%s.prefetch_misses", name);
  stat_reg_counter(sdb, buf, "total number of prefetch misses", &cp->prefetch_misses, 0, NULL);


}


md_addr_t get_PC();

/* Next Line Prefetcher */
void next_line_prefetcher(struct cache_t *cp, md_addr_t addr) {

  //prefetch(cp, addr + cp->bsize);
  md_addr_t next_addr = addr + cp->bsize; 
  // a prefetch is generated if and only if the calculated prefetch address is not already in the local cache
  md_addr_t set = CACHE_SET(cp, next_addr);
  md_addr_t tag = CACHE_TAG(cp, next_addr);
  md_addr_t baddr = CACHE_MK_BADDR(cp, tag, set);

  if(cache_probe(cp, baddr))
  {
    return;
  }
  cache_access(cp, Read, baddr, NULL, cp->bsize, NULL, NULL, NULL, 1);
}


int it_index(md_addr_t miss_address){
  int index_offset = log_base2(CSIZE);
  int index_mask = IT_SIZE - 1;
  //miss_address
  return ((miss_address >> index_offset) & (index_mask));
}

md_addr_t it_tag(md_addr_t miss_address){
  int tag_offset = log_base2(CSIZE) + log_base2(IT_SIZE);
  //printf("tag_offset %d\n", tag_offset);
  //printf("tag %d\n", miss_address >> tag_offset);

  //miss address
  return (miss_address >> tag_offset);
}

void ghb_insert(struct cache_t *cp, md_addr_t miss_address){
  int index = it_index(miss_address);
  md_addr_t tag = it_tag(miss_address);
  //printf("missaddress == %x\n", miss_address);
  //printf("tag == %x\n", tag);
  //printf("index == %x\n", index);

  struct GHB_entry * new_entry = (struct GHB_entry *)malloc(sizeof(struct GHB_entry));
  new_entry->miss_address = miss_address;

  //insert it at beginning of the ghb
  new_entry->next = cp->ghb->next;
  new_entry->prev = cp->ghb->next->prev;
  cp->ghb->next->prev = new_entry;
  cp->ghb->next = new_entry;
  
  new_entry->CZone_next = cp->ghb;
  new_entry->CZone_prev = cp->ghb;

  cp->ghb_size++;     // increment ghb_size

  if(cp->ghb_tail == NULL || cp->ghb_tail == cp->ghb)
  {
    cp->ghb_tail = new_entry;
  }
  
  if(cp->it[index].linked_entry == NULL)   // entry is empty
  {
    
    //linked_entry should point to new_entry
    cp->it[index].linked_entry = new_entry;
  }

  else if(cp->it[index].tag == tag)      // hit
  {
     new_entry->CZone_prev = cp->ghb;
     cp->it[index].linked_entry->CZone_prev = new_entry;
     new_entry->CZone_next = cp->it[index].linked_entry;
     cp->it[index].linked_entry = new_entry;
     ghb_correlation(cp, miss_address);
  }

  else   // conflict
  {
    //printf("No conflict !!! \n");
    struct GHB_entry * curr = cp->it[index].linked_entry;
    struct GHB_entry * curr_next;
    while(curr != cp->ghb)
    {
      if(curr == cp->ghb_tail)
      {
        cp->ghb_tail = curr->prev;
      }
      curr_next = curr->CZone_next;

      //unlink curr
      curr->next->prev = curr->prev;
      curr->prev->next = curr->next;
      free(curr);
      cp->ghb_size--;
      curr = curr_next;
    }
    cp->it[index].linked_entry = new_entry;
  }

  // set the tag
  cp->it[index].tag = tag; 

  if(cp->ghb_size > GHB_SIZE)
  {
    assert(cp->ghb_size == GHB_SIZE + 1);
    //remove tail
    ghb_delete(cp);
  }
}


void ghb_delete(struct cache_t *cp){

  // remove last element at the tail of the ghb
  struct GHB_entry * deleted_entry = cp->ghb_tail;
   assert(deleted_entry->next == cp->ghb);


  cp->ghb_tail = deleted_entry->prev;
  if(deleted_entry->CZone_prev == cp->ghb)
  {
    int index = it_index(deleted_entry->miss_address);
    md_addr_t tag = it_tag(deleted_entry->miss_address);

    assert(cp->it[index].tag == tag && cp->it[index].linked_entry == deleted_entry);
    cp->it[index].tag = 0;
    cp->it[index].linked_entry = cp->ghb;
  }

  deleted_entry->prev->next = deleted_entry->next;
  deleted_entry->next->prev = deleted_entry->prev;

  deleted_entry->CZone_prev->CZone_next = deleted_entry->CZone_next;
  deleted_entry->CZone_next->CZone_prev = deleted_entry->CZone_prev;
  free(deleted_entry);
  cp->ghb_size--;
}

struct delta * delta_buffer_insert(struct delta * delta_buffer, struct delta * new_delta)
{
  new_delta->next = delta_buffer;
  delta_buffer = new_delta;
}

int correlation_hit(long * correlation_key_reg, long * correlation_comp_reg)
{
  if(correlation_key_reg[0] == correlation_comp_reg[0] &&
     correlation_key_reg[1] == correlation_comp_reg[1])
    return 1;

  return 0;
}

void prefetch(struct cache_t *cp, md_addr_t addr)
{
  md_addr_t set = CACHE_SET(cp, addr);
  md_addr_t tag = CACHE_TAG(cp, addr);
  md_addr_t baddr = CACHE_MK_BADDR(cp, tag, set);

  if(cache_probe(cp, baddr)) return;
  cache_access(cp, Read, baddr, NULL, cp->bsize, NULL, NULL, NULL, 1);
}

void trigger_prefetch(struct cache_t *cp, md_addr_t *  miss_address, struct delta *  delta_buffer)
{
  struct delta * curr = delta_buffer->next->next;
  int degree = DEGREE;
  int size = 0;
  while(curr)
  {
    curr = curr->next;
    size++;
  }
  if(size < degree)
  {
    return;
  }
  curr = delta_buffer->next->next;
  while(degree > 0)
  {
    if(curr == NULL)
    {
  
      curr = delta_buffer;
    }
    if((curr->delta & 0x80000000) != 0)
    {
  
      miss_address += curr->delta;
    }    
    else
    {
      miss_address += curr->delta;
    }
    
    prefetch(cp, miss_address);
    curr = curr->next;
    degree--;
  }
}

void destroy_delta_buffer(struct delta * delta_buffer)
{ 
  struct delta * temp;
  while(delta_buffer)
  {
    temp = delta_buffer;
    delta_buffer = delta_buffer->next;
    free(temp);
  }
}

void ghb_correlation(struct cache_t *cp, md_addr_t miss_address){
  int i;
  long delta;  
  long correlation_key_reg[2] = {0};
  long correlation_comp_reg[2] = {0};
  struct delta * delta_buffer = NULL;

  correlation_key_reg[1] = miss_address - cp->ghb->next->CZone_next->miss_address;
  if(cp->ghb->next->CZone_next->CZone_next != cp->ghb)
  {
    correlation_key_reg[0] = cp->ghb->next->CZone_next->miss_address - cp->ghb->next->CZone_next->CZone_next->miss_address;
  }
  else
  {
    return; // not enough history
  }

  if(correlation_key_reg[1] == correlation_key_reg[0])
  {
    for(i = 0; i < DEGREE; i++)
    {
      prefetch(cp, miss_address + (i + 1) * correlation_key_reg[0]);
    }
    return;
  }

  // shif computed deltas into delta_buffer
  struct delta * new_delta = (struct delta *)malloc(sizeof(struct delta));
  new_delta->delta = correlation_key_reg[1];
  new_delta->next = NULL;
  delta_buffer = delta_buffer_insert(delta_buffer, new_delta);

  new_delta = (struct delta *)malloc(sizeof(struct delta));
  new_delta->delta = correlation_key_reg[0];
  new_delta->next = NULL;
  delta_buffer = delta_buffer_insert(delta_buffer, new_delta);

  int counter = 0;

  struct GHB_entry * curr = cp->ghb->next->CZone_next->CZone_next;
  while(curr != cp->ghb)
  {
    if(curr->CZone_next != cp->ghb)
    {
      delta = curr->miss_address - curr->CZone_next->miss_address;
      // insert into delta buffer
      new_delta = (struct delta *)malloc(sizeof(struct delta));
      new_delta->delta = delta;
      new_delta->next = NULL;
      delta_buffer = delta_buffer_insert(delta_buffer, new_delta);
      correlation_comp_reg[1] = correlation_comp_reg[0];
      correlation_comp_reg[0] = delta;
      counter++;
    }
    if(counter >= 2 && correlation_hit(correlation_key_reg, correlation_comp_reg))
    {
      trigger_prefetch(cp, miss_address, delta_buffer);
      break;
    }
    curr = curr->CZone_next;
  }
  destroy_delta_buffer(delta_buffer);
}


/* Open Ended Prefetcher */
void open_ended_prefetcher(struct cache_t *cp, md_addr_t addr) {
  // addr should be a miss address
  if(is_miss)
  {
    ghb_insert(cp, addr); 
  }
}



//given a pc address find its tag used to store in rpt
md_addr_t find_pc_tag(struct rpt *rpt, md_addr_t pc)
{
  return pc >> (rpt->index_size + log_base2(sizeof(md_inst_t)));
}
//given a pc address find its location/index in rpt 
int find_pc_index(struct rpt *rpt, md_addr_t pc)
{
  return (pc >> log_base2(sizeof(md_inst_t))) & (rpt->size -1);
}


md_addr_t get_tag(struct rpt *rpt, int index){
  return rpt->table[index].tag;
}

md_addr_t get_prev_addr(struct rpt *rpt, int index){
  return rpt->table[index].prev_addr;
}

md_addr_t get_stride(struct rpt *rpt, int index){
  return rpt->table[index].stride;
}

enum sign get_stride_sign(struct rpt *rpt, int index){
  return rpt->table[index].stride_sign;
}

enum rpt_state get_state(struct rpt *rpt, int index){
  return rpt->table[index].state;
}

void set_tag(struct rpt *rpt, md_addr_t tag, int index){
  rpt->table[index].tag = tag;
} 
void set_prev_addr(struct rpt *rpt, md_addr_t prev_addr, int index){
  rpt->table[index].prev_addr = prev_addr;
}
void set_stride(struct rpt *rpt, md_addr_t stride, int index){
  rpt->table[index].stride = stride;
}

void set_stride_sign(struct rpt *rpt, enum sign stride_sign, int index){
  rpt->table[index].stride_sign = stride_sign;
}

void set_state(struct rpt *rpt, enum rpt_state state, int index){
  rpt->table[index].state = state;
}

/* Determine new state */
enum rpt_state det_new_state(enum rpt_state state, int condtion)
{
  enum rpt_state new_state; 
  switch(state)
  {
    case initial:
    {
      if(condtion) new_state = steady;
      else new_state = transient;
      break;
    }
    case transient:
    {
      if(condtion) new_state = steady;
      else new_state = no_prediction;
      break;
    }
    case steady:
    {
      if(condtion) new_state = steady;
      else new_state = initial;
      break;
    }
    case no_prediction:
    {
      if(condtion) new_state = transient;
      else new_state = no_prediction;
      break;
    }
    default:
    {
      new_state = initial;
    }
  }
  return new_state;
}

/* Stride Prefetcher */
void stride_prefetcher(struct cache_t *cp, md_addr_t addr) {
	
  struct rpt * rpt = cp->rpt;
  md_addr_t tag = find_pc_tag(rpt, get_PC());
  int index = find_pc_index(rpt, get_PC());

  if(tag != get_tag(rpt, index)) //scenario1
  {
    // There is no corresponding entry in the RPT. 
    // 1) The instruction is entered in the RPT
    // 2) prev_addr is set to addr
    // 3) stride set to 0
    // 4) stride_sign to negative
    // 5) state to init
    set_tag(rpt, tag, index);
    set_prev_addr(rpt, addr, index);
    set_stride(rpt, 0, index);
    set_stride_sign(rpt, negative, index);
    set_state(rpt, initial, index);
    return;
  }

  // scenario 2
  // There is a corresponding entry
  // 1) new stride is computed computed as addr - prev-addr
  // 2) Depending on the current state and whether the new 
  //    stride is equal to the stride is the RPT the transitions are performed
  // 3) Following the update, a prefetch is generated if state of entry is not no_pred
  md_addr_t prev_addr = get_prev_addr(rpt, index);
  md_addr_t stride = get_stride(rpt, index);
  enum sign stride_sign = get_stride_sign(rpt, index);
  enum rpt_state state = get_state(rpt, index);
  md_addr_t new_stride = MAX(addr, prev_addr) - MIN(addr, prev_addr);
  enum sign new_stride_sign = (addr >= prev_addr);
  int condition = (stride == new_stride) && (stride_sign == new_stride_sign);
  enum rpt_state new_state = det_new_state(state, condition);

  set_tag(rpt, tag, index);
  set_prev_addr(rpt, addr, index);
  set_state(rpt, new_state, index);

  if((new_state == transient || new_state == no_prediction) && !condition)
  {
    set_stride(rpt, new_stride, index);
    set_stride_sign(rpt, new_stride_sign , index);
  }

  if(new_state != no_prediction)
  {
    md_addr_t next_addr;
    if(get_stride_sign(rpt, index) == negative)
    {
      next_addr = addr - get_stride(rpt, index);;
    }
    else
    {
      next_addr = addr + get_stride(rpt, index);;
    }
    md_addr_t set = CACHE_SET(cp, next_addr);
    md_addr_t tag = CACHE_TAG(cp, next_addr);
    md_addr_t baddr = CACHE_MK_BADDR(cp, tag, set);

    if(cache_probe(cp, baddr))
    {
      return;
    }
    cache_access(cp, Read, baddr, NULL, cp->bsize, NULL, NULL, NULL, 1);
  }
}


/* cache x might generate a prefetch after a regular cache access to address addr */
void generate_prefetch(struct cache_t *cp, md_addr_t addr) {

	switch(cp->prefetch_type) {
		case 0:
		   // prefetching is not enabled;
		   // do nothing
		   break;
		case 1:
		   // Next Line Prefetcher
		   next_line_prefetcher(cp, addr);
		   break;
		case 2:
		   // Open Ended Prefetcher
		   open_ended_prefetcher(cp, addr);
		   break;
		default:
		   // Stride Prefetcher with cp->prefetch_type number of entries in the Reference Prediction Table (RPT)
		   stride_prefetcher(cp, addr);
	}

}


/* print cache stats */
void
cache_stats(struct cache_t *cp,		/* cache instance */
	    FILE *stream)		/* output stream */
{
  double sum = (double)(cp->hits + cp->misses);

  fprintf(stream,
	  "cache: %s: %.0f hits %.0f misses %.0f repls %.0f invalidations\n",
	  cp->name, (double)cp->hits, (double)cp->misses,
	  (double)cp->replacements, (double)cp->invalidations);
  fprintf(stream,
	  "cache: %s: miss rate=%f  repl rate=%f  invalidation rate=%f\n",
	  cp->name,
	  (double)cp->misses/sum, (double)(double)cp->replacements/sum,
	  (double)cp->invalidations/sum);
}

/* access a cache, perform a CMD operation on cache CP at address ADDR,
   places NBYTES of data at *P, returns latency of operation if initiated
   at NOW, places pointer to block user data in *UDATA, *P is untouched if
   cache blocks are not allocated (!CP->BALLOC), UDATA should be NULL if no
   user data is attached to blocks */
unsigned int				/* latency of access in cycles */
cache_access(struct cache_t *cp,	/* cache to access */
	     enum mem_cmd cmd,		/* access type, Read or Write */
	     md_addr_t addr,		/* address of access */
	     void *vp,			/* ptr to buffer for input/output */
	     int nbytes,		/* number of bytes to access */
	     tick_t now,		/* time of access */
	     byte_t **udata,		/* for return of user data ptr */
	     md_addr_t *repl_addr,	/* for address of replaced block */
	     int prefetch)		/* 1 if the access is a prefetch, 0 if it is not */
{
  byte_t *p = vp;
  md_addr_t tag = CACHE_TAG(cp, addr);
  md_addr_t set = CACHE_SET(cp, addr);
  md_addr_t bofs = CACHE_BLK(cp, addr);
  struct cache_blk_t *blk, *repl;
  int lat = 0;

  is_miss = 0;

  /* default replacement address */
  if (repl_addr)
    *repl_addr = 0;

  /* check alignments */
  if ((nbytes & (nbytes-1)) != 0 || (addr & (nbytes-1)) != 0)
    fatal("cache: access error: bad size or alignment, addr 0x%08x", addr);

  /* access must fit in cache block */
  /* FIXME:
     ((addr + (nbytes - 1)) > ((addr & ~cp->blk_mask) + (cp->bsize - 1))) */
  if ((addr + nbytes) > ((addr & ~cp->blk_mask) + cp->bsize))
    fatal("cache: access error: access spans block, addr 0x%08x", addr);

  /* permissions are checked on cache misses */

  /* check for a fast hit: access to same block */
  if (CACHE_TAGSET(cp, addr) == cp->last_tagset)
    {
      /* hit in the same block */
      blk = cp->last_blk;
      goto cache_fast_hit;
    }
    
  if (cp->hsize)
    {
      /* higly-associativity cache, access through the per-set hash tables */
      int hindex = CACHE_HASH(cp, tag);

      for (blk=cp->sets[set].hash[hindex];
	   blk;
	   blk=blk->hash_next)
	{
	  if (blk->tag == tag && (blk->status & CACHE_BLK_VALID))
	    goto cache_hit;
	}
    }
  else
    {
      /* low-associativity cache, linear search the way list */
      for (blk=cp->sets[set].way_head;
	   blk;
	   blk=blk->way_next)
	{
	  if (blk->tag == tag && (blk->status & CACHE_BLK_VALID))
	    goto cache_hit;
	}
    }

  /* cache block not found */

  /* **MISS** */
  if (prefetch == 0 ) {
     is_miss = 1;
     cp->misses++;

     if (cmd == Read) {	
	cp->read_misses++;
     }
  }
  else {
     cp->prefetch_misses++;
  }


  /* select the appropriate block to replace, and re-link this entry to
     the appropriate place in the way list */
  switch (cp->policy) {
  case LRU:
  case FIFO:
    repl = cp->sets[set].way_tail;
    update_way_list(&cp->sets[set], repl, Head);
    break;
  case Random:
    {
      int bindex = myrand() & (cp->assoc - 1);
      repl = CACHE_BINDEX(cp, cp->sets[set].blks, bindex);
    }
    break;
  default:
    panic("bogus replacement policy");
  }

  /* remove this block from the hash bucket chain, if hash exists */
  if (cp->hsize)
    unlink_htab_ent(cp, &cp->sets[set], repl);

  /* blow away the last block to hit */
  cp->last_tagset = 0;
  cp->last_blk = NULL;

  /* write back replaced block data */
  if (repl->status & CACHE_BLK_VALID)
    {
      cp->replacements++;

      if (repl_addr)
	*repl_addr = CACHE_MK_BADDR(cp, repl->tag, set);
 
      /* don't replace the block until outstanding misses are satisfied */
      lat += BOUND_POS(repl->ready - now);
 
      /* stall until the bus to next level of memory is available */
      lat += BOUND_POS(cp->bus_free - (now + lat));
 
      /* track bus resource usage */
      cp->bus_free = MAX(cp->bus_free, (now + lat)) + 1;

      if (repl->status & CACHE_BLK_DIRTY)
	{
	  /* write back the cache block */
	  cp->writebacks++;
	  lat += cp->blk_access_fn(Write,
				   CACHE_MK_BADDR(cp, repl->tag, set),
				   cp->bsize, repl, now+lat, 0);
	}
    }

  /* update block tags */
  repl->tag = tag;
  repl->status = CACHE_BLK_VALID;	/* dirty bit set on update */

  /* read data block */
  lat += cp->blk_access_fn(Read, CACHE_BADDR(cp, addr), cp->bsize,
			   repl, now+lat, prefetch);

  /* copy data out of cache block */
  if (cp->balloc)
    {
      CACHE_BCOPY(cmd, repl, bofs, p, nbytes);
    }

  /* update dirty status */
  if (cmd == Write)
    repl->status |= CACHE_BLK_DIRTY;

  /* get user block data, if requested and it exists */
  if (udata)
    *udata = repl->user_data;

  /* update block status */
  repl->ready = now+lat;

  /* link this entry back into the hash table */
  if (cp->hsize)
    link_htab_ent(cp, &cp->sets[set], repl);

  if (prefetch == 0) {	/* only regular cache accesses can generate a prefetch */
  	generate_prefetch(cp, addr);
  }

  /* return latency of the operation */
  return lat;


 cache_hit: /* slow hit handler */
  
  /* **HIT** */
  if (prefetch == 0) {

     cp->hits++;

     if (cmd == Read) {	
	   cp->read_hits++;
     }
  }
  else {
     cp->prefetch_hits++;
  }


  /* copy data out of cache block, if block exists */
  if (cp->balloc)
    {
      CACHE_BCOPY(cmd, blk, bofs, p, nbytes);
    }

  /* update dirty status */
  if (cmd == Write)
    blk->status |= CACHE_BLK_DIRTY;

  /* if LRU replacement and this is not the first element of list, reorder */
  if (blk->way_prev && cp->policy == LRU)
    {
      /* move this block to head of the way (MRU) list */
      update_way_list(&cp->sets[set], blk, Head);
    }

  /* tag is unchanged, so hash links (if they exist) are still valid */

  /* record the last block to hit */
  cp->last_tagset = CACHE_TAGSET(cp, addr);
  cp->last_blk = blk;

  /* get user block data, if requested and it exists */
  if (udata)
    *udata = blk->user_data;

  if (prefetch == 0) {	/* only regular cache accesses can generate a prefetch */
	generate_prefetch(cp, addr);
  }


  /* return first cycle data is available to access */
  return (int) MAX(cp->hit_latency, (blk->ready - now));

 cache_fast_hit: /* fast hit handler */
  
  /* **FAST HIT** */
  if (prefetch == 0) {
     
     cp->hits++;

     if (cmd == Read) {	
        cp->read_hits++;
     }
  }
  else {
     cp->prefetch_hits++;
  }


  /* copy data out of cache block, if block exists */
  if (cp->balloc)
    {
      CACHE_BCOPY(cmd, blk, bofs, p, nbytes);
    }

  /* update dirty status */
  if (cmd == Write)
    blk->status |= CACHE_BLK_DIRTY;

  /* this block hit last, no change in the way list */

  /* tag is unchanged, so hash links (if they exist) are still valid */

  /* get user block data, if requested and it exists */
  if (udata)
    *udata = blk->user_data;

  /* record the last block to hit */
  cp->last_tagset = CACHE_TAGSET(cp, addr);
  cp->last_blk = blk;

  if (prefetch == 0) {	/* only regular cache accesses can generate a prefetch */
     generate_prefetch(cp, addr);
  }

  /* return first cycle data is available to access */
  return (int) MAX(cp->hit_latency, (blk->ready - now));
}

/* return non-zero if block containing address ADDR is contained in cache
   CP, this interface is used primarily for debugging and asserting cache
   invariants */
int					/* non-zero if access would hit */
cache_probe(struct cache_t *cp,		/* cache instance to probe */
	    md_addr_t addr)		/* address of block to probe */
{
  md_addr_t tag = CACHE_TAG(cp, addr);
  md_addr_t set = CACHE_SET(cp, addr);
  struct cache_blk_t *blk;

  /* permissions are checked on cache misses */

  if (cp->hsize)
  {
    /* higly-associativity cache, access through the per-set hash tables */
    int hindex = CACHE_HASH(cp, tag);
    
    for (blk=cp->sets[set].hash[hindex];
	 blk;
	 blk=blk->hash_next)
    {	
      if (blk->tag == tag && (blk->status & CACHE_BLK_VALID))
	  return TRUE;
    }
  }
  else
  {
    /* low-associativity cache, linear search the way list */
    for (blk=cp->sets[set].way_head;
	 blk;
	 blk=blk->way_next)
    {
      if (blk->tag == tag && (blk->status & CACHE_BLK_VALID))
	  return TRUE;
    }
  }
  
  /* cache block not found */
  return FALSE;
}

/* flush the entire cache, returns latency of the operation */
unsigned int				/* latency of the flush operation */
cache_flush(struct cache_t *cp,		/* cache instance to flush */
	    tick_t now)			/* time of cache flush */
{
  int i, lat = cp->hit_latency; /* min latency to probe cache */
  struct cache_blk_t *blk;

  /* blow away the last block to hit */
  cp->last_tagset = 0;
  cp->last_blk = NULL;

  /* no way list updates required because all blocks are being invalidated */
  for (i=0; i<cp->nsets; i++)
    {

      for (blk=cp->sets[i].way_head; blk; blk=blk->way_next)
	{
	  if (blk->status & CACHE_BLK_VALID)
	    {
	      cp->invalidations++;
	      blk->status &= ~CACHE_BLK_VALID;

	      if (blk->status & CACHE_BLK_DIRTY)
		{
		  /* write back the invalidated block */
          	  cp->writebacks++;
		  lat += cp->blk_access_fn(Write,
					   CACHE_MK_BADDR(cp, blk->tag, i),
					   cp->bsize, blk, now+lat, 0);
		}
	    }
	}
    }

  /* return latency of the flush operation */
  return lat;
}

/* flush the block containing ADDR from the cache CP, returns the latency of
   the block flush operation */
unsigned int				/* latency of flush operation */
cache_flush_addr(struct cache_t *cp,	/* cache instance to flush */
		 md_addr_t addr,	/* address of block to flush */
		 tick_t now)		/* time of cache flush */
{
  md_addr_t tag = CACHE_TAG(cp, addr);
  md_addr_t set = CACHE_SET(cp, addr);
  struct cache_blk_t *blk;
  int lat = cp->hit_latency; /* min latency to probe cache */

  if (cp->hsize)
    {
      /* higly-associativity cache, access through the per-set hash tables */
      int hindex = CACHE_HASH(cp, tag);

      for (blk=cp->sets[set].hash[hindex];
	   blk;
	   blk=blk->hash_next)
	{
	  if (blk->tag == tag && (blk->status & CACHE_BLK_VALID))
	    break;
	}
    }
  else
    {
      /* low-associativity cache, linear search the way list */
      for (blk=cp->sets[set].way_head;
	   blk;
	   blk=blk->way_next)
	{
	  if (blk->tag == tag && (blk->status & CACHE_BLK_VALID))
	    break;
	}
    }

  if (blk)
    {
      cp->invalidations++;
      blk->status &= ~CACHE_BLK_VALID;

      /* blow away the last block to hit */
      cp->last_tagset = 0;
      cp->last_blk = NULL;

      if (blk->status & CACHE_BLK_DIRTY)
	{
	  /* write back the invalidated block */
          cp->writebacks++;
	  lat += cp->blk_access_fn(Write,
				   CACHE_MK_BADDR(cp, blk->tag, set),
				   cp->bsize, blk, now+lat, 0);
	}
      /* move this block to tail of the way (LRU) list */
      update_way_list(&cp->sets[set], blk, Tail);
    }

  /* return latency of the operation */
  return lat;
}
