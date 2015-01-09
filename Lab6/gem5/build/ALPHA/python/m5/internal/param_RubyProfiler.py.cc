#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_RubyProfiler[] = {
    120,156,197,88,235,115,219,198,17,223,3,64,72,164,68,137,
    178,94,81,226,214,76,51,158,176,153,198,116,157,218,233,195,
    227,137,211,54,175,201,40,46,152,25,219,108,166,8,4,28,
    73,80,120,176,192,209,14,59,210,151,200,147,246,91,254,134,
    78,167,31,250,127,244,255,106,119,247,0,136,178,228,86,51,
    237,80,18,121,115,92,44,246,246,241,219,189,189,243,161,248,
    171,225,247,131,54,64,254,161,0,8,240,35,32,2,136,5,
    244,5,8,41,32,216,132,195,26,100,63,131,160,6,47,0,
    250,6,72,3,78,112,98,194,239,13,72,86,249,29,27,34,
    147,41,2,102,13,144,22,244,107,240,56,217,0,75,218,112,
    216,128,236,107,16,66,36,2,158,4,75,16,44,195,11,148,
    142,147,58,11,92,134,160,193,147,58,4,43,60,105,192,172,
    5,114,5,250,40,124,9,250,77,20,245,14,138,90,99,81,
    255,36,81,1,62,217,130,160,73,236,168,203,83,226,180,136,
    147,215,88,99,41,235,165,102,45,232,183,202,249,6,244,55,
    32,88,7,185,1,227,107,48,64,243,90,149,140,77,144,38,
    140,183,160,191,5,18,63,155,112,130,30,8,54,152,119,155,
    121,175,85,188,59,204,187,11,253,93,144,248,217,209,188,54,
    244,58,219,232,207,240,95,248,215,65,127,130,90,197,225,153,
    204,242,48,77,220,48,25,164,161,65,207,109,26,200,251,62,
    13,75,69,24,126,77,97,248,7,112,12,2,163,8,195,49,
    160,96,65,250,71,6,28,243,228,216,128,89,7,142,4,140,
    45,8,76,56,194,101,106,164,192,80,192,137,1,95,153,196,
    112,140,163,133,142,251,33,88,74,199,96,204,142,211,146,150,
    224,184,6,71,53,232,61,57,50,136,112,88,135,236,239,240,
    167,235,44,116,153,133,26,112,132,163,5,39,22,28,219,240,
    24,153,144,52,174,147,249,226,201,17,90,138,148,94,199,66,
    109,247,231,204,37,83,130,48,75,188,88,170,77,156,187,19,
    47,243,98,215,153,30,204,30,101,233,32,140,100,214,105,148,
    140,105,126,107,226,169,145,195,111,154,228,146,120,162,88,98,
    154,72,181,130,147,65,152,4,110,156,6,211,72,170,101,18,
    231,146,8,215,229,135,159,198,147,52,83,191,205,178,52,115,
    200,171,76,140,82,175,122,131,124,234,71,105,46,59,180,26,
    47,227,144,120,69,220,131,9,75,36,5,88,91,122,57,144,
    185,159,133,19,133,193,210,18,137,155,164,117,40,76,60,228,
    95,227,208,77,6,121,119,58,236,142,210,88,230,239,222,238,
    198,221,56,29,121,241,123,119,239,117,165,47,239,222,189,211,
    253,220,59,184,215,29,202,248,110,247,96,26,70,65,247,225,
    231,143,62,121,216,157,204,212,40,77,186,72,13,19,37,209,
    75,81,247,188,127,110,33,215,53,90,233,121,56,116,67,182,
    209,29,201,104,34,51,82,49,127,157,180,16,45,177,42,108,
    97,138,142,104,226,172,134,95,83,92,55,86,196,126,72,86,
    250,100,57,97,204,44,81,245,55,224,248,97,248,15,13,200,
    174,19,102,198,248,17,20,100,68,78,143,158,25,252,236,119,
    228,30,77,29,155,132,4,77,60,98,156,33,224,144,243,62,
    133,62,1,6,75,13,198,54,104,16,33,246,52,170,178,25,
    141,200,78,98,12,20,110,65,254,253,89,9,73,11,208,253,
    152,179,72,218,193,165,190,101,92,246,58,164,248,62,131,67,
    141,194,60,125,158,112,8,104,206,153,212,67,159,60,154,125,
    113,48,150,190,202,111,32,225,105,58,109,251,94,146,164,170,
    237,5,65,219,83,42,11,15,166,74,230,109,149,182,111,230,
    157,58,197,124,163,196,87,37,111,54,41,241,68,177,71,60,
    233,31,65,232,43,252,193,192,117,217,255,185,84,136,141,81,
    26,228,72,39,17,67,169,28,82,82,173,225,240,176,92,142,
    65,216,177,75,200,228,50,26,168,6,163,207,203,115,151,151,
    35,58,3,141,222,126,230,69,83,169,136,63,87,158,194,85,
    105,170,23,90,52,212,94,35,99,75,91,201,127,110,146,38,
    193,12,85,13,253,183,72,139,215,24,112,171,64,144,219,70,
    184,45,225,104,67,19,225,215,50,124,178,202,42,192,198,64,
    219,33,31,0,7,95,20,69,4,65,119,130,165,166,99,112,
    173,96,243,56,21,219,52,163,151,29,194,180,243,6,13,215,
    105,248,65,233,129,5,186,161,249,178,27,110,211,210,6,219,
    238,155,133,149,85,58,237,159,73,167,189,211,116,194,234,216,
    163,180,48,40,121,78,211,194,36,63,100,15,138,28,160,132,
    67,24,224,227,57,228,179,119,156,22,89,109,151,160,117,8,
    137,243,112,28,206,193,209,161,192,48,22,157,189,87,121,242,
    198,149,122,114,168,61,249,30,45,189,90,160,168,201,232,105,
    8,159,32,96,20,126,101,159,254,6,39,179,93,242,233,188,
    55,119,113,203,123,156,52,121,239,226,253,143,119,120,93,74,
    180,147,245,196,34,188,13,76,216,41,246,164,156,50,127,146,
    165,223,204,218,233,160,173,160,212,225,254,205,252,214,205,252,
    87,88,27,218,15,184,218,232,234,160,243,63,147,147,12,243,
    188,206,63,116,238,186,156,199,110,177,165,160,215,105,127,231,
    96,177,175,185,84,229,42,163,10,181,104,71,55,42,71,147,
    222,191,160,117,27,236,101,19,118,241,219,16,172,156,155,114,
    181,228,70,131,159,226,247,67,242,55,153,44,129,218,60,167,
    167,85,103,171,200,62,231,237,51,184,89,156,77,206,59,164,
    93,153,121,54,84,40,161,175,73,90,83,50,252,25,184,27,
    19,240,29,16,34,48,240,69,250,112,162,210,151,2,187,73,
    236,127,0,46,68,23,236,123,134,78,67,163,40,85,152,165,
    249,251,204,170,183,193,207,224,47,115,85,236,196,4,65,91,
    150,89,244,91,243,91,150,85,37,46,67,233,82,219,146,117,
    54,195,41,78,35,47,39,54,157,203,102,149,203,167,5,177,
    234,146,176,64,45,16,101,203,122,69,151,148,251,248,20,99,
    180,31,188,33,54,141,57,228,252,132,134,119,43,208,136,146,
    182,24,61,111,192,171,247,49,87,23,205,143,72,25,139,213,
    95,183,217,176,82,64,149,29,181,50,59,238,84,217,33,185,
    138,191,224,174,156,70,131,48,112,98,8,60,238,96,255,66,
    39,13,11,100,13,250,54,229,17,183,156,162,72,51,81,150,
    54,42,137,103,182,8,118,206,190,118,91,5,3,29,97,26,
    190,89,116,41,33,95,220,143,188,248,32,240,30,244,104,85,
    90,218,47,19,207,40,237,104,205,219,65,73,35,94,101,10,
    255,188,93,218,243,108,209,101,228,167,184,72,101,7,39,77,
    144,250,92,59,190,28,201,118,44,227,3,60,146,141,194,73,
    123,16,121,67,142,151,89,216,249,69,105,167,226,128,191,188,
    65,115,127,179,159,182,253,52,193,170,63,245,85,154,181,3,
    137,199,20,25,104,192,159,77,95,238,250,188,108,152,115,131,
    119,248,156,166,87,17,91,23,207,158,33,182,182,95,150,62,
    209,39,162,170,214,115,55,171,179,7,247,76,60,106,168,153,
    174,104,247,104,248,49,13,55,225,138,182,132,46,173,78,171,
    145,11,109,44,58,117,193,231,163,121,190,71,244,102,126,62,
    139,255,122,153,44,214,215,21,69,46,219,196,41,151,232,20,
    76,99,157,54,134,126,163,36,174,240,184,202,196,102,73,92,
    227,113,157,137,173,146,184,193,227,53,38,110,150,119,39,91,
    76,220,134,254,14,93,70,16,101,151,138,198,210,255,90,52,
    56,211,174,34,199,250,255,215,90,225,220,185,106,51,28,238,
    85,255,83,157,16,243,54,54,117,157,24,139,178,171,159,55,
    144,47,16,246,46,4,170,235,103,210,83,82,199,238,245,197,
    27,205,213,72,235,240,85,21,193,210,178,234,144,243,126,101,
    221,9,247,89,179,173,185,174,155,3,42,30,99,83,132,157,
    249,17,59,192,53,116,115,126,10,85,171,242,3,149,205,68,
    62,119,207,251,66,247,223,164,144,55,153,200,36,56,237,173,
    249,201,162,225,64,5,207,131,211,54,7,27,233,45,252,158,
    79,79,178,109,206,84,14,101,173,74,200,43,8,42,35,121,
    80,134,179,195,167,195,170,192,59,20,76,93,210,171,106,238,
    252,178,10,79,231,98,152,38,211,216,77,7,216,80,253,113,
    42,19,31,83,129,142,116,151,103,198,70,76,81,12,207,61,
    81,63,186,88,68,134,36,55,159,229,74,198,188,210,37,216,
    104,13,186,23,155,163,169,246,197,175,141,82,229,70,184,83,
    107,43,254,43,19,73,166,147,96,69,81,111,95,252,138,23,
    69,184,189,234,118,32,196,190,128,197,95,150,151,86,161,176,
    188,252,128,129,200,229,35,144,145,84,242,130,204,225,247,138,
    139,129,0,213,203,210,25,30,87,249,204,135,191,35,215,189,
    146,237,250,231,184,200,83,90,109,11,244,118,109,227,134,189,
    93,252,215,173,186,224,238,232,165,107,240,78,5,89,125,194,
    153,229,14,151,227,245,10,161,124,87,91,182,38,92,153,40,
    54,251,94,172,239,222,248,50,201,121,147,134,183,74,144,115,
    81,209,167,95,62,87,234,115,61,86,33,62,217,115,167,230,
    220,34,58,249,241,212,152,158,6,209,122,69,236,133,177,190,
    113,100,1,213,47,110,76,20,101,88,105,62,135,34,147,195,
    16,5,100,44,160,98,46,106,29,57,135,79,42,23,64,99,
    254,229,171,136,156,62,4,232,123,142,7,100,105,78,245,129,
    110,253,234,235,117,97,27,116,197,108,138,134,104,10,75,172,
    54,235,102,221,174,215,76,140,46,81,54,69,195,172,55,86,
    145,119,15,35,220,48,246,214,234,226,223,186,68,247,36,
};

EmbeddedPython embedded_m5_internal_param_RubyProfiler(
    "m5/internal/param_RubyProfiler.py",
    "/nfs/ug/homes-0/m/moham356/ece552/Lab6/gem5/build/ALPHA/python/m5/internal/param_RubyProfiler.py",
    "m5.internal.param_RubyProfiler",
    data_m5_internal_param_RubyProfiler,
    2159,
    6754);

} // anonymous namespace
