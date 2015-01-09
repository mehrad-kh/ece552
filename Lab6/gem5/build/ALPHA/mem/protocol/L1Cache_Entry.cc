/** \file L1Cache_Entry.cc
 *
 * Auto generated C++ code started by /nfs/ug/homes-0/m/moham356/ece552/Lab6/gem5/src/mem/slicc/symbols/Type.py:402
 */

#include <iostream>

#include "mem/protocol/L1Cache_Entry.hh"

using namespace std;
/** \brief Print the state of this object */
void
L1Cache_Entry::print(ostream& out) const
{
    out << "[L1Cache_Entry: ";
    out << "CacheState = " << m_CacheState << " ";
    out << "Dirty = " << m_Dirty << " ";
    out << "DataBlk = " << m_DataBlk << " ";
    out << "]";
}
