#include "sim/init.hh"

namespace {

const uint8_t data_m5_objects_IntelTrace[] = {
    120,156,181,144,77,75,3,49,16,134,39,187,237,170,197,67,
    5,175,130,222,22,193,70,148,237,161,136,84,241,34,136,194,
    110,47,238,37,164,217,244,67,146,118,217,108,161,61,235,255,
    214,153,244,99,127,129,33,121,153,201,199,188,79,70,193,110,
    132,184,134,151,0,238,5,131,2,39,3,3,96,25,228,12,
    24,229,1,152,0,70,20,133,96,66,176,33,228,33,158,180,
    64,135,48,97,80,180,225,7,224,27,224,51,111,65,17,65,
    22,31,97,161,249,47,142,152,97,84,159,160,100,115,251,49,
    254,210,170,222,110,145,92,111,195,14,202,235,194,213,163,74,
    42,93,237,210,90,27,159,171,61,36,93,125,38,200,115,12,
    52,16,27,2,229,1,209,34,77,154,197,1,30,164,244,23,
    119,134,226,95,15,6,77,165,184,69,102,199,40,66,44,164,
    213,66,120,43,33,236,178,88,25,74,253,133,77,169,61,175,
    90,175,133,50,210,185,152,220,27,113,79,40,124,49,113,124,
    53,229,179,165,213,238,230,150,91,110,151,51,105,239,147,62,
    215,74,39,201,29,127,147,227,62,159,106,155,112,87,41,174,
    202,21,111,72,122,229,198,115,94,81,57,50,141,88,196,222,
    227,54,217,159,162,216,164,119,232,86,10,251,6,226,110,41,
    43,105,93,122,248,232,191,160,249,22,61,108,155,242,120,65,
    101,35,148,46,235,176,110,240,7,40,46,117,72,
};

EmbeddedPython embedded_m5_objects_IntelTrace(
    "m5/objects/IntelTrace.py",
    "/nfs/ug/homes-0/m/moham356/ece552/Lab6/gem5/src/cpu/IntelTrace.py",
    "m5.objects.IntelTrace",
    data_m5_objects_IntelTrace,
    317,
    563);

} // anonymous namespace
