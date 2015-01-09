#include "sim/init.hh"

namespace {

const uint8_t data_m5_objects_DummyChecker[] = {
    120,156,181,144,193,74,195,64,16,134,103,211,90,181,136,248,
    8,158,36,10,118,69,77,79,34,210,120,20,145,84,15,246,
    18,214,221,105,35,102,154,144,77,14,57,215,247,214,153,68,
    169,47,224,176,251,243,47,236,254,243,205,90,248,169,1,239,
    187,99,0,127,205,198,241,82,144,3,60,139,11,32,87,64,
    10,22,10,148,27,0,42,88,42,112,67,248,4,216,0,188,
    46,2,112,59,48,15,71,252,240,253,139,43,84,236,106,145,
    179,222,238,178,204,140,199,248,233,165,62,96,127,223,16,181,
    113,134,246,3,43,251,11,32,55,103,2,112,200,6,65,186,
    113,115,14,79,230,93,74,18,176,132,130,89,239,177,164,233,
    218,16,166,105,61,238,14,84,184,38,151,227,80,46,180,37,
    134,146,185,21,31,179,232,245,210,235,102,165,179,130,208,159,
    95,104,210,84,100,134,174,162,169,70,139,81,116,169,31,204,
    219,84,175,144,34,237,43,171,109,217,232,191,172,147,178,237,
    40,78,37,80,204,72,61,246,68,251,44,20,77,74,83,25,
    242,201,22,247,127,32,186,15,184,233,71,190,61,145,96,153,
    122,172,142,130,111,195,101,94,214,
};

EmbeddedPython embedded_m5_objects_DummyChecker(
    "m5/objects/DummyChecker.py",
    "/nfs/ug/homes-0/m/moham356/ece552/Lab6/gem5/src/cpu/DummyChecker.py",
    "m5.objects.DummyChecker",
    data_m5_objects_DummyChecker,
    265,
    463);

} // anonymous namespace