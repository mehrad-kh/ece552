#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_BasePrefetcher[] = {
    120,156,197,89,239,114,27,73,17,239,217,149,100,75,182,98,
    249,191,29,59,23,133,16,16,7,23,133,28,201,65,145,74,
    145,227,239,81,119,190,32,81,229,68,80,44,235,221,145,180,
    178,180,43,118,198,201,233,202,230,3,78,1,223,120,8,234,
    62,240,30,60,14,239,112,215,221,163,89,75,142,149,11,5,
    101,199,218,169,217,222,158,158,233,238,95,247,244,76,2,24,
    255,203,227,243,147,42,128,250,179,0,8,241,39,160,15,48,
    16,208,18,32,164,128,112,21,14,243,144,254,0,194,60,188,
    2,104,57,32,29,56,197,142,11,191,115,32,94,228,49,5,
    232,187,76,17,48,42,129,204,65,43,15,251,241,50,228,100,
    1,14,75,144,254,17,132,16,177,128,103,225,28,132,243,240,
    10,165,99,167,200,2,231,33,44,113,167,8,225,2,119,74,
    48,170,128,92,128,22,10,159,131,86,25,69,189,139,162,174,
    177,168,127,147,168,16,191,172,65,88,38,118,92,203,115,226,
    204,17,39,207,113,141,165,44,217,149,85,160,85,177,253,101,
    104,45,219,254,10,180,86,108,127,21,90,171,182,191,6,173,
    53,219,95,135,214,186,237,111,64,107,3,194,37,144,27,208,
    219,132,54,154,166,146,205,191,5,210,133,222,54,180,182,65,
    226,111,11,78,209,122,225,50,243,94,103,222,149,140,119,135,
    121,119,161,181,11,18,127,59,134,183,0,205,218,58,250,34,
    250,18,255,213,208,23,160,23,177,121,33,83,21,37,177,23,
    197,237,36,114,232,123,129,26,242,92,64,205,220,216,133,63,
    37,23,254,11,216,127,161,51,118,225,9,160,96,65,235,239,
    59,112,194,157,19,7,70,53,56,22,208,203,65,232,194,49,
    78,147,167,5,116,4,156,58,240,123,151,24,78,176,205,161,
    209,223,129,156,54,254,235,177,209,141,164,57,56,201,195,113,
    30,154,207,142,29,34,28,22,33,253,2,62,223,101,161,243,
    44,212,129,99,108,115,112,154,131,147,2,236,35,19,146,122,
    69,82,95,60,59,70,77,145,210,172,229,112,181,123,19,234,
    146,42,97,148,198,254,64,106,178,132,55,244,83,127,224,125,
    232,43,249,52,149,109,169,131,174,76,107,37,203,154,168,187,
    67,95,119,27,60,214,37,163,12,134,154,101,38,177,212,11,
    216,105,71,113,232,13,146,240,168,47,245,60,9,244,218,81,
    95,122,30,127,252,104,48,76,82,253,243,52,77,210,6,217,
    149,137,253,196,207,70,144,85,131,126,162,100,141,102,227,105,
    26,36,94,19,119,123,200,18,105,1,188,94,26,28,74,21,
    164,209,80,163,187,140,68,226,38,105,53,114,20,55,234,0,
    155,122,220,86,245,163,78,189,155,12,164,122,239,94,125,80,
    31,36,93,127,240,254,131,135,117,25,200,7,15,238,215,63,
    246,15,30,214,59,114,240,160,126,112,20,245,195,250,147,143,
    159,254,234,73,125,56,210,221,36,174,35,53,138,181,68,59,
    245,235,23,89,232,46,242,173,208,92,47,163,142,23,177,150,
    94,87,246,135,50,165,69,170,235,180,14,81,17,139,162,32,
    92,81,19,101,236,229,241,113,197,174,179,32,246,34,210,51,
    32,221,9,103,174,69,214,63,129,125,136,16,56,116,32,221,
    37,220,244,240,39,200,209,136,158,38,125,115,248,219,111,200,
    64,134,218,115,9,13,134,120,204,88,67,208,33,231,35,114,
    127,12,12,152,60,244,10,96,128,132,248,51,200,74,71,212,
    34,59,137,113,80,120,14,212,63,166,37,196,21,64,7,96,
    204,35,105,3,167,250,11,99,179,89,163,133,239,49,60,116,
    55,82,201,203,152,157,64,125,142,166,38,218,228,233,232,211,
    131,158,12,180,186,137,132,231,201,81,53,240,227,56,209,85,
    63,12,171,190,214,105,116,112,164,165,170,234,164,122,71,213,
    138,228,245,101,139,176,76,222,104,104,17,69,222,71,68,153,
    151,48,10,52,190,172,242,11,219,95,73,141,232,232,38,161,
    66,58,137,232,72,221,160,69,234,107,216,60,177,211,49,12,
    107,5,11,26,37,251,109,93,98,252,249,74,121,60,29,209,
    25,106,52,250,133,223,63,146,154,248,149,246,53,206,74,93,
    51,209,229,131,109,139,212,181,218,146,5,189,56,137,195,17,
    46,54,10,110,211,58,182,24,114,139,64,160,91,71,192,205,
    97,91,128,50,2,176,226,4,164,87,110,12,55,134,218,6,
    89,1,216,253,98,156,74,16,118,167,152,112,106,14,103,12,
    86,144,195,177,74,61,26,220,32,84,55,118,168,217,165,230,
    134,181,193,165,26,162,124,222,16,247,104,114,135,181,15,220,
    177,158,89,72,237,77,133,212,246,89,72,97,150,108,82,104,
    56,20,64,103,161,225,146,37,210,199,227,56,160,160,67,40,
    224,231,9,244,179,125,26,21,210,187,96,129,219,32,52,78,
    66,178,51,1,201,6,185,134,241,216,216,158,101,203,155,87,
    108,203,142,177,229,251,52,249,226,24,73,101,70,80,73,4,
    4,3,103,108,89,182,234,207,176,51,218,36,171,78,218,115,
    19,55,191,253,184,204,187,24,239,132,92,39,152,132,98,204,
    108,58,57,194,92,219,133,141,241,238,164,40,254,135,105,242,
    217,168,154,180,171,26,236,26,30,221,81,119,239,168,31,99,
    134,168,62,230,156,99,114,132,201,2,169,28,166,24,237,69,
    126,49,17,236,113,52,123,227,173,5,237,78,251,27,187,139,
    173,205,9,75,233,148,242,212,229,155,186,148,153,154,86,254,
    35,154,185,196,118,118,97,19,159,146,224,229,121,9,103,77,
    46,58,248,43,62,31,146,197,73,105,9,84,46,54,154,102,
    241,172,23,105,216,248,246,20,118,46,83,171,198,187,180,62,
    27,127,5,200,144,66,143,75,235,166,144,248,27,112,109,38,
    224,175,64,168,64,231,143,131,136,195,149,30,114,238,42,177,
    255,1,56,33,93,176,3,58,38,24,157,113,202,194,88,85,
    31,48,171,217,16,127,13,127,159,200,102,167,46,8,218,188,
    220,113,245,53,185,121,229,178,240,101,56,189,213,6,149,155,
    142,115,242,84,215,87,196,102,34,218,205,34,250,44,49,102,
    21,19,166,169,75,69,218,188,153,211,163,229,253,242,12,103,
    180,51,236,136,85,103,2,61,223,163,230,189,12,56,194,210,
    46,107,165,55,207,167,242,137,61,205,51,233,243,23,180,156,
    28,43,176,84,224,237,124,90,76,22,41,121,27,41,247,179,
    72,145,156,213,95,113,181,78,173,67,104,56,117,4,30,161,
    176,166,161,211,75,14,100,30,90,5,138,41,46,68,197,56,
    228,132,77,116,148,32,167,182,12,54,210,158,49,95,6,8,
    227,107,106,62,187,252,196,66,238,126,212,247,7,7,161,255,
    248,25,205,75,147,7,54,8,29,171,73,101,82,19,10,32,
    49,75,25,126,189,103,53,122,113,249,73,229,251,56,77,166,
    9,135,80,152,4,156,73,126,219,149,213,129,28,28,224,113,
    173,27,13,171,237,190,223,97,159,185,99,77,63,181,154,106,
    118,250,249,77,155,171,158,189,164,26,36,49,238,3,71,129,
    78,210,106,40,241,0,35,67,3,254,233,96,230,106,208,79,
    59,138,11,191,195,151,212,189,26,255,122,120,50,141,176,232,
    125,110,173,98,78,75,89,246,231,192,48,145,132,251,40,30,
    66,244,200,100,184,135,212,124,135,154,59,112,101,155,68,29,
    167,217,167,249,200,140,5,76,66,69,161,215,94,139,228,167,
    52,90,189,30,207,255,121,155,120,54,151,33,200,32,11,208,
    155,227,118,158,246,136,86,209,18,75,220,46,48,113,209,18,
    203,220,94,99,226,146,37,86,184,93,102,226,138,37,174,114,
    187,198,196,117,75,220,224,118,147,137,91,150,184,205,237,117,
    38,238,88,226,46,183,55,152,248,142,205,62,55,153,88,133,
    214,45,123,237,243,13,202,68,133,255,53,19,113,240,94,77,
    216,122,255,215,4,212,184,127,245,138,52,184,36,126,83,242,
    113,96,226,188,241,129,73,62,198,71,88,236,140,214,38,202,
    95,86,90,236,99,101,130,37,242,49,23,207,158,99,170,228,
    51,135,114,173,193,55,27,116,108,136,229,75,239,162,56,49,
    165,48,65,197,31,14,101,28,158,149,185,252,229,242,141,70,
    153,134,14,141,182,218,192,154,118,13,159,215,129,76,250,77,
    168,203,128,205,103,208,189,126,101,30,143,179,220,122,123,42,
    183,54,200,165,38,155,102,137,212,248,231,187,51,114,152,23,
    250,218,247,252,32,144,74,73,229,37,113,127,68,231,171,255,
    138,31,11,34,190,95,122,253,147,174,206,18,211,247,181,140,
    3,51,215,215,50,209,4,180,137,140,223,245,183,102,13,56,
    82,210,27,248,10,45,232,69,33,203,126,75,86,154,129,178,
    214,20,149,107,190,139,141,32,59,169,148,60,193,215,241,144,
    100,130,190,121,213,187,179,216,213,72,177,188,55,50,144,48,
    46,211,71,106,182,102,74,166,145,223,247,212,159,142,124,213,
    125,179,17,166,89,173,17,166,168,250,155,179,6,7,105,130,
    7,217,161,223,145,102,229,111,197,72,115,208,173,227,4,77,
    223,152,185,188,232,115,99,228,55,115,144,76,190,36,195,23,
    142,109,189,195,6,239,75,45,47,76,72,154,34,100,124,249,
    17,226,2,210,100,132,7,114,62,211,226,123,223,243,174,168,
    248,248,33,78,67,167,74,190,146,165,226,163,32,214,207,253,
    21,115,69,193,85,223,185,171,127,179,88,178,83,227,35,106,
    120,59,88,202,194,159,175,166,109,181,197,121,159,46,35,246,
    252,129,185,104,228,123,179,198,45,106,110,219,228,193,168,53,
    71,124,62,58,155,235,11,204,241,124,129,193,229,103,227,46,
    140,255,83,194,104,212,68,88,202,129,166,105,101,124,52,240,
    62,145,131,36,29,125,146,132,230,250,254,201,1,154,218,15,
    180,33,123,47,36,21,181,92,93,153,225,211,223,249,90,51,
    245,99,244,255,82,198,130,159,204,93,237,4,173,25,89,26,
    173,48,123,227,82,142,145,48,109,104,118,123,42,59,17,69,
    57,139,201,134,140,183,43,114,131,190,53,19,114,19,195,175,
    6,39,230,24,101,110,142,30,147,206,124,199,69,119,169,197,
    165,162,40,56,116,117,239,138,146,40,139,156,88,44,23,221,
    98,161,152,119,17,75,68,89,21,37,183,88,90,20,147,127,
    219,136,169,146,179,189,92,20,95,1,224,188,125,126,
};

EmbeddedPython embedded_m5_internal_param_BasePrefetcher(
    "m5/internal/param_BasePrefetcher.py",
    "/nfs/ug/homes-0/m/moham356/ece552/Lab6/gem5/build/ALPHA/python/m5/internal/param_BasePrefetcher.py",
    "m5.internal.param_BasePrefetcher",
    data_m5_internal_param_BasePrefetcher,
    2302,
    7172);

} // anonymous namespace
