// Auto generated C++ code started by /nfs/ug/homes-0/m/moham356/ece552/Lab6/gem5/src/mem/slicc/symbols/StateMachine.py:1316
// Directory: Directory protocol

#ifndef __Directory_PROFILE_DUMPER_HH__
#define __Directory_PROFILE_DUMPER_HH__

#include <cassert>
#include <iostream>
#include <vector>

#include "Directory_Event.hh"
#include "Directory_Profiler.hh"

typedef std::vector<Directory_Profiler *> Directory_profilers;

class Directory_ProfileDumper
{
  public:
    Directory_ProfileDumper();
    void registerProfiler(Directory_Profiler* profiler);
    void dumpStats(std::ostream& out) const;

  private:
    Directory_profilers m_profilers;
};

#endif // __Directory_PROFILE_DUMPER_HH__
