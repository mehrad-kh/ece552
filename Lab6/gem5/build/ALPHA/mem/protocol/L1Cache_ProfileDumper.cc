// Auto generated C++ code started by /nfs/ug/homes-0/m/moham356/ece552/Lab6/gem5/src/mem/slicc/symbols/StateMachine.py:1377
// L1Cache: MSI L1 Cache

#include "mem/protocol/L1Cache_ProfileDumper.hh"

L1Cache_ProfileDumper::L1Cache_ProfileDumper()
{
}

void
L1Cache_ProfileDumper::registerProfiler(L1Cache_Profiler* profiler)
{
    m_profilers.push_back(profiler);
}

void
L1Cache_ProfileDumper::dumpStats(std::ostream& out) const
{
    out << " --- L1Cache ---\n";
    out << " - Event Counts -\n";
    for (L1Cache_Event event = L1Cache_Event_FIRST;
         event < L1Cache_Event_NUM;
         ++event) {
        out << (L1Cache_Event) event << " [";
        uint64 total = 0;
        for (int i = 0; i < m_profilers.size(); i++) {
             out << m_profilers[i]->getEventCount(event) << " ";
             total += m_profilers[i]->getEventCount(event);
        }
        out << "] " << total << "\n";
    }
    out << "\n";
    out << " - Transitions -\n";
    for (L1Cache_State state = L1Cache_State_FIRST;
         state < L1Cache_State_NUM;
         ++state) {
        for (L1Cache_Event event = L1Cache_Event_FIRST;
             event < L1Cache_Event_NUM;
             ++event) {
            if (m_profilers[0]->isPossible(state, event)) {
                out << (L1Cache_State) state << "  "
                    << (L1Cache_Event) event << " [";
                uint64 total = 0;
                for (int i = 0; i < m_profilers.size(); i++) {
                     out << m_profilers[i]->getTransitionCount(state, event) << " ";
                     total += m_profilers[i]->getTransitionCount(state, event);
                }
                out << "] " << total << "\n";
            }
        }
        out << "\n";
    }
}
