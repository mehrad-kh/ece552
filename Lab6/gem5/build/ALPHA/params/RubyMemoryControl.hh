#ifndef __PARAMS__RubyMemoryControl__
#define __PARAMS__RubyMemoryControl__

class MemoryControl;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/SimObject.hh"

struct RubyMemoryControlParams
    : public SimObjectParams
{
    MemoryControl * create();
    int bank_busy_time;
    int basic_bus_busy_time;
    int ranks_per_dimm;
    int mem_ctl_latency;
    int read_write_delay;
    int bank_bit_0;
    int mem_fixed_delay;
    int mem_bus_cycle_multiplier;
    int dimm_bit_0;
    int version;
    int banks_per_rank;
    int rank_bit_0;
    int rank_rank_delay;
    int refresh_period;
    int mem_random_arbitrate;
    int dimms_per_channel;
    int tFaw;
    int bank_queue_size;
};

#endif // __PARAMS__RubyMemoryControl__
