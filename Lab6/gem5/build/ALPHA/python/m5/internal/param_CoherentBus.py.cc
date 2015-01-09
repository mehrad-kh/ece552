#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_CoherentBus[] = {
    120,156,197,88,109,111,219,70,18,158,37,41,218,146,173,88,
    142,157,216,105,211,70,69,17,156,174,184,70,105,218,164,47,
    23,4,151,180,119,125,65,235,230,168,30,146,170,215,178,52,
    185,146,40,75,164,192,93,39,213,193,254,114,14,238,250,173,
    63,162,232,135,254,143,254,175,187,153,89,146,166,157,180,40,
    208,66,182,197,197,114,185,156,157,151,231,153,157,101,8,249,
    95,13,175,191,180,1,212,142,0,136,240,39,96,2,48,21,
    208,23,32,164,128,104,3,246,106,144,189,1,81,13,158,0,
    244,45,144,22,28,97,199,134,47,44,72,86,249,29,23,38,
    54,143,8,152,55,64,58,208,175,193,131,100,29,28,233,194,
    94,3,178,175,65,8,145,8,120,24,45,65,180,12,79,80,
    58,118,234,44,112,25,162,6,119,234,16,173,112,167,1,243,
    22,200,21,232,163,240,37,232,55,81,212,43,40,234,28,139,
    250,137,68,69,248,100,19,162,38,77,71,93,62,167,153,14,
    205,228,53,206,177,148,181,66,179,22,244,91,69,127,29,250,
    235,69,255,60,244,207,67,180,6,178,5,227,13,24,160,169,
    173,82,222,38,72,27,198,23,160,127,1,36,254,54,225,8,
    189,17,173,243,220,139,60,247,124,57,119,139,231,110,67,127,
    27,36,254,182,204,92,23,122,157,11,232,219,248,127,248,215,
    65,223,130,94,197,230,145,204,84,156,38,126,156,12,210,216,
    162,231,46,53,20,137,144,154,165,60,36,239,82,72,126,4,
    142,71,100,229,33,57,4,20,44,72,255,137,5,135,220,57,
    180,96,222,129,3,1,99,7,34,27,14,112,153,26,41,48,
    20,112,100,193,63,109,154,112,136,173,131,78,124,17,28,109,
    226,49,102,39,26,73,75,112,88,131,131,26,244,30,30,88,
    52,176,87,135,236,7,248,215,101,22,186,204,66,45,56,192,
    214,129,35,7,14,93,120,128,147,112,104,92,39,243,197,195,
    3,180,20,71,122,29,7,181,221,169,152,75,166,68,113,150,
    4,83,169,207,99,223,159,5,89,48,245,223,77,71,50,147,
    137,190,183,175,58,141,98,94,170,174,205,2,61,242,248,69,
    155,60,50,157,105,22,152,38,82,175,96,103,16,39,145,63,
    77,163,253,137,212,203,36,205,31,196,19,233,251,252,240,195,
    233,44,205,244,95,179,44,205,60,114,42,15,78,210,160,124,
    131,92,26,78,82,37,59,180,26,47,227,145,120,77,179,7,
    51,150,72,10,176,178,244,114,36,85,152,197,51,141,177,50,
    18,105,54,73,235,80,148,184,81,62,54,221,100,160,186,251,
    195,238,40,157,74,245,234,245,238,180,59,77,71,193,244,245,
    155,183,186,50,148,55,111,222,232,126,28,236,222,234,14,229,
    244,102,119,119,63,158,68,221,187,31,223,255,224,110,119,54,
    215,163,52,233,226,104,156,104,137,78,154,116,159,114,207,53,
    156,68,142,83,143,227,161,31,179,137,254,72,78,102,50,35,
    13,213,115,164,132,104,137,85,225,10,91,116,68,19,123,53,
    188,108,113,217,90,17,59,49,25,25,146,225,132,48,187,192,
    212,247,192,209,195,224,239,89,144,93,38,196,140,241,39,40,
    196,136,155,30,61,179,248,217,223,201,59,102,116,108,19,14,
    204,224,1,163,12,225,134,51,111,83,224,19,96,168,212,96,
    236,130,129,16,34,207,96,42,155,83,139,211,73,140,133,194,
    29,80,223,157,148,144,180,0,189,143,236,197,161,139,184,212,
    191,25,149,189,14,41,190,195,216,208,163,88,165,143,19,142,
    0,245,153,71,61,244,201,253,249,167,187,99,25,106,117,5,
    7,62,79,247,219,97,144,36,169,110,7,81,212,14,180,206,
    226,221,125,45,85,91,167,237,171,170,83,167,144,175,23,240,
    42,229,205,103,5,156,40,244,8,39,115,19,197,161,198,155,
    13,190,97,255,43,169,17,26,163,52,82,56,78,34,134,82,
    123,164,164,62,135,205,221,98,57,198,96,199,45,16,163,228,
    100,160,27,12,190,64,41,159,151,163,113,198,25,189,253,40,
    152,236,75,77,243,149,14,52,174,74,93,179,208,130,145,182,
    77,182,22,166,146,251,252,36,77,162,57,106,26,135,47,147,
    18,219,140,183,85,32,196,93,64,180,45,97,235,66,19,209,
    215,178,66,50,202,201,177,198,56,187,72,46,0,142,189,200,
    51,8,98,238,8,243,76,199,226,68,193,214,49,17,219,212,
    163,151,61,130,180,247,60,53,151,169,121,161,112,192,226,188,
    208,60,237,133,235,180,178,197,166,135,118,110,100,73,166,157,
    19,100,186,116,76,38,204,140,61,34,133,69,212,57,38,133,
    77,110,200,238,228,12,32,186,33,8,240,113,5,247,236,28,
    175,69,70,187,5,100,61,194,97,21,140,195,10,24,61,138,
    11,35,209,187,244,115,142,188,114,150,142,28,26,71,190,78,
    43,175,230,24,106,50,118,26,34,36,0,88,185,91,217,165,
    239,97,103,190,69,46,173,58,115,11,119,187,7,73,147,183,
    45,222,250,120,163,55,121,196,248,216,116,28,66,219,192,134,
    139,249,118,164,136,246,179,44,253,102,222,78,7,109,13,133,
    14,183,175,170,107,87,213,159,49,49,180,239,112,170,49,169,
    193,144,63,147,179,12,73,94,231,27,67,92,159,73,236,231,
    219,9,58,157,182,118,142,21,187,154,243,148,210,25,165,167,
    5,251,185,81,250,153,212,126,155,150,109,176,147,109,216,194,
    171,33,88,55,63,229,76,201,37,6,63,197,235,30,185,155,
    44,150,64,197,158,215,51,154,179,81,100,158,247,135,19,168,
    89,152,73,222,43,164,92,65,59,23,74,140,208,101,147,210,
    196,132,255,2,151,97,2,254,3,132,7,12,123,206,29,102,
    41,93,20,214,13,154,254,21,112,18,122,198,150,103,25,14,
    90,121,154,66,138,170,55,121,170,217,1,63,130,111,43,25,
    236,200,6,65,187,149,157,23,90,213,221,202,41,89,203,64,
    250,85,59,146,115,146,222,20,166,81,160,104,154,33,178,93,
    18,249,56,25,150,245,17,102,167,197,97,108,217,44,232,147,
    110,239,31,35,140,182,130,231,197,134,85,193,205,159,168,121,
    181,132,140,40,198,22,162,230,149,211,185,187,178,131,249,38,
    95,254,141,116,113,88,251,53,151,11,189,138,140,146,29,181,
    130,29,55,74,118,72,206,225,79,184,30,167,214,34,16,28,
    89,2,15,61,88,187,208,121,195,1,89,131,190,75,60,226,
    106,83,228,52,19,69,102,163,140,120,98,131,96,247,236,24,
    199,149,56,48,33,166,230,155,5,103,18,138,242,237,73,48,
    221,141,130,59,159,209,162,180,114,88,16,207,42,204,104,85,
    205,32,210,136,159,179,132,111,175,23,230,60,90,112,22,121,
    13,215,40,205,96,206,68,105,200,169,227,179,145,108,79,229,
    116,23,143,98,163,120,214,30,76,130,33,71,203,206,205,252,
    180,48,83,115,184,79,111,206,92,218,236,164,237,48,77,48,
    229,239,135,58,205,218,145,196,243,137,140,12,224,79,178,151,
    235,189,32,27,42,46,237,246,30,83,247,12,34,235,227,145,
    51,198,154,246,31,133,75,204,73,168,76,244,92,198,26,246,
    224,126,137,103,12,61,55,249,236,22,53,127,164,230,42,156,
    205,126,208,197,53,122,180,24,57,208,197,148,83,23,122,253,
    36,117,239,211,123,207,32,240,39,191,134,192,230,123,69,78,
    99,183,248,208,177,4,114,153,14,185,253,6,125,45,160,145,
    21,226,246,210,111,229,54,51,226,12,184,240,197,239,74,105,
    239,198,25,91,225,113,61,249,75,116,22,85,19,155,134,206,
    99,81,20,222,85,251,248,128,191,253,44,68,249,97,38,3,
    45,77,224,158,91,184,201,156,50,140,10,95,150,225,43,236,
    42,79,33,111,150,182,29,113,45,52,223,172,212,197,28,77,
    241,0,11,23,172,157,15,216,124,223,50,229,243,49,76,157,
    210,11,148,15,18,249,216,127,202,19,166,64,38,125,130,217,
    76,38,209,113,241,203,79,22,12,5,74,74,84,214,21,149,
    8,86,186,155,120,61,77,76,178,172,98,40,199,177,86,82,
    113,241,17,101,16,135,69,44,59,116,22,57,206,193,30,69,
    210,100,221,50,225,122,239,64,145,132,75,152,70,114,34,181,
    124,58,70,154,94,205,143,136,145,196,205,41,157,227,201,133,
    235,127,188,159,248,254,89,100,239,183,112,141,62,228,231,46,
    202,222,46,230,239,186,83,23,188,69,158,250,6,106,116,163,
    13,212,84,185,115,229,49,217,215,74,251,249,75,93,177,65,
    49,242,233,156,182,19,76,205,167,23,254,152,224,189,68,205,
    203,133,31,25,181,230,0,196,103,11,115,178,67,148,243,217,
    142,183,107,239,26,141,83,146,48,54,220,11,148,68,253,245,
    90,57,242,137,156,154,175,77,149,177,94,92,140,145,143,243,
    119,120,187,58,157,77,56,38,153,28,198,10,93,197,235,228,
    179,115,114,145,147,244,139,207,204,64,213,55,207,32,126,166,
    44,52,231,222,59,228,56,117,27,27,250,6,84,95,171,11,
    215,162,239,141,182,104,136,166,112,196,106,179,110,215,221,122,
    205,198,24,211,200,134,104,216,245,198,170,160,255,75,24,241,
    134,117,169,81,23,255,7,134,140,79,150,
};

EmbeddedPython embedded_m5_internal_param_CoherentBus(
    "m5/internal/param_CoherentBus.py",
    "/nfs/ug/homes-0/m/moham356/ece552/Lab6/gem5/build/ALPHA/python/m5/internal/param_CoherentBus.py",
    "m5.internal.param_CoherentBus",
    data_m5_internal_param_CoherentBus,
    2043,
    6267);

} // anonymous namespace
