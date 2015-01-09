#include "sim/init.hh"

namespace {

const uint8_t data_MeshDirCorners[] = {
    120,156,189,86,205,110,219,70,16,158,37,37,90,63,150,100,
    203,242,95,236,22,57,10,53,18,182,105,29,95,10,163,169,
    157,67,11,39,5,148,0,106,141,186,4,45,174,45,90,34,
    41,145,43,91,46,200,30,234,2,237,177,79,144,151,232,91,
    20,125,129,158,242,0,125,136,118,102,40,202,86,163,0,57,
    69,36,71,59,179,243,243,205,236,112,151,29,152,252,116,124,
    190,184,15,16,237,225,192,193,91,64,31,224,229,100,36,112,
    164,129,212,224,76,128,163,195,47,0,55,0,223,29,235,224,
    228,136,57,206,129,147,135,23,77,3,109,221,127,241,215,20,
    56,82,68,62,82,85,164,207,100,212,61,116,195,131,32,244,
    101,24,117,178,160,164,240,37,5,37,29,137,126,4,133,62,
    214,160,245,130,61,180,136,52,9,154,42,32,177,44,223,246,
    164,101,169,18,51,94,224,140,250,196,150,9,178,140,58,161,
    59,80,110,224,55,201,245,45,137,78,144,152,254,89,100,142,
    206,205,110,224,201,232,193,199,166,103,122,65,215,246,62,221,
    125,108,202,142,220,221,125,100,30,217,167,143,205,115,233,237,
    154,81,216,49,61,233,153,225,232,244,218,244,165,186,10,194,
    158,169,130,65,208,15,206,93,25,153,179,201,60,28,92,51,
    204,251,20,74,67,98,136,78,30,255,182,241,89,196,231,128,
    242,187,204,1,196,2,46,0,146,60,15,4,36,6,156,35,
    187,192,180,192,180,8,227,31,33,6,56,60,9,33,41,65,
    92,130,11,141,202,223,211,32,250,38,99,53,98,67,11,226,
    5,184,208,73,120,35,64,12,119,178,105,157,167,127,130,184,
    48,119,58,199,211,200,22,103,167,241,110,199,6,196,121,232,
    9,136,254,0,149,131,159,5,168,60,73,80,190,133,106,73,
    25,226,50,49,13,210,66,72,127,103,90,6,168,5,194,131,
    74,56,117,163,193,247,26,36,139,144,84,32,174,80,99,144,
    178,33,38,202,11,4,13,53,29,131,229,31,102,242,2,181,
    84,82,165,66,168,34,251,17,88,136,85,72,106,16,99,123,
    161,89,13,53,196,15,26,12,63,19,113,21,172,18,185,78,
    150,184,114,203,48,86,128,125,144,130,56,60,57,99,8,53,
    72,234,132,14,45,111,113,173,64,210,128,120,5,226,69,232,
    225,202,188,154,196,143,151,185,32,216,209,5,136,151,192,65,
    8,117,112,112,17,170,112,129,180,1,155,55,160,83,177,104,
    178,12,123,24,120,216,19,237,57,102,5,194,181,57,53,37,
    230,13,211,249,102,229,59,102,88,106,228,55,222,213,116,241,
    174,105,158,172,223,217,180,50,107,58,63,234,248,91,46,111,
    49,45,239,215,89,121,75,51,125,21,253,163,189,181,152,37,
    152,87,145,225,159,90,155,214,111,21,198,175,64,45,82,119,
    113,128,223,33,89,131,241,175,44,42,167,162,107,72,214,33,
    94,39,64,235,40,195,181,11,247,117,228,227,53,82,105,172,
    39,27,211,217,76,178,9,241,42,3,209,50,32,213,44,207,
    13,76,186,150,49,155,200,112,166,55,144,251,223,18,239,235,
    120,183,135,59,122,123,2,176,60,5,184,158,1,52,166,0,
    215,8,13,67,48,24,224,235,25,128,247,32,229,38,25,160,
    100,235,237,0,239,221,5,184,149,2,92,156,3,240,181,142,
    119,123,248,151,78,173,72,175,69,133,124,210,128,93,189,104,
    46,227,30,244,92,213,145,30,125,114,96,119,186,210,58,8,
    124,21,6,253,190,12,83,241,163,55,196,13,20,227,14,39,
    59,42,8,175,239,78,208,62,125,248,236,201,29,145,75,91,
    172,155,3,126,107,49,229,96,164,100,104,185,14,190,231,0,
    125,215,239,209,152,54,111,57,86,150,31,56,146,25,215,79,
    25,151,118,78,151,118,77,151,119,121,58,64,72,110,217,183,
    195,83,30,94,73,247,188,171,154,181,236,44,240,71,158,213,
    25,140,34,142,138,123,122,215,10,131,171,72,49,144,235,129,
    100,27,123,48,144,190,195,160,159,68,17,194,199,195,225,105,
    24,6,161,210,83,12,172,229,184,151,120,146,176,168,47,125,
    222,203,21,109,224,161,237,159,75,78,35,77,42,13,37,49,
    176,12,109,149,70,24,167,74,197,73,126,148,111,170,70,9,
    50,215,220,206,252,81,50,17,251,11,248,152,74,199,95,249,
    234,8,245,120,252,116,156,142,201,115,139,99,242,209,70,169,
    102,16,10,83,30,147,165,201,14,175,93,234,187,200,217,132,
    119,57,207,158,112,185,9,130,169,199,78,208,31,121,8,98,
    57,115,18,89,3,92,185,52,80,186,150,210,179,93,223,65,
    46,55,169,49,159,232,46,31,191,188,180,157,96,228,171,214,
    118,118,214,251,41,34,108,141,190,213,151,151,178,223,34,55,
    173,15,104,94,231,58,94,241,63,134,230,124,165,29,169,172,
    85,174,100,58,230,4,113,133,186,25,19,33,32,98,222,231,
    129,174,232,224,246,236,158,124,153,42,93,83,220,232,55,254,
    100,41,138,162,110,8,186,42,162,134,215,210,228,105,24,117,
    252,95,19,91,162,46,54,180,162,190,163,27,168,183,41,86,
    137,23,203,162,170,111,35,45,137,109,148,204,80,157,116,30,
    228,12,177,130,215,146,168,162,126,29,125,87,112,126,85,155,
    39,67,4,218,243,102,62,123,229,188,221,135,3,59,180,189,
    136,215,5,185,224,244,2,223,220,180,87,178,4,184,173,91,
    123,51,31,70,239,171,152,132,227,243,244,99,109,159,122,33,
    162,254,46,137,146,182,86,248,15,174,248,57,99,
};

EmbeddedPython embedded_MeshDirCorners(
    "MeshDirCorners.py",
    "/nfs/ug/homes-0/m/moham356/ece552/Lab6/gem5/src/mem/ruby/network/topologies/MeshDirCorners.py",
    "MeshDirCorners",
    data_MeshDirCorners,
    1229,
    2687);

} // anonymous namespace
