/** \file TriggerMsg.cc
 *
 * Auto generated C++ code started by /nfs/ug/homes-0/m/moham356/ece552/Lab6/gem5/src/mem/slicc/symbols/Type.py:402
 */

#include <iostream>

#include "mem/protocol/TriggerMsg.hh"

using namespace std;
/** \brief Print the state of this object */
void
TriggerMsg::print(ostream& out) const
{
    out << "[TriggerMsg: ";
    out << "Address = " << m_Address << " ";
    out << "Type = " << m_Type << " ";
    out << "Time = " << getTime() * g_eventQueue_ptr->getClock() << " ";
    out << "]";
}
