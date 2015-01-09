#include <limits.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "host.h"
#include "misc.h"
#include "machine.h"
#include "regs.h"
#include "memory.h"
#include "loader.h"
#include "syscall.h"
#include "dlite.h"
#include "options.h"
#include "stats.h"
#include "sim.h"
#include "decode.def"

#include "instr.h"

/* PARAMETERS OF THE TOMASULO'S ALGORITHM */

#define INSTR_QUEUE_SIZE         10

#define RESERV_INT_SIZE    4
#define RESERV_FP_SIZE     2
#define FU_INT_SIZE        2
#define FU_FP_SIZE         1

#define FU_INT_LATENCY     4
#define FU_FP_LATENCY      9

/* IDENTIFYING INSTRUCTIONS */

//unconditional branch, jump or call
#define IS_UNCOND_CTRL(op) (MD_OP_FLAGS(op) & F_CALL || \
                         MD_OP_FLAGS(op) & F_UNCOND)

//conditional branch instruction
#define IS_COND_CTRL(op) (MD_OP_FLAGS(op) & F_COND)

//floating-point computation
#define IS_FCOMP(op) (MD_OP_FLAGS(op) & F_FCOMP)

//integer computation
#define IS_ICOMP(op) (MD_OP_FLAGS(op) & F_ICOMP)

//load instruction
#define IS_LOAD(op)  (MD_OP_FLAGS(op) & F_LOAD)

//store instruction
#define IS_STORE(op) (MD_OP_FLAGS(op) & F_STORE)

//trap instruction
#define IS_TRAP(op) (MD_OP_FLAGS(op) & F_TRAP) 

#define USES_INT_FU(op) (IS_ICOMP(op) || IS_LOAD(op) || IS_STORE(op))
#define USES_FP_FU(op) (IS_FCOMP(op))

#define WRITES_CDB(op) (IS_ICOMP(op) || IS_LOAD(op) || IS_FCOMP(op))

/* FOR DEBUGGING */

//prints info about an instruction
#define PRINT_INST(out,instr,str,cycle)	\
  myfprintf(out, "%d: %s", cycle, str);		\
  md_print_insn(instr->inst, instr->pc, out); \
  myfprintf(stdout, "(%d)\n",instr->index);

#define PRINT_REG(out,reg,str,instr) \
  myfprintf(out, "reg#%d %s ", reg, str);	\
  md_print_insn(instr->inst, instr->pc, out); \
  myfprintf(stdout, "(%d)\n",instr->index);

/* VARIABLES */

//instruction queue for tomasulo
static instruction_t* instr_queue[INSTR_QUEUE_SIZE];
//number of instructions in the instruction queue
static int instr_queue_size = 0;

//reservation stations (each reservation station entry contains a pointer to an instruction)
static instruction_t* reservINT[RESERV_INT_SIZE];
static instruction_t* reservFP[RESERV_FP_SIZE];

//functional units
static instruction_t* fuINT[FU_INT_SIZE];
static instruction_t* fuFP[FU_FP_SIZE];

//common data bus
static instruction_t* commonDataBus = NULL;

//The map table keeps track of which instruction produces the value for each register
static instruction_t* map_table[MD_TOTAL_REGS];

//the index of the last instruction fetched
static int fetch_index = 0;

/* FUNCTIONAL UNITS */


/* RESERVATION STATIONS */

bool is_IFQ_empty()
{
  int i;
  for (i = 0; i < INSTR_QUEUE_SIZE; i++)
  {
    if(instr_queue[i] != NULL)
    {
      //printf("IFQ is NOT EMPTY\n");
      return false;
    }
  }
  //printf("IFQ is EMPTY\n");
  return true;
}


bool is_RS_empty()
{
  int i;
  for (i = 0; i < RESERV_INT_SIZE; i++)
  {
    if(reservINT[i] != NULL)
    {
      //printf("RSInt %d is NOT EMPTY\n", i);
      //print_tom_instr(reservINT[i]);
      return false;
    }
  }

   for (i = 0; i < RESERV_FP_SIZE; i++)
  {
    if(reservFP[i] != NULL)
    {
      //printf("RSFP is NOT EMPTY\n");
      return false;
    }
  }

  //printf("RS is EMPTY\n");
  return true;
}

bool is_FU_empty()
{
  int i;
  bool ret = true;
  for(i = 0; i <  FU_INT_SIZE; i++)
  {
    if(fuINT[i] != NULL)
    {
      //printf("FUInt is NOT EMPTY\n");
      //print_tom_instr(fuINT[i]);
      ret = false;
      break;
      //return false;
    }
  }

  for(i = 0; i <  FU_FP_SIZE; i++)
  {
    if(fuFP[i] != NULL)
    {
      //printf("FUFP is NOT EMPTY\n");
      //return false;
      ret =false;
      break;
    }
  }

  if(ret)
  {
    //printf("FU is EMPTY\n");
  }
  
  return ret;
}

/* 
 * Description: 
 * 	Checks if simulation is done by finishing the very last instruction
 *      Remember that simulation is done only if the entire pipeline is empty
 * Inputs:
 * 	sim_insn: the total number of instructions simulated
 * Returns:
 * 	True: if simulation is finished
 */
static bool is_simulation_done(counter_t sim_insn) {

  /* ECE552: YOUR CODE GOES HERE */
  // Simulation is done if the following is true
  // 1) if there is no more instuction to fetch
  // 2) IFQ is empty
  // 3) Reservation stations are empty
  // 4) FU's are empty
  if(is_FU_empty()  && is_IFQ_empty() && is_RS_empty())
  {
    return true;
  }
  return false; 
}

/* 
 * Description: 
 * 	Retires the instruction from writing to the Common Data Bus
 * Inputs:
 * 	current_cycle: the cycle we are at
 * Returns:
 * 	None
 */
void CDB_To_retire(int current_cycle) {

  /* ECE552: YOUR CODE GOES HERE */
  int i;
  if(commonDataBus != NULL)
  {
    // Updating the maptable
    for(i = 0; i < 2; i++)
    {
      if(commonDataBus->r_out[i] != DNA)
      {
        if(map_table[commonDataBus->r_out[i]] == commonDataBus)
        {
          // clear maptable
          map_table[commonDataBus->r_out[i]] = NULL;
        }
      }
    }
  }
  // Clearing commonDatabus
  commonDataBus = NULL;
}


/* 
 * Description: 
 * 	Moves an instruction from the execution stage to common data bus (if possible)
 * Inputs:
 * 	current_cycle: the cycle we are at
 * Returns:
 * 	None
 */
void execute_To_CDB(int current_cycle) {

  /* ECE552: YOUR CODE GOES HERE */
  int i, executed_store_num;
  int CDB_contention = 0;

  // Point to FU holding instruction that wins accessing to common data bus
  instruction_t** CDBInstr = NULL;  

  //multiple store might finish executing
  instruction_t* store_completed[FU_INT_SIZE];

  commonDataBus = NULL;


  for(i = 0; i < FU_INT_SIZE; i++)
  {
    store_completed[i] = NULL;
  }

  executed_store_num = 0;

  for(i = 0; i < FU_INT_SIZE; i++)
  {
    if(fuINT[i] != NULL)
    {
      if(current_cycle >= fuINT[i]->tom_execute_cycle + FU_INT_LATENCY)
      {
        if(IS_STORE(fuINT[i]->op))
        {
          store_completed[executed_store_num] = fuINT[i];
          executed_store_num++;
          // free the functional unit that store occupied 
          fuINT[i] = NULL;
          // we free the RS later
        }
        else if (CDBInstr == NULL || (CDBInstr != NULL && (*CDBInstr)->index > fuINT[i]->index))
        {
          CDBInstr = &fuINT[i];
        }
      }
    }
  }


  for(i = 0; i < FU_FP_SIZE; i++)
  {
    if(fuFP[i] != NULL)
    {
      if(current_cycle >= fuFP[i]->tom_execute_cycle + FU_FP_LATENCY)
      {
        if (CDBInstr == NULL || (CDBInstr != NULL && (*CDBInstr)->index > fuFP[i]->index))
        {
          CDBInstr = &fuFP[i];
        }
      }
    }
  }


  // at this point CDBInstr if(not null)points to the FU that holds the instruction winning access to CDB
  // We go and put that instruction in the common databus and free its functional unit.
  if(CDBInstr)
  {
    //update common databus
    commonDataBus = *CDBInstr;
    //updating tom_cdb_cycle of instruction
    commonDataBus->tom_cdb_cycle = current_cycle;

    // Updating the maptable
    // We will do it in CDS retire
    for(i = 0; i < 2; i++)
    {
      if(commonDataBus->r_out[i] != DNA)
      {
        if(map_table[commonDataBus->r_out[i]] == commonDataBus)
        {
          // clear maptable
          map_table[commonDataBus->r_out[i]] = NULL;
        }
      }
    }
    
    //printf("4) WriteBack:        ");
    //print_tom_instr(commonDataBus);

    //free its FU unit
    *CDBInstr = NULL; 

    //free its RS
    if(USES_INT_FU(commonDataBus->op))
    {
      for(i = 0 ; i < RESERV_INT_SIZE; i++)
      {
        if(reservINT[i] == commonDataBus)
        {
          reservINT[i] = NULL;
          break;
        }
      }
    }
    else
    {
      for(i = 0 ; i < RESERV_FP_SIZE; i++)
      {
        if(reservFP[i] == commonDataBus)
        {
          reservFP[i] = NULL;
          break;
        }
      }
    }
  }



  // Free reservation station correspoiding to instruction completed executions
  // store_completed holds all store instruction executed
  for(i = 0; i < executed_store_num; i++)
  {
    int j;
    for(j = 0; j < RESERV_INT_SIZE; j++)
    {
      if(reservINT[j] == store_completed[i])
      {
        reservINT[j] = NULL;
        break;
      }
    }
  }


  // Reorder Reservation Stations to keep order of instructions
  for(i = 0; i < RESERV_INT_SIZE; i++)
  {
    if(reservINT[i] == NULL)
    {
      int j = i;
      while (j < RESERV_INT_SIZE && reservINT[j] == NULL)
      {
        j++;
      }

      if(j != RESERV_INT_SIZE)
      {
        //reservINT[j] is not NULL. 
        reservINT[i] = reservINT[j];
        reservINT[j] = NULL;
      }
    }
  }



  for(i = 0; i < RESERV_FP_SIZE; i++)
  {
    if(reservFP[i] == NULL)
    {
      int j = i;
      while (j < RESERV_FP_SIZE && reservFP[j] == NULL)
      {
        j++;
      }

      if(j != RESERV_FP_SIZE)
      {
        //reservINT[j] is not NULL. 
        reservFP[i] = reservFP[j];
        reservFP[j] = NULL;
      }
    }
  }

}

/* 
 * Description: 
 * 	Moves instruction(s) from the issue to the execute stage (if possible). We prioritize old instructions
 *      (in program order) over new ones, if they both contend for the same functional unit.
 *      All RAW dependences need to have been resolved with stalls before an instruction enters execute.
 * Inputs:
 * 	current_cycle: the cycle we are at
 * Returns:
 * 	None
 */
void issue_To_execute(int current_cycle) {

  /* ECE552: YOUR CODE GOES HERE */
  // Scan all the avaialbe RS's. Order them Check if any of them are ready to execute such that
  // all RAW dependencies are resolved. If so go and check if there is a matching
  // avaialbe FU. If so the send it to execute.

  int i, j;

  // check if any instruction is ready to exectue.
  // If there is a mtaching FU available then send it 
  // to execute.

  j = 0;
  for(i = 0; i < FU_INT_SIZE; i++)
  {
    // check if functional unit is available. 
    if(fuINT[i] == NULL) 
    {
      // We try to find an instruction in RS which is ready for execute
      for( ; j < RESERV_INT_SIZE && reservINT[j] != NULL; j++)
      {
        //printf("Aboutt to Exec  --> ");
        //print_tom_instr(reservINT[j]);

        // check instruction in RS is ready to execute. 
        if(reservINT[j]->tom_execute_cycle == 0 &&
           reservINT[j]->Q[0] == NULL && 
           reservINT[j]->Q[1] == NULL && 
           reservINT[j]->Q[2] == NULL && 
           reservINT[j]->tom_issue_cycle != current_cycle) 
        {
          //update the instruction's tom_execute_cycle
          reservINT[j]->tom_execute_cycle = current_cycle;
          //put instruction in the functional
          fuINT[i] = reservINT[j];

          //printf("3) Execute  INT in %d:      ", i);
          //print_tom_instr(fuINT[i]);

          j++;
          break;
        }
      }
    }
  }


  j = 0;
  for(i = 0; i < FU_FP_SIZE; i++)
  {
    // check if functional unit is available. 
    if(fuFP[i] == NULL) 
    {
      // We try to find an instruction in RS which is ready for execute
      for( ; j < RESERV_FP_SIZE && reservFP[j] != NULL; j++)
      {
        // check instruction in RS is ready to execute. 
        if(reservFP[j]->tom_execute_cycle == 0 &&
           reservFP[j]->Q[0] == NULL && 
           reservFP[j]->Q[1] == NULL && 
           reservFP[j]->Q[2] == NULL && 
           reservFP[j]->tom_issue_cycle != current_cycle)
        {
          //update the instruction's tom_execute_cycle
          reservFP[j]->tom_execute_cycle = current_cycle;
          //put instruction in the functional
          fuFP[i] = reservFP[j];

          //printf("3) Execute  FP %d:      ", i);
          //print_tom_instr(fuFP[i]);

          j++;
          break;
        }
      }

    }
  }


   //Read data from commonDataBus and update instructions waiting values on CDB
  if(commonDataBus != NULL)
  {
    for(i = 0; i < RESERV_INT_SIZE; i++)
    {
      if(reservINT[i] != NULL)
      {
        for(j = 0; j < 3; j++)
        {
          if(reservINT[i]->Q[j] == commonDataBus)
          {
            //printf("YOOOOOOOOOOOOOOOOOOOOOOOOOOOOHOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
            //print_tom_instr(commonDataBus);
            //print_tom_instr(reservINT[i]);

            reservINT[i]->Q[j] = NULL;
          }
        }
      }  
    }

    for(i = 0; i < RESERV_FP_SIZE; i++)
    {
      if(reservFP[i] != NULL)
      {
        for(j = 0; j < 3; j++)
        {
          if(reservFP[i]->Q[j] == commonDataBus)
          {
            reservFP[i]->Q[j] = NULL;
          }
        }
      }
    }
  }

  return;
}

void pop_ifq(){

  int i;

  instr_queue[0] = NULL;
  for(i = 0; i < instr_queue_size - 1; i++)
  {
    instr_queue[i] = instr_queue[i+1];
    instr_queue[i+1] = NULL;
  }

  instr_queue_size --;
}


/* 
 * Description: 
 * 	Moves instruction(s) from the dispatch stage to the issue stage
 * Inputs:
 * 	current_cycle: the cycle we are at
 * Returns:
 * 	None
 */
void dispatch_To_issue(int current_cycle) {

  /* ECE552: YOUR CODE GOES HERE */

  //we check head of the IFQ if instruction is a jump/branch instruction
  //we just ignore it. Otherwie, we grab the instruction at the head of the queue
  //we check following
  // 1) Instruction at the head of the queue tom_dispatch_cycle is different than current_cycle
  // 2) A respective reservation station is availabe
  // If so, then we remove it from the queue and update the queue, update tom_issue_cycle, put in in RS

  int i,j;
  if(instr_queue[0] == NULL || instr_queue[0]->tom_dispatch_cycle == current_cycle)//empty ifq 
    return;


  if(IS_COND_CTRL(instr_queue[0]->op) || IS_UNCOND_CTRL(instr_queue[0]->op))
  {
    //instr_queue[0]->tom_dispatch_cycle = current_cycle;    ?????
    pop_ifq();
    return;
  }

  instruction_t* issue_instruction = NULL; 

  if(USES_INT_FU(instr_queue[0]->op))
  {
    for(i = 0; i < RESERV_INT_SIZE; i++) // check for free int reservation unit
    {
      if(reservINT[i] == NULL)
      {                
        reservINT[i] = instr_queue[0];    //allocate raservation station
        issue_instruction = instr_queue[0];
        break;
      }
    }      
  }


  else if(USES_FP_FU(instr_queue[0]->op))
  {
    for(i = 0; i < RESERV_FP_SIZE; i++) // check for free int reservation unit
    {
      if(reservFP[i] == NULL)
      {                     
        reservFP[i] = instr_queue[0];    //allocate raservation station
        issue_instruction = instr_queue[0];
        break;
      }    
    }
  }

  if(issue_instruction != NULL)
  {
    pop_ifq(); // pop first instruction from the queue
    issue_instruction->tom_issue_cycle = current_cycle;

    /* printf("2) Issue:    ");
    print_tom_instr(issue_instruction); */

    for(i = 0; i < 3; i++)
    {
      if(issue_instruction->r_in[i] != DNA)
      {
        issue_instruction->Q[i] = map_table[issue_instruction->r_in[i]];
      }
    }

    for(i = 0; i < 2; i++)
    {
      if(issue_instruction->r_out[i] != DNA)
      {
        map_table[issue_instruction->r_out[i]] = issue_instruction;
      }
    }
  }
  else
  {
    //printf("Not Issued\n");
  }

}

/* 
 * Description: 
 * 	Grabs an instruction from the instruction trace (if possible)
 * Inputs:
 *      trace: instruction trace with all the instructions executed
 * Returns:
 * 	None
 */
void fetch(instruction_trace_t* trace) {

  /* ECE552: YOUR CODE GOES HERE */
  if(fetch_index <= sim_num_insn)
  {
    fetch_index ++; 
  }
  

  while(fetch_index <= sim_num_insn && IS_TRAP(get_instr(trace, fetch_index)->op))
    fetch_index ++;  
}

/* 
 * Description: 
 * 	Calls fetch and dispatches an instruction at the same cycle (if possible)
 * Inputs:
 *      trace: instruction trace with all the instructions executed
 * 	current_cycle: the cycle we are at
 * Returns:
 * 	None
 */
void fetch_To_dispatch(instruction_trace_t* trace, int current_cycle) {

  //fetch(trace);
  //if there is spot in the queue fetch the innstruction, 
  //dispatch it to the queue, update tom_dispatch_cycle of inst
  //else do nothing

  /* ECE552: YOUR CODE GOES HERE */
  if(instr_queue_size < INSTR_QUEUE_SIZE)
  {
    fetch(trace);
    if(fetch_index <= sim_num_insn)
    {
      instr_queue[instr_queue_size] = get_instr(trace, fetch_index); 
      instr_queue[instr_queue_size]->tom_dispatch_cycle = current_cycle;
      instr_queue_size ++;

      /* printf("1) Dispatch:    ");
      print_tom_instr(instr_queue[instr_queue_size -1]); */
    }
    else
    {
      //printf("Not dispatched\n");
    }  
  }
}

/* 
 * Description: 
 * 	Performs a cycle-by-cycle simulation of the 4-stage pipeline
 * Inputs:
 *      trace: instruction trace with all the instructions executed
 * Returns:
 * 	The total number of cycles it takes to execute the instructions.
 * Extra Notes:
 * 	sim_num_insn: the number of instructions in the trace
 */
counter_t runTomasulo(instruction_trace_t* trace)
{
  //initialize instruction queue
  int i;
  for (i = 0; i < INSTR_QUEUE_SIZE; i++) {
    instr_queue[i] = NULL;
  }

  //initialize reservation stations
  for (i = 0; i < RESERV_INT_SIZE; i++) {
      reservINT[i] = NULL;
  }

  for(i = 0; i < RESERV_FP_SIZE; i++) {
      reservFP[i] = NULL;
  }

  //initialize functional units
  for (i = 0; i < FU_INT_SIZE; i++) {
    fuINT[i] = NULL;
  }

  for (i = 0; i < FU_FP_SIZE; i++) {
    fuFP[i] = NULL;
  }

  //initialize map_table to no producers
  int reg;
  for (reg = 0; reg < MD_TOTAL_REGS; reg++) {
    map_table[reg] = NULL;
  }
  
  int cycle = 1;
  //print_all_instr(trace, sim_num_insn);
  while (true) {

     /* ECE552: YOUR CODE GOES HERE */
    //printf("In cycle %d fetch Index %d queue size %d \n", cycle, fetch_index, instr_queue_size);
    //CDB_To_retire(cycle);
    execute_To_CDB(cycle);
    issue_To_execute(cycle);
    dispatch_To_issue(cycle);
    fetch_To_dispatch(trace, cycle);

    cycle++;

     if (is_simulation_done(sim_num_insn))
        break;
  }
  
  return cycle;
}
