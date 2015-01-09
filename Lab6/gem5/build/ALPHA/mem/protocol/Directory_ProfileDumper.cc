// Auto generated C++ code started by /nfs/ug/homes-0/m/moham356/ece552/Lab6/gem5/src/mem/slicc/symbols/StateMachine.py:1377
// Directory: Directory protocol

#include "mem/protocol/Directory_ProfileDumper.hh"

Directory_ProfileDumper::Directory_ProfileDumper()
{
}

void
Directory_ProfileDumper::registerProfiler(Directory_Profiler* profiler)
{
    m_profilers.push_back(profiler);
}

void
Directory_ProfileDumper::dumpStats(std::ostream& out) const
{
    out << " --- Directory ---\n";
    out << " - Event Counts -\n";
    for (Directory_Event event = Directory_Event_FIRST;
         event < Directory_Event_NUM;
         ++event) {
        out << (Directory_Event) event << " [";
        uint64 total = 0;
        for (int i = 0; i < m_profilers.size(); i++) {
             out << m_profilers[i]->getEventCount(event) << " ";
             total += m_profilers[i]->getEventCount(event);
        }
        out << "] " << total << "\n";
    }
    out << "\n";
    out << " - Transitions -\n";
    for (Directory_State state = Directory_State_FIRST;
         state < Directory_State_NUM;
         ++state) {
        for (Directory_Event event = Directory_Event_FIRST;
             event < Directory_Event_NUM;
             ++event) {
            if (m_profilers[0]->isPossible(state, event)) {
                out << (Directory_State) state << "  "
                    << (Directory_Event) event << " [";
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
