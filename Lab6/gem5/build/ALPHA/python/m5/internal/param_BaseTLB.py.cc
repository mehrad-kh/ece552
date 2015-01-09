#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_BaseTLB[] = {
    120,156,197,88,109,143,219,198,17,158,37,41,222,73,119,242,
    201,190,243,57,118,220,90,65,96,84,13,26,203,117,106,167,
    69,13,163,118,211,87,24,23,135,10,96,91,41,202,240,196,
    149,68,157,68,10,36,207,142,138,187,47,61,163,237,183,254,
    136,162,31,250,63,250,191,218,121,102,73,158,116,105,130,0,
    109,21,65,92,44,151,203,217,153,103,158,153,157,229,128,138,
    95,141,175,159,181,137,178,7,138,40,228,191,162,41,209,76,
    81,95,145,210,138,194,93,58,170,81,250,35,10,107,244,134,
    168,111,145,182,232,140,59,54,125,102,81,188,45,239,184,52,
    181,101,68,209,162,65,218,161,126,141,158,199,151,201,209,46,
    29,53,40,253,156,148,82,177,162,23,225,6,133,155,244,134,
    165,115,167,46,2,55,41,108,72,167,78,225,150,116,26,180,
    104,145,222,162,62,11,223,160,126,147,69,189,199,162,46,137,
    168,127,66,84,200,79,246,40,108,98,58,235,242,18,51,29,
    204,148,53,46,137,148,157,82,179,22,245,91,20,238,144,110,
    209,228,50,13,217,164,86,245,222,21,210,54,77,118,169,191,
    75,154,255,87,232,140,173,14,47,203,220,61,153,123,165,154,
    123,85,230,238,83,127,159,52,255,175,154,185,46,245,58,87,
    25,195,232,95,252,235,48,134,148,111,115,243,74,167,89,148,
    196,126,20,15,147,200,194,115,23,13,16,31,160,217,40,160,
    255,57,160,255,7,9,238,161,85,64,127,74,44,88,65,255,
    169,69,167,210,57,181,104,209,161,19,69,19,135,66,155,78,
    120,153,26,20,24,41,58,179,232,119,54,38,156,114,235,48,
    88,223,37,39,55,184,79,4,44,35,105,131,78,107,116,82,
    163,222,139,19,11,3,71,117,74,255,78,127,184,41,66,55,
    69,168,69,39,220,58,116,230,208,169,75,207,121,18,15,77,
    234,48,95,189,56,97,75,121,164,215,113,88,219,131,37,115,
    97,74,24,165,113,48,211,249,37,238,251,243,32,13,102,254,
    147,32,211,159,62,125,210,105,148,115,146,236,206,60,200,199,
    158,188,100,3,141,217,60,23,97,73,172,243,45,238,12,163,
    56,244,103,73,120,60,213,249,38,36,249,195,104,170,125,95,
    30,254,102,54,79,210,252,23,105,154,164,30,0,149,193,105,
    18,84,111,0,206,193,52,201,116,7,171,201,50,30,196,231,
    152,61,156,139,68,40,32,138,226,229,80,103,131,52,154,231,
    236,39,35,17,179,33,173,3,15,73,147,125,198,77,55,30,
    102,221,227,81,119,156,204,116,246,254,221,238,172,59,75,198,
    193,236,131,251,15,186,122,160,239,223,191,215,125,26,28,62,
    232,142,244,236,126,247,240,56,154,134,221,199,79,159,253,250,
    113,119,190,200,199,73,220,229,209,40,206,53,3,52,237,174,
    64,115,135,39,92,193,34,175,163,145,31,137,121,254,88,79,
    231,58,133,118,217,13,40,160,90,106,91,185,202,86,29,213,
    228,94,141,47,91,221,180,182,212,65,4,3,7,48,26,204,
    178,75,46,253,141,196,107,236,244,35,139,210,155,96,202,132,
    255,10,174,101,190,244,240,204,146,103,159,0,25,51,58,177,
    225,127,51,120,34,236,98,154,241,204,135,112,120,76,66,145,
    26,77,92,50,212,97,198,25,46,165,11,180,60,29,98,44,
    22,238,80,246,215,85,9,113,139,24,121,142,78,30,218,231,
    165,254,40,108,236,117,160,248,129,240,34,31,71,89,242,58,
    22,244,209,151,248,233,49,38,207,22,31,31,78,244,32,207,
    110,241,192,203,228,184,61,8,226,56,201,219,65,24,182,131,
    60,79,163,195,227,92,103,237,60,105,223,206,58,117,184,251,
    114,73,173,74,222,98,94,82,9,110,103,42,153,155,48,26,
    228,124,179,43,55,130,127,166,115,166,197,56,9,51,30,135,
    136,145,206,61,40,41,156,126,92,46,39,252,235,184,37,91,
    50,61,29,230,13,33,94,144,101,190,44,135,113,225,24,222,
    126,21,76,143,117,142,249,89,30,228,188,42,186,102,161,53,
    178,236,45,216,89,154,9,232,252,56,137,195,5,107,25,13,
    222,133,2,111,9,215,182,9,108,187,202,76,219,224,214,165,
    38,51,175,101,13,96,144,83,240,76,56,182,15,243,73,252,
    174,138,172,193,124,59,227,220,210,177,36,57,136,101,18,128,
    109,244,240,178,7,58,123,111,163,185,137,230,59,165,241,235,
    65,160,121,17,129,187,88,213,18,179,7,118,97,96,21,68,
    7,43,65,116,253,60,136,56,19,246,16,12,22,66,230,60,
    24,108,64,144,62,42,152,143,48,99,231,243,227,37,190,11,
    48,94,11,6,187,37,85,61,240,111,153,132,163,37,18,122,
    240,137,48,208,187,254,85,32,222,250,182,64,28,25,16,63,
    192,170,219,5,119,154,194,153,134,26,192,241,86,1,169,192,
    249,17,119,22,215,0,231,50,144,215,120,103,123,30,55,101,
    139,146,109,78,54,111,147,59,12,190,166,227,128,101,67,155,
    246,139,173,39,67,168,207,211,228,139,69,59,25,182,115,42,
    117,120,120,59,187,115,59,251,41,39,131,246,35,73,47,38,
    29,152,128,79,245,60,229,192,174,203,141,9,86,95,2,215,
    47,182,15,6,28,219,184,248,73,96,150,220,148,229,41,82,
    210,26,49,110,84,24,67,229,159,96,201,134,0,108,211,53,
    190,26,74,244,242,19,201,140,82,74,200,83,190,158,0,106,
    88,171,9,197,155,215,51,90,139,65,48,205,251,222,10,91,
    214,98,142,247,30,20,43,67,205,165,138,27,184,108,40,12,
    246,255,153,164,212,82,244,39,2,15,216,221,69,188,72,100,
    226,130,59,119,49,253,247,36,73,231,63,108,111,150,137,59,
    171,72,75,28,150,217,135,50,213,236,118,191,165,191,44,101,
    172,51,155,20,118,38,187,40,166,150,119,38,167,138,84,33,
    208,55,218,125,156,213,144,134,139,198,65,134,105,38,120,237,
    42,120,207,147,95,85,7,113,70,90,15,183,54,205,98,62,
    244,250,213,57,179,144,246,223,86,187,214,18,95,126,128,230,
    253,138,42,170,28,251,191,171,120,235,98,158,94,218,169,124,
    147,27,127,9,61,28,209,124,199,21,168,139,247,171,104,168,
    149,209,112,175,138,6,45,185,250,141,212,217,104,45,56,254,
    204,82,124,104,225,218,4,231,5,135,116,141,250,46,226,70,
    42,73,85,132,149,42,179,24,178,223,202,70,32,176,28,24,
    192,42,223,27,183,162,249,98,141,89,3,158,125,56,13,102,
    135,97,240,200,195,130,88,117,80,6,154,85,154,208,90,54,
    1,65,162,190,202,10,185,189,91,154,242,106,141,25,227,135,
    88,185,52,65,226,35,76,6,146,38,62,29,235,246,76,207,
    14,249,104,53,142,230,237,225,52,24,137,151,236,194,196,143,
    75,19,115,113,243,197,205,87,202,150,131,164,61,72,98,78,
    235,199,131,60,73,219,161,230,51,135,14,13,193,87,35,85,
    234,184,32,29,101,82,178,29,189,70,119,205,30,245,249,248,
    24,113,157,218,43,225,48,39,155,42,153,155,227,150,68,11,
    239,135,124,110,200,23,38,111,61,64,243,125,52,183,105,253,
    57,191,203,242,63,193,66,0,206,229,212,82,87,82,58,20,
    83,158,97,126,246,229,96,253,232,155,4,171,249,182,80,132,
    172,75,122,3,103,87,124,58,168,21,159,14,56,124,221,255,
    54,124,133,248,107,166,252,203,255,105,212,122,247,190,69,11,
    60,41,11,191,46,98,45,90,42,182,63,52,17,107,188,194,
    219,255,98,111,169,4,20,107,213,115,222,171,185,76,60,145,
    2,210,183,76,165,120,238,66,217,125,229,4,15,40,98,253,
    218,95,161,154,169,3,193,138,96,62,215,113,120,94,227,201,
    147,53,194,132,184,196,26,229,198,203,5,221,30,95,95,38,
    43,44,90,50,80,72,89,171,232,121,99,253,206,253,188,74,
    65,91,43,41,200,131,247,76,210,169,242,141,73,63,226,143,
    61,216,161,167,58,215,171,46,201,241,70,113,232,9,53,167,
    227,100,193,245,184,84,182,124,63,245,253,117,231,172,31,179,
    252,23,165,103,144,179,92,85,119,234,74,182,131,11,223,239,
    140,86,215,168,172,222,22,153,39,172,223,169,172,150,47,77,
    101,66,22,122,227,220,113,16,204,204,231,3,57,20,123,239,
    160,121,183,4,78,232,105,138,122,169,153,205,73,133,169,44,
    103,21,217,154,188,59,24,199,42,70,251,94,52,51,223,71,
    100,110,117,39,233,87,128,47,204,19,148,83,61,138,50,54,
    94,222,175,230,22,241,1,227,243,27,116,33,67,175,188,183,
    102,127,152,130,198,156,204,30,193,188,12,58,226,235,68,125,
    167,174,92,11,95,193,108,213,80,77,229,168,237,102,221,174,
    187,245,154,205,62,195,200,174,106,216,245,198,182,186,206,254,
    107,88,215,235,117,245,111,48,46,215,198,
};

EmbeddedPython embedded_m5_internal_param_BaseTLB(
    "m5/internal/param_BaseTLB.py",
    "/nfs/ug/homes-0/m/moham356/ece552/Lab6/gem5/build/ALPHA/python/m5/internal/param_BaseTLB.py",
    "m5.internal.param_BaseTLB",
    data_m5_internal_param_BaseTLB,
    1963,
    5869);

} // anonymous namespace