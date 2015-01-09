#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_NetworkTest[] = {
    120,156,197,89,109,115,219,198,17,222,3,72,202,164,69,235,
    93,150,44,197,102,226,186,97,220,196,116,157,216,233,139,199,
    83,247,189,157,68,113,161,204,200,102,59,69,33,224,72,130,
    34,1,14,112,178,205,140,212,15,149,167,237,183,254,136,78,
    63,244,127,244,127,181,187,123,56,16,122,181,59,237,80,18,
    113,115,92,236,237,221,238,62,187,183,119,244,33,251,43,227,
    243,163,6,64,250,71,1,16,224,71,192,0,96,40,160,45,
    64,72,1,193,18,236,149,33,249,12,130,50,188,1,104,91,
    32,45,56,194,142,13,191,181,32,154,229,49,21,24,216,76,
    17,48,174,129,44,65,187,12,59,209,2,148,100,5,246,106,
    144,252,1,132,16,145,128,231,193,12,4,87,224,13,74,199,
    78,149,5,94,129,160,198,157,42,4,87,185,83,131,241,60,
    200,171,208,70,225,51,208,174,163,168,187,40,234,26,139,250,
    23,137,10,240,205,50,4,117,98,199,181,188,32,206,18,113,
    242,28,215,88,202,156,89,217,60,180,231,77,127,1,218,11,
    166,191,8,237,69,211,95,130,246,146,233,47,67,123,217,244,
    87,160,189,98,250,171,208,94,133,96,14,228,10,244,175,67,
    7,77,51,159,207,191,6,210,134,254,58,180,215,65,226,103,
    13,142,208,122,193,2,243,222,96,222,197,156,119,131,121,55,
    161,189,9,18,63,27,154,183,2,219,205,21,244,69,248,111,
    252,107,162,47,64,205,98,243,82,38,105,24,71,110,24,117,
    226,208,162,247,21,106,200,115,62,53,51,153,11,127,66,46,
    252,39,176,255,2,43,115,225,33,160,96,65,235,31,88,112,
    200,157,67,11,198,77,56,16,208,47,65,96,195,1,78,83,
    166,5,116,5,28,89,240,59,155,24,14,177,45,161,209,111,
    66,73,105,255,245,217,232,90,210,12,28,150,225,160,12,219,
    207,15,44,34,236,85,33,249,7,124,179,201,66,175,176,80,
    11,14,176,45,193,81,9,14,43,176,131,76,72,234,87,73,
    125,241,252,0,53,69,202,118,179,132,171,221,42,168,75,170,
    4,97,18,121,67,169,22,177,239,142,188,196,27,186,91,82,
    189,138,147,189,175,101,170,154,53,195,23,167,247,70,158,234,
    57,60,208,38,139,12,71,138,5,198,145,84,87,177,211,9,
    163,192,29,198,193,254,64,170,43,36,205,237,132,3,233,186,
    252,242,87,195,81,156,168,159,37,73,156,56,100,84,38,14,
    98,47,31,65,38,245,7,113,42,155,52,27,79,227,144,120,
    69,220,157,17,75,164,5,240,98,105,112,32,83,63,9,71,
    10,125,165,37,18,55,73,107,146,151,184,73,93,108,90,81,
    39,109,237,119,91,189,120,40,211,79,238,183,134,173,97,220,
    243,134,159,62,124,212,146,190,124,248,240,65,235,11,111,247,
    81,171,43,135,15,91,187,251,225,32,104,61,253,226,217,47,
    159,182,70,99,213,139,163,22,82,195,72,73,52,210,160,117,
    202,60,247,144,137,12,151,190,10,187,110,200,42,186,61,57,
    24,201,132,86,152,222,160,69,136,121,49,43,42,194,22,77,
    81,199,94,25,31,91,108,90,87,197,86,72,74,250,164,56,
    33,204,54,152,250,59,176,247,208,249,123,22,36,155,132,152,
    62,126,4,185,24,113,179,77,239,44,126,247,27,178,142,166,
    246,109,194,129,38,30,48,202,16,110,200,249,152,28,31,1,
    67,165,12,253,10,104,8,33,242,52,166,146,49,181,200,78,
    98,44,20,94,130,244,111,199,37,68,243,128,214,199,104,71,
    210,42,78,245,39,70,229,118,147,22,190,197,216,80,189,48,
    141,95,69,236,1,234,115,28,109,163,77,158,141,191,218,237,
    75,95,165,183,144,240,34,222,111,248,94,20,197,170,225,5,
    65,195,83,42,9,119,247,149,76,27,42,110,220,73,155,85,
    114,249,130,129,87,46,111,60,50,112,34,215,35,156,244,151,
    32,244,21,126,89,226,47,108,255,84,42,132,70,47,14,82,
    164,147,136,174,84,14,45,82,93,195,230,169,153,142,49,216,
    172,24,196,164,114,208,81,53,6,159,151,166,46,79,71,116,
    198,25,141,126,233,13,246,165,34,254,84,121,10,103,165,174,
    158,104,202,72,91,35,93,141,170,100,62,55,138,163,96,140,
    43,13,253,219,180,136,53,198,219,44,16,226,86,16,109,51,
    216,86,160,142,232,155,183,124,82,170,148,97,141,113,182,74,
    38,0,246,189,200,50,8,98,238,8,243,76,211,226,68,193,
    218,113,32,54,168,71,131,29,130,180,179,65,205,38,53,239,
    25,3,76,207,10,245,147,86,184,79,51,91,172,186,111,103,
    74,230,193,180,117,44,152,214,39,193,132,153,113,155,130,194,
    162,208,153,4,133,77,102,72,158,100,17,64,225,134,32,192,
    215,5,220,179,113,156,121,82,186,98,32,235,16,14,139,96,
    236,22,192,232,144,95,24,137,206,250,121,134,188,117,153,134,
    236,106,67,126,74,51,207,102,24,170,51,118,106,194,39,0,
    88,153,89,217,164,63,197,206,248,58,153,180,104,204,235,184,
    219,237,68,117,222,182,120,235,227,194,64,231,17,109,99,221,
    41,17,218,58,54,172,102,219,81,74,97,63,74,226,215,227,
    70,220,105,40,48,107,120,124,39,189,119,39,253,33,38,134,
    198,19,78,53,58,53,232,224,79,228,40,193,32,175,242,23,
    29,184,46,7,177,155,109,39,104,116,218,218,217,87,108,106,
    206,83,169,74,40,61,77,217,206,181,220,206,180,236,239,211,
    180,53,54,178,13,215,241,169,9,94,155,27,115,166,228,18,
    131,223,226,243,99,50,55,105,44,129,138,67,103,91,175,156,
    149,34,245,156,15,143,161,102,106,42,57,119,105,113,38,236,
    42,144,99,132,30,155,22,77,145,240,23,224,50,76,192,159,
    129,240,128,110,207,98,135,163,148,30,114,235,18,177,255,30,
    56,9,157,177,229,89,58,6,173,44,77,97,136,166,159,51,
    171,222,1,127,13,127,45,100,176,35,27,4,237,86,118,86,
    104,21,119,171,82,30,181,12,164,119,218,145,74,199,195,155,
    220,212,243,82,98,211,129,108,231,129,60,73,134,121,125,132,
    217,105,122,24,187,162,39,116,105,109,191,152,32,140,182,130,
    13,177,100,21,112,243,49,53,159,228,144,17,134,54,149,101,
    222,58,153,187,11,59,152,171,243,229,207,105,45,37,94,253,
    92,133,11,189,130,140,60,58,202,38,58,30,228,209,33,57,
    135,191,225,122,156,90,139,64,112,100,9,60,36,97,237,66,
    231,147,18,200,50,180,43,20,71,92,109,138,44,204,132,201,
    108,148,17,143,109,16,108,158,45,109,184,28,7,218,197,212,
    188,158,114,38,33,47,63,30,120,195,221,192,123,242,156,38,
    165,153,125,19,120,150,81,99,190,168,6,5,141,56,79,19,
    254,122,223,168,243,114,202,89,228,187,56,71,174,6,199,76,
    16,251,156,58,190,238,201,198,80,14,119,241,40,214,11,71,
    141,206,192,235,178,183,236,76,205,175,140,154,138,221,125,114,
    115,230,210,102,43,110,248,113,132,41,127,223,87,113,210,8,
    36,158,79,100,160,1,127,60,122,185,222,243,146,110,202,165,
    221,222,43,234,94,130,103,93,60,114,134,88,211,190,48,38,
    209,39,161,60,209,115,25,171,163,7,247,75,60,99,168,177,
    206,103,143,168,249,136,154,59,112,57,251,65,11,231,216,161,
    201,200,128,21,76,57,85,161,22,142,135,238,51,26,151,158,
    14,224,207,196,59,4,176,190,223,200,194,184,66,156,114,134,
    142,190,212,86,105,83,104,215,12,241,42,183,179,76,172,27,
    226,53,110,231,152,56,111,136,11,220,46,50,113,201,16,151,
    185,93,97,226,170,33,94,231,118,141,137,235,134,120,131,219,
    13,38,110,26,226,123,220,222,100,226,45,67,108,112,251,62,
    19,63,48,196,219,220,126,139,137,119,12,241,219,220,126,200,
    196,166,185,255,249,136,137,119,161,253,29,186,20,33,202,199,
    148,194,102,254,215,20,198,129,127,9,33,239,254,95,51,151,
    243,224,146,181,112,184,108,190,40,107,137,162,138,117,157,181,
    250,194,156,47,138,250,241,61,198,218,89,129,227,250,137,244,
    148,212,142,187,49,117,149,57,51,234,37,120,185,251,140,94,
    249,97,235,243,92,183,35,46,249,198,203,133,242,159,189,41,
    118,176,62,195,35,194,1,171,239,90,250,148,48,129,105,41,
    183,2,165,189,72,190,114,79,89,66,159,3,104,61,222,104,
    36,163,96,82,227,243,155,41,67,129,114,239,16,38,5,23,
    22,244,203,248,156,14,76,210,172,160,40,251,177,156,135,226,
    244,61,202,32,78,140,47,155,84,17,78,182,26,135,60,169,
    55,151,124,95,113,126,144,251,166,113,38,66,59,225,107,25,
    184,163,61,149,210,129,242,237,76,88,2,242,217,104,66,82,
    31,156,57,102,119,16,251,123,110,220,233,80,133,75,162,223,
    129,141,132,211,49,178,72,60,103,92,180,63,196,218,115,24,
    39,161,76,47,16,127,140,205,136,47,18,185,186,61,61,110,
    148,72,63,228,27,101,146,253,54,30,18,172,79,196,25,69,
    109,158,57,34,29,167,74,14,89,228,133,12,36,143,239,174,
    248,171,122,255,76,94,214,96,236,166,225,55,146,37,190,157,
    139,196,82,109,94,160,157,55,202,123,237,142,60,127,79,102,
    176,120,59,87,46,123,66,59,199,37,42,241,58,29,60,57,
    208,165,221,5,158,59,198,102,60,87,36,158,131,213,52,28,
    186,254,216,31,200,139,0,93,96,50,128,158,144,212,205,51,
    199,132,81,223,77,48,149,178,216,183,176,144,80,170,14,13,
    65,221,63,27,65,116,245,140,39,87,229,98,209,27,73,159,
    174,197,177,187,31,233,136,249,175,7,209,180,148,148,206,103,
    225,212,199,155,85,32,7,18,87,122,74,190,162,4,146,221,
    135,5,72,77,226,177,235,234,203,14,252,62,112,221,203,40,
    85,191,135,115,208,117,67,74,88,161,82,181,130,197,234,202,
    153,255,213,82,85,240,41,225,196,207,64,122,197,116,218,215,
    7,253,113,234,16,197,153,203,19,36,255,88,97,106,116,222,
    21,41,166,183,188,161,190,125,230,251,84,135,34,193,185,109,
    114,44,71,169,190,3,226,235,21,125,185,133,59,32,95,111,
    241,137,197,185,7,217,111,84,90,179,109,29,211,52,173,164,
    68,244,37,7,227,151,113,32,121,247,124,186,139,38,247,124,
    165,201,238,75,73,231,32,181,156,15,63,254,158,239,186,19,
    47,66,180,204,229,44,248,74,95,224,23,104,219,161,161,209,
    10,115,14,62,3,156,172,93,216,247,137,236,134,184,208,132,
    101,228,252,217,102,78,238,56,39,4,138,99,47,1,41,250,
    180,173,175,19,159,144,170,124,241,73,87,235,213,185,170,168,
    88,244,51,142,45,106,162,46,74,98,182,94,181,171,149,106,
    217,70,52,17,101,73,212,236,106,109,86,20,255,215,17,77,
    53,107,125,165,42,254,3,6,194,20,124,
};

EmbeddedPython embedded_m5_internal_param_NetworkTest(
    "m5/internal/param_NetworkTest.py",
    "/nfs/ug/homes-0/m/moham356/ece552/Lab6/gem5/build/ALPHA/python/m5/internal/param_NetworkTest.py",
    "m5.internal.param_NetworkTest",
    data_m5_internal_param_NetworkTest,
    2427,
    7690);

} // anonymous namespace