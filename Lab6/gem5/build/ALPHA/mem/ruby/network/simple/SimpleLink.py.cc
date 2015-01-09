#include "sim/init.hh"

namespace {

const uint8_t data_m5_objects_SimpleLink[] = {
    120,156,189,82,193,74,195,64,16,157,77,154,52,22,21,79,
    61,138,32,72,16,236,138,146,158,68,164,224,65,40,10,169,
    30,204,37,164,201,182,77,155,77,66,54,193,230,172,255,173,
    59,155,180,213,155,23,93,146,199,204,219,100,102,222,204,132,
    208,30,93,190,119,39,0,98,41,141,72,62,4,18,128,231,
    214,34,141,165,65,162,1,215,193,211,129,160,175,67,210,1,
    110,128,103,0,55,193,51,37,219,1,102,194,140,64,100,192,
    7,192,59,192,171,215,133,200,4,102,40,182,187,101,45,136,
    44,152,216,123,50,93,252,41,143,77,164,85,34,156,55,38,
    222,76,98,254,52,93,178,176,180,53,164,246,37,140,2,17,
    135,15,105,57,142,211,213,142,184,95,55,196,65,243,83,158,
    176,150,9,55,2,49,230,8,5,30,74,131,1,120,4,101,
    122,26,184,19,149,207,237,72,176,177,13,165,37,193,247,211,
    128,51,223,47,123,202,225,89,84,37,232,226,87,101,157,51,
    27,99,238,64,188,72,160,233,76,208,106,78,23,25,103,226,
    226,146,114,202,179,69,192,175,157,33,101,33,115,156,43,58,
    14,166,67,58,103,220,161,162,8,41,103,156,22,213,180,166,
    41,43,223,178,98,69,133,170,156,54,2,176,250,65,94,171,
    186,78,49,5,182,192,36,223,36,182,93,248,189,68,107,35,
    209,53,16,76,132,238,15,29,127,45,6,43,56,219,137,121,
    84,243,87,163,230,206,32,15,138,128,11,213,126,244,138,108,
    93,171,9,75,103,187,8,238,118,55,212,220,49,174,139,177,
    92,125,51,195,70,229,127,41,82,213,222,52,235,113,123,140,
    169,112,97,122,164,71,142,72,95,235,235,95,169,116,185,107,
};

EmbeddedPython embedded_m5_objects_SimpleLink(
    "m5/objects/SimpleLink.py",
    "/nfs/ug/homes-0/m/moham356/ece552/Lab6/gem5/src/mem/ruby/network/simple/SimpleLink.py",
    "m5.objects.SimpleLink",
    data_m5_objects_SimpleLink,
    384,
    865);

} // anonymous namespace