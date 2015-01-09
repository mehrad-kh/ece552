/** \file DMARequestMsg.cc
 *
 * Auto generated C++ code started by /nfs/ug/homes-0/m/moham356/ece552/Lab6/gem5/src/mem/slicc/symbols/Type.py:402
 */

#include <iostream>

#include "mem/protocol/DMARequestMsg.hh"

using namespace std;
/** \brief Print the state of this object */
void
DMARequestMsg::print(ostream& out) const
{
    out << "[DMARequestMsg: ";
    out << "Type = " << m_Type << " ";
    out << "PhysicalAddress = " << m_PhysicalAddress << " ";
    out << "LineAddress = " << m_LineAddress << " ";
    out << "Requestor = " << m_Requestor << " ";
    out << "Destination = " << m_Destination << " ";
    out << "DataBlk = " << m_DataBlk << " ";
    out << "Len = " << m_Len << " ";
    out << "MessageSize = " << m_MessageSize << " ";
    out << "Time = " << getTime() * g_eventQueue_ptr->getClock() << " ";
    out << "]";
}
