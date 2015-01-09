#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_EtherBus[] = {
    120,156,197,88,235,111,219,200,17,159,37,41,218,146,173,88,
    126,197,206,37,109,84,28,130,170,135,94,148,230,154,92,31,
    65,208,92,239,209,22,7,95,74,93,145,156,238,193,210,228,
    74,162,204,135,64,174,146,83,97,127,169,131,182,31,10,244,
    143,40,250,161,255,71,255,175,118,102,150,164,36,59,57,28,
    208,86,177,197,197,114,119,56,59,143,223,204,206,174,15,197,
    95,13,159,95,180,1,242,35,1,16,224,79,64,4,16,11,
    232,11,16,82,64,176,11,39,53,200,126,12,65,13,94,0,
    244,13,144,6,156,99,199,132,207,13,72,54,249,27,27,34,
    147,71,4,204,26,32,45,232,215,224,73,178,13,150,180,225,
    164,1,217,239,65,8,145,8,120,26,172,65,176,14,47,144,
    59,118,234,204,112,29,130,6,119,234,16,108,112,167,1,179,
    22,200,13,232,35,243,53,232,55,145,213,91,200,234,10,179,
    250,23,177,10,112,102,15,130,38,145,163,44,159,17,165,69,
    148,188,198,21,230,178,85,74,214,130,126,171,236,111,67,127,
    187,236,239,64,127,7,130,45,144,59,48,222,133,1,170,218,
    170,248,237,129,52,97,188,15,253,125,144,248,219,131,115,180,
    70,176,205,180,87,153,118,167,162,61,96,218,67,232,31,130,
    196,223,129,166,181,161,215,217,71,219,134,255,198,191,14,218,
    22,212,38,54,207,100,150,135,105,226,134,201,32,13,13,154,
    183,169,33,79,248,212,172,21,46,249,37,185,228,159,192,254,
    8,140,194,37,103,128,140,5,201,31,25,112,198,157,51,3,
    102,29,56,21,48,182,32,48,225,20,151,169,145,0,67,1,
    231,6,124,97,18,193,25,182,22,26,241,187,96,41,237,143,
    49,27,81,115,90,131,179,26,156,214,160,247,244,212,160,129,
    147,58,100,255,128,63,220,96,166,235,204,212,128,83,108,45,
    56,183,224,204,134,39,72,132,67,227,58,169,47,158,158,162,
    166,56,210,235,88,40,237,209,130,186,164,74,16,102,137,23,
    75,181,133,125,119,226,101,94,236,126,160,70,50,123,111,154,
    119,26,37,81,154,223,158,120,106,228,240,87,38,153,35,158,
    40,230,150,38,82,109,96,103,16,38,129,27,167,193,52,146,
    106,157,88,185,131,48,146,174,203,147,191,142,39,105,166,62,
    200,178,52,115,200,162,60,24,165,94,245,5,217,211,143,210,
    92,118,104,53,94,198,33,246,138,168,7,19,230,72,2,176,
    164,244,113,32,115,63,11,39,10,29,165,57,18,53,113,235,
    144,139,184,201,191,192,166,155,12,242,238,116,216,29,165,177,
    204,223,190,211,141,187,113,58,242,226,119,238,221,239,74,95,
    222,187,119,183,251,177,119,124,191,59,148,241,189,238,241,52,
    140,130,238,163,143,31,255,234,81,119,50,83,163,52,233,226,
    104,152,40,137,22,138,186,203,182,185,141,20,59,180,202,243,
    112,232,134,172,159,59,146,209,68,102,36,94,254,6,73,32,
    90,98,83,216,194,20,29,209,196,94,13,31,83,220,48,54,
    196,81,72,26,250,164,53,97,203,44,209,244,119,96,191,161,
    219,79,12,200,110,16,86,198,248,19,228,92,68,76,143,230,
    12,158,251,45,153,70,143,142,77,66,128,30,60,101,124,33,
    208,144,242,1,185,60,1,6,73,13,198,54,104,240,32,230,
    52,154,178,25,181,72,78,108,12,100,110,65,254,183,101,14,
    73,11,208,244,24,183,56,116,21,151,250,35,227,177,215,33,
    193,143,24,24,106,20,230,233,243,132,205,79,125,142,160,30,
    218,228,241,236,147,227,177,244,85,126,19,7,62,75,167,109,
    223,75,146,84,181,189,32,104,123,74,101,225,241,84,201,188,
    173,210,246,173,188,83,39,127,111,151,216,170,248,205,38,37,
    150,200,239,136,37,253,18,132,190,194,151,93,126,97,251,231,
    82,33,46,70,105,144,227,56,177,24,74,229,144,144,234,10,
    54,143,202,229,24,128,29,187,132,75,46,163,129,106,48,242,
    188,60,119,121,57,26,103,144,209,215,207,188,104,42,21,209,
    231,202,83,184,42,117,245,66,171,132,217,33,41,90,234,73,
    182,115,147,52,9,102,40,102,232,191,73,18,28,50,216,54,
    129,224,182,143,80,91,195,214,134,38,66,175,101,248,164,145,
    85,0,141,65,118,149,244,7,118,188,40,18,7,2,238,28,
    211,75,199,224,252,192,170,113,8,182,169,71,31,59,132,103,
    231,58,53,55,168,249,78,169,253,138,76,208,188,104,130,59,
    180,172,193,122,251,102,161,97,21,70,71,75,97,116,109,30,
    70,152,13,123,20,14,6,5,205,60,28,76,178,65,246,176,
    192,62,5,26,186,31,167,23,16,207,150,113,90,164,177,93,
    130,213,33,4,46,194,112,184,0,67,135,156,194,24,116,174,
    189,202,138,55,95,155,21,135,218,138,239,208,178,155,5,122,
    154,140,154,134,240,201,245,70,97,83,182,231,251,216,153,29,
    144,61,23,45,121,128,219,219,147,164,201,251,20,239,117,188,
    179,235,244,161,13,172,59,22,225,108,96,194,213,98,255,201,
    41,218,39,89,250,245,172,157,14,218,10,74,25,30,220,202,
    111,223,202,127,142,249,160,253,144,51,140,206,8,58,230,51,
    57,201,48,182,235,252,162,227,213,229,216,117,139,45,4,45,
    78,123,57,59,138,237,204,233,41,87,25,101,165,85,26,185,
    81,25,153,100,254,41,173,217,96,11,155,112,128,79,67,176,
    96,110,202,217,145,11,10,158,197,231,61,178,53,169,43,129,
    74,59,167,167,197,102,141,72,55,231,251,75,120,89,141,62,
    206,91,36,89,25,109,54,84,232,160,199,36,137,41,0,254,
    12,92,113,9,248,19,16,18,208,225,69,200,112,112,210,67,
    14,221,37,242,175,128,19,207,75,246,56,67,135,158,81,164,
    38,140,204,252,93,38,213,91,222,111,224,47,11,89,235,220,
    4,65,219,147,89,212,84,139,219,147,85,5,43,67,232,91,
    109,65,214,114,84,147,143,70,94,78,100,58,126,205,42,126,
    231,9,176,170,134,48,41,173,8,93,235,122,53,151,4,251,
    104,142,45,202,253,215,197,174,177,128,152,31,82,243,118,5,
    22,81,142,253,255,101,188,121,49,89,47,236,87,174,78,144,
    31,146,32,22,139,190,101,179,82,37,131,42,34,106,101,68,
    220,173,34,66,114,198,126,193,21,55,181,6,249,254,220,16,
    120,172,193,26,133,78,20,22,200,26,244,109,138,29,46,41,
    69,17,90,162,76,101,148,2,151,182,3,54,204,145,54,89,
    229,126,237,89,106,190,94,101,234,32,59,60,136,188,248,56,
    240,30,126,74,43,210,178,126,25,108,70,169,67,107,81,7,
    10,20,241,42,53,248,245,78,169,203,179,85,166,141,31,225,
    2,149,14,28,36,65,234,115,174,248,116,36,219,177,140,143,
    241,152,53,10,39,237,65,228,13,217,79,102,161,227,39,165,
    142,138,29,125,113,19,230,250,229,40,109,251,105,130,217,125,
    234,171,52,107,7,18,143,31,50,208,32,95,14,87,174,232,
    188,108,152,115,241,118,242,156,186,171,246,169,139,103,201,16,
    75,214,223,149,246,208,167,156,42,167,115,149,170,35,6,247,
    69,60,66,168,153,206,94,247,169,249,1,53,183,224,53,164,
    254,46,46,208,163,149,200,116,54,38,152,186,96,81,75,154,
    199,244,197,75,34,246,175,223,38,98,245,21,68,17,183,54,
    81,202,53,58,205,82,91,167,228,223,111,148,131,27,220,110,
    242,96,179,28,188,194,237,22,15,182,202,171,143,109,30,220,
    129,254,46,221,31,208,200,30,229,130,181,255,54,23,112,16,
    173,58,124,62,255,159,166,0,231,238,235,84,193,225,82,243,
    155,194,95,44,234,215,212,225,63,22,101,65,190,168,28,159,
    247,247,47,225,208,245,51,233,41,169,253,245,198,106,149,229,
    228,162,215,255,178,242,90,169,81,117,46,121,183,210,234,156,
    203,164,217,222,66,177,204,78,20,79,176,166,193,130,250,148,
    21,119,13,93,83,207,161,105,85,250,211,221,67,34,159,187,
    203,54,208,37,51,9,227,77,38,50,9,230,229,48,207,172,
    210,253,148,187,60,152,87,40,88,251,238,225,115,57,12,73,
    167,5,21,217,125,181,42,240,86,236,72,70,237,160,116,33,
    95,15,206,243,180,67,14,212,153,185,74,202,206,207,42,151,
    28,94,134,100,62,145,50,160,211,214,171,39,177,70,226,203,
    6,126,83,7,151,201,130,105,60,97,22,175,154,35,14,108,
    68,124,81,215,47,19,69,105,58,57,246,252,19,102,242,77,
    243,196,136,246,171,114,128,125,200,145,22,200,72,42,121,1,
    108,138,44,81,28,125,3,137,155,113,58,195,67,25,159,110,
    240,61,114,221,149,111,88,63,193,5,250,180,18,69,7,109,
    88,54,110,89,251,252,95,183,234,130,171,130,11,87,186,90,
    60,170,25,116,37,63,203,29,206,87,91,149,91,249,238,177,
    220,150,57,132,233,20,122,228,197,250,62,137,47,73,156,239,
    81,243,102,137,12,142,64,125,194,227,243,147,62,183,98,184,
    242,201,149,43,20,231,54,141,211,42,11,106,188,79,30,156,
    143,245,194,88,95,162,169,237,101,186,98,116,163,244,165,126,
    231,253,122,41,49,178,111,50,57,12,115,52,25,51,89,32,
    47,50,6,217,236,101,168,88,252,116,213,142,212,149,176,62,
    216,63,36,219,229,15,176,161,235,173,250,86,93,216,6,221,
    163,154,162,33,154,194,18,155,205,186,89,183,235,53,19,157,
    77,35,187,162,97,214,27,155,130,254,175,161,211,27,198,181,
    102,93,252,7,55,82,131,213,
};

EmbeddedPython embedded_m5_internal_param_EtherBus(
    "m5/internal/param_EtherBus.py",
    "/nfs/ug/homes-0/m/moham356/ece552/Lab6/gem5/build/ALPHA/python/m5/internal/param_EtherBus.py",
    "m5.internal.param_EtherBus",
    data_m5_internal_param_EtherBus,
    2120,
    6477);

} // anonymous namespace