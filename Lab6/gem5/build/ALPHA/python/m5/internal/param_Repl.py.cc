#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_Repl[] = {
    120,156,197,88,109,111,219,214,21,62,151,164,104,75,182,98,
    37,78,236,166,205,22,21,69,48,173,88,163,44,93,210,13,
    11,130,165,235,186,23,20,110,74,13,136,163,14,99,105,241,
    74,162,44,145,2,73,39,213,96,127,153,131,109,223,250,35,
    138,126,216,255,216,255,218,206,115,46,73,201,233,11,10,116,
    85,5,241,226,242,242,240,220,243,242,156,151,203,1,21,191,
    26,95,191,105,19,101,247,21,81,200,127,69,83,162,153,162,
    190,34,165,21,133,187,116,92,163,244,23,20,214,232,5,81,
    223,34,109,209,57,79,108,250,216,162,120,91,222,113,105,106,
    203,138,162,69,131,180,67,253,26,61,137,47,147,163,93,58,
    110,80,250,9,41,165,98,69,135,225,6,133,155,244,130,185,
    243,164,46,12,55,41,108,200,164,78,225,150,76,26,180,104,
    145,222,162,62,51,223,160,126,147,89,189,201,172,46,9,171,
    255,128,85,200,79,174,82,216,4,57,203,242,20,148,14,40,
    101,143,75,194,101,167,148,172,69,253,22,133,59,164,91,52,
    185,76,67,86,169,85,189,119,133,180,77,147,93,234,239,146,
    230,255,21,58,103,173,195,203,66,123,85,104,175,84,180,215,
    132,118,143,250,123,164,249,127,205,208,186,212,235,92,99,27,
    70,255,229,95,135,109,72,249,54,15,207,116,154,69,73,236,
    71,241,48,137,44,60,119,49,192,226,3,12,27,133,233,127,
    11,211,255,155,196,238,161,85,152,254,140,152,177,130,252,83,
    139,206,100,114,102,209,162,67,167,138,38,14,133,54,157,242,
    54,53,8,48,82,116,110,209,95,108,16,156,241,232,176,177,
    126,76,78,110,236,62,17,99,25,78,27,116,86,163,211,26,
    245,14,79,45,44,28,215,41,253,130,254,118,67,152,110,10,
    83,139,78,121,116,232,220,161,51,151,158,48,17,47,77,234,
    80,95,29,158,178,166,188,210,235,56,44,237,193,138,186,80,
    37,140,210,56,152,233,124,139,231,254,60,72,131,153,239,233,
    249,180,211,40,9,146,236,246,60,200,199,158,188,97,195,20,
    179,121,46,156,146,216,188,54,140,226,208,159,37,225,201,84,
    231,155,96,227,15,163,169,246,125,121,248,199,217,60,73,243,
    223,165,105,146,122,176,166,44,78,147,160,122,3,182,28,76,
    147,76,119,176,155,108,227,129,125,14,234,225,92,56,66,128,
    74,202,80,103,131,52,154,231,236,36,195,17,212,224,214,129,
    123,100,200,14,121,232,198,195,172,123,50,234,142,147,153,206,
    222,186,211,157,117,103,201,56,152,189,125,239,126,87,15,244,
    189,123,119,187,31,4,71,247,187,35,61,187,215,61,58,137,
    166,97,247,209,7,143,255,240,168,59,95,228,227,36,238,242,
    106,20,231,154,173,51,237,46,237,114,155,159,94,193,14,207,
    163,145,31,137,110,254,88,79,231,58,133,104,217,171,216,93,
    181,212,182,114,149,173,58,170,201,179,26,95,182,186,97,109,
    169,131,8,218,13,160,49,48,101,151,40,250,156,196,95,236,
    238,99,139,210,27,192,200,132,255,10,78,101,164,244,240,204,
    146,103,31,193,44,102,117,98,195,243,102,241,84,112,197,0,
    99,202,7,112,117,76,2,142,26,77,92,50,160,97,172,25,
    20,165,11,140,76,14,54,22,51,119,40,251,236,34,135,184,
    69,108,118,142,75,94,218,227,173,254,46,56,236,117,32,248,
    129,128,34,31,71,89,242,60,22,211,99,46,145,211,99,155,
    60,94,124,120,52,209,131,60,187,201,11,79,147,147,246,32,
    136,227,36,111,7,97,216,14,242,60,141,142,78,114,157,181,
    243,164,125,43,235,212,225,235,203,37,174,42,126,139,121,137,
    35,248,156,113,100,110,194,104,144,243,205,174,220,136,253,51,
    157,51,38,198,73,152,241,58,88,140,116,238,65,200,252,18,
    15,143,202,237,4,124,29,183,132,74,166,167,195,188,33,168,
    11,178,204,151,237,176,46,0,195,219,207,130,233,137,206,65,
    159,229,65,206,187,98,106,54,90,23,196,94,129,146,165,142,
    176,155,31,39,113,184,96,17,163,193,27,216,253,21,1,218,
    54,1,106,215,24,102,27,60,186,212,100,216,181,172,1,180,
    113,10,144,9,192,246,160,59,137,211,85,145,44,24,108,231,
    156,82,58,150,228,4,81,75,66,175,141,25,94,246,128,101,
    239,53,12,55,48,252,168,212,124,13,234,55,95,86,255,14,
    182,180,68,231,129,93,104,87,133,207,193,133,240,185,190,12,
    31,206,126,61,132,129,133,96,89,134,129,13,253,211,135,5,
    230,17,96,236,118,126,188,130,116,177,138,215,130,182,110,9,
    82,15,200,91,133,223,104,5,126,30,28,34,216,243,174,127,
    157,5,111,254,32,22,28,25,11,190,141,45,183,11,212,52,
    5,45,13,53,128,203,173,194,158,98,203,247,120,178,216,135,
    45,87,173,184,207,165,236,73,220,148,154,36,117,77,170,181,
    73,25,198,184,102,226,0,95,67,155,246,138,90,147,33,194,
    231,105,242,233,162,157,12,219,57,149,50,60,184,149,221,190,
    149,253,154,115,64,251,161,100,21,147,5,76,156,167,122,158,
    114,60,215,229,198,196,168,47,241,234,23,37,131,173,141,186,
    45,78,18,27,75,74,202,242,20,153,104,93,6,110,84,6,
    134,188,191,194,126,13,177,174,77,251,124,53,148,8,229,39,
    146,13,165,113,144,167,124,189,11,59,67,85,77,104,213,188,
    158,17,89,180,129,94,222,79,46,224,228,251,215,197,123,19,
    82,149,17,230,82,133,10,92,54,164,5,232,255,73,210,85,
    41,250,7,1,1,236,232,34,76,36,32,113,193,145,187,32,
    255,43,73,162,249,138,122,102,153,112,179,138,84,196,209,152,
    189,35,164,166,188,253,137,254,181,146,165,206,109,82,40,69,
    118,209,55,173,150,34,167,10,80,129,206,183,42,55,206,197,
    72,134,127,198,65,6,50,19,179,118,21,179,203,132,87,117,
    61,156,136,214,128,170,77,179,147,15,161,126,191,196,20,242,
    252,107,106,215,90,65,202,207,48,188,85,129,68,149,107,223,
    175,124,55,95,78,204,43,117,201,55,201,240,125,8,225,136,
    216,59,174,20,86,188,92,69,64,173,140,128,187,85,4,104,
    201,204,47,164,147,198,104,193,223,231,150,226,99,9,247,32,
    56,17,56,164,107,212,119,17,43,210,46,170,34,148,84,153,
    182,144,238,46,164,125,49,200,129,49,85,229,114,227,77,12,
    159,174,43,77,192,161,15,166,193,236,40,12,30,122,216,13,
    91,14,202,224,178,74,249,91,171,242,35,48,212,215,169,32,
    183,119,74,61,158,173,43,69,252,28,219,150,242,75,64,132,
    201,64,242,194,159,199,186,61,211,179,35,62,54,141,163,121,
    123,56,13,70,226,31,187,208,239,195,82,191,92,28,252,114,
    145,149,222,228,32,105,15,146,152,51,248,201,32,79,210,118,
    168,249,72,161,67,3,234,139,161,41,128,10,210,81,38,77,
    217,241,115,76,215,233,75,159,207,133,17,183,161,189,210,22,
    230,212,82,229,109,233,60,77,132,112,221,227,99,65,190,48,
    89,234,62,134,159,98,184,69,107,78,239,93,102,254,17,118,
    129,201,92,78,36,117,37,229,11,207,31,131,50,251,114,116,
    190,247,109,162,211,124,46,40,98,212,37,189,129,227,40,190,
    6,212,138,175,1,28,175,238,119,141,87,1,251,58,97,254,
    244,255,26,166,222,221,31,74,124,79,90,190,111,10,81,139,
    86,186,232,119,76,136,26,127,112,129,95,92,93,105,239,68,
    85,245,132,171,49,183,128,167,210,28,250,150,233,2,151,206,
    147,92,111,149,65,16,235,231,254,18,97,166,193,3,24,130,
    249,92,199,225,178,121,147,39,235,50,16,162,240,99,90,214,
    85,238,212,174,242,245,101,128,66,151,21,213,4,136,181,10,
    146,175,174,217,167,159,84,217,102,235,66,182,241,224,52,147,
    95,170,212,98,50,141,184,1,150,13,245,84,231,122,197,19,
    57,200,139,19,76,168,57,231,38,11,238,175,165,89,229,251,
    169,239,175,53,55,253,146,153,31,150,14,65,110,114,85,221,
    169,43,73,248,47,125,125,51,34,237,83,217,144,45,50,79,
    96,190,83,233,43,159,138,202,172,43,120,198,33,226,128,207,
    245,230,251,83,27,148,175,99,120,163,52,153,64,210,52,233,
    210,6,155,99,7,99,87,14,30,82,124,188,219,88,199,46,
    70,244,94,52,51,223,56,132,182,186,147,52,43,38,135,110,
    98,223,84,143,162,140,213,150,151,43,194,34,32,160,121,190,
    79,171,105,248,194,75,235,116,131,105,83,204,233,234,33,180,
    202,32,29,190,45,212,119,234,202,181,240,1,203,86,13,213,
    84,142,218,110,214,237,186,91,175,217,236,42,172,236,170,134,
    93,111,108,171,235,236,182,134,117,189,94,87,255,3,141,110,
    195,193,
};

EmbeddedPython embedded_m5_internal_param_Repl(
    "m5/internal/param_Repl.py",
    "/nfs/ug/homes-0/m/moham356/ece552/Lab6/gem5/build/ALPHA/python/m5/internal/param_Repl.py",
    "m5.internal.param_Repl",
    data_m5_internal_param_Repl,
    1954,
    5794);

} // anonymous namespace
