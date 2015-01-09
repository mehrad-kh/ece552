#include "sim/init.hh"

namespace {

const uint8_t data_m5_stattestmain[] = {
    120,156,181,81,77,75,195,64,16,157,221,244,75,105,64,68,
    60,123,204,197,174,40,233,73,68,240,226,65,122,104,60,121,
    145,52,89,219,148,236,166,100,39,80,161,61,181,255,91,103,
    182,173,228,15,184,176,195,204,155,143,247,102,55,131,227,17,
    116,159,111,0,92,72,78,14,176,7,248,32,71,64,18,73,
    66,50,174,9,232,114,240,194,117,107,240,233,92,66,9,96,
    4,108,201,74,216,10,16,140,2,148,1,108,37,108,0,118,
    52,124,35,97,217,129,101,183,29,244,32,15,96,39,254,226,
    126,59,57,56,4,162,141,157,249,128,70,39,81,135,200,39,
    197,15,29,175,14,89,180,195,20,81,59,252,44,108,129,56,
    108,35,117,99,145,91,178,170,193,232,156,27,174,200,152,120,
    84,88,212,181,77,203,209,169,116,202,123,78,249,49,112,112,
    40,225,140,195,238,113,156,243,131,153,33,41,76,226,129,193,
    17,120,215,107,196,30,5,218,166,179,82,251,150,90,59,141,
    158,58,111,204,42,226,7,108,49,72,207,16,49,224,141,123,
    37,163,236,151,83,205,92,45,42,163,221,237,157,50,202,84,
    139,212,60,196,99,165,51,29,199,247,234,45,157,141,213,92,
    155,88,185,58,83,13,111,75,202,213,105,5,147,22,118,180,
    250,246,172,236,51,149,187,244,127,124,45,134,178,31,132,226,
    34,8,131,80,246,229,36,226,228,116,120,18,240,95,82,248,
    137,30,77,149,55,165,126,242,114,152,226,23,97,176,136,39,
};

EmbeddedPython embedded_m5_stattestmain(
    "m5/stattestmain.py",
    "/nfs/ug/homes-0/m/moham356/ece552/Lab6/gem5/src/unittest/stattestmain.py",
    "m5.stattestmain",
    data_m5_stattestmain,
    336,
    635);

} // anonymous namespace