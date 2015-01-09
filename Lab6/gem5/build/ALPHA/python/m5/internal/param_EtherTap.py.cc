#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_EtherTap[] = {
    120,156,197,88,109,111,219,200,17,158,37,41,218,148,173,88,
    126,139,157,75,218,168,56,4,85,15,189,40,205,53,185,190,
    4,65,211,222,245,13,7,95,74,165,72,78,119,45,75,147,
    43,137,178,68,10,228,42,57,29,236,47,117,208,246,67,129,
    254,136,162,31,250,63,250,191,174,51,179,36,69,217,231,226,
    128,182,138,45,46,150,187,195,217,121,121,102,118,118,3,200,
    255,106,248,252,164,5,144,29,9,128,16,127,2,198,0,19,
    1,61,1,66,10,8,119,225,164,6,233,247,33,172,193,107,
    128,158,1,210,128,115,236,152,240,169,1,241,38,127,99,195,
    216,228,17,1,243,58,72,11,122,53,120,30,111,131,37,109,
    56,169,67,250,7,16,66,196,2,94,132,107,16,174,195,107,
    228,142,29,135,25,174,67,88,231,142,3,225,6,119,234,48,
    111,130,220,128,30,50,95,131,94,3,89,189,131,172,174,49,
    171,127,17,171,16,103,246,32,108,16,57,202,242,9,81,90,
    68,201,107,92,99,46,91,133,100,77,232,53,139,254,54,244,
    182,139,254,14,244,118,32,220,2,185,3,163,93,232,163,170,
    205,146,223,30,72,19,70,251,208,219,7,137,191,61,56,71,
    107,132,219,76,123,157,105,119,74,218,3,166,61,132,222,33,
    72,252,29,104,90,27,186,237,125,180,109,244,37,254,181,209,
    182,160,54,177,121,41,211,44,74,98,47,138,251,73,100,208,
    188,77,13,121,34,160,102,45,119,201,207,200,37,255,4,246,
    71,104,228,46,57,3,100,44,72,254,177,1,103,220,57,51,
    96,222,134,83,1,35,11,66,19,78,113,153,26,9,48,16,
    112,110,192,103,38,17,156,97,107,161,17,191,9,150,210,254,
    24,177,17,53,167,53,56,171,193,105,13,186,47,78,13,26,
    56,113,32,253,7,124,113,139,153,174,51,83,3,78,177,181,
    224,220,130,51,27,158,35,17,14,141,28,82,95,188,56,69,
    77,113,164,219,182,80,218,163,138,186,164,74,24,165,177,63,
    145,106,11,251,222,212,79,253,137,247,161,26,202,244,153,63,
    109,215,11,162,36,187,59,245,213,208,229,175,76,50,199,100,
    170,152,91,18,75,181,129,157,126,20,135,222,36,9,103,99,
    169,214,137,149,215,143,198,210,243,120,242,87,147,105,146,170,
    15,211,52,73,93,178,40,15,142,19,191,252,130,236,25,140,
    147,76,182,105,53,94,198,37,246,138,168,251,83,230,72,2,
    176,164,244,113,40,179,32,141,166,10,29,165,57,18,53,113,
    107,147,139,184,201,62,195,166,19,247,179,206,108,208,25,38,
    19,153,189,123,175,51,233,76,146,161,63,121,239,193,195,142,
    12,228,131,7,247,59,31,249,199,15,59,3,57,121,208,57,
    158,69,227,176,243,228,163,167,191,124,210,153,206,213,48,137,
    59,56,26,197,74,162,133,198,157,101,219,220,69,138,29,90,
    229,85,52,240,34,214,207,27,202,241,84,166,36,94,246,22,
    73,32,154,98,83,216,194,20,109,209,192,94,13,31,83,220,
    50,54,196,81,68,26,6,164,53,97,203,44,208,244,119,96,
    191,161,219,79,12,72,111,17,86,70,248,19,228,92,68,76,
    151,230,12,158,251,13,153,70,143,142,76,66,128,30,60,101,
    124,33,208,144,242,17,185,60,6,6,73,13,70,54,104,240,
    32,230,52,154,210,57,181,72,78,108,12,100,110,65,246,183,
    101,14,113,19,208,244,24,183,56,116,29,151,250,35,227,177,
    219,38,193,143,24,24,106,24,101,201,171,152,205,79,125,142,
    160,46,218,228,233,252,227,227,145,12,84,118,27,7,62,73,
    102,173,192,143,227,68,181,252,48,108,249,74,165,209,241,76,
    201,172,165,146,214,157,172,237,144,191,183,11,108,149,252,230,
    211,2,75,228,119,196,146,126,9,163,64,225,203,46,191,176,
    253,51,169,16,23,195,36,204,112,156,88,12,164,114,73,72,
    117,13,155,39,197,114,12,192,182,93,192,37,147,227,190,170,
    51,242,252,44,243,120,57,26,103,144,209,215,47,253,241,76,
    42,162,207,148,175,112,85,234,234,133,86,9,179,67,82,180,
    208,147,108,231,197,73,28,206,81,204,40,120,155,36,56,100,
    176,109,2,193,109,31,161,182,134,173,13,13,132,94,211,8,
    72,35,43,7,26,131,236,58,233,15,236,120,145,39,14,4,
    220,57,166,151,182,193,249,129,85,227,16,108,81,143,62,118,
    9,207,238,77,106,110,81,243,141,66,251,21,153,160,113,209,
    4,247,104,89,131,245,14,204,92,195,50,140,142,150,194,232,
    198,34,140,48,27,118,41,28,12,10,154,69,56,152,100,131,
    244,113,142,125,10,52,116,63,78,87,16,207,150,113,155,164,
    177,93,128,213,37,4,86,97,56,168,192,208,37,167,48,6,
    221,27,87,89,241,246,27,179,226,64,91,241,61,90,118,51,
    71,79,131,81,83,23,1,185,222,200,109,202,246,252,0,59,
    243,3,178,103,213,146,7,184,189,61,143,27,188,79,241,94,
    199,59,187,78,31,218,192,186,99,17,206,250,38,92,207,247,
    159,140,162,125,154,38,159,207,91,73,191,165,160,144,225,209,
    157,236,238,157,236,199,152,15,90,143,57,195,232,140,160,99,
    62,149,211,20,99,219,225,23,29,175,30,199,174,151,111,33,
    104,113,218,203,217,81,108,103,78,79,153,74,41,43,173,210,
    200,245,210,200,36,243,15,105,205,58,91,216,132,3,124,234,
    130,5,243,18,206,142,92,80,240,44,62,63,37,91,147,186,
    18,168,180,115,187,90,108,214,136,116,115,191,189,132,151,213,
    232,227,190,67,146,21,209,102,67,137,14,122,76,146,152,2,
    224,207,192,21,151,128,63,1,33,1,29,158,135,12,7,39,
    61,228,208,93,34,255,61,112,226,249,138,61,206,208,161,103,
    228,169,9,35,51,123,159,73,245,150,247,107,248,75,37,107,
    157,155,32,104,123,50,243,154,170,186,61,89,101,176,50,132,
    190,214,22,100,45,71,53,249,104,232,103,68,166,227,215,44,
    227,119,145,0,203,106,8,147,210,138,208,181,174,87,243,72,
    176,95,44,176,69,185,255,166,216,53,42,136,249,46,53,239,
    150,96,17,197,216,255,95,198,219,23,147,117,101,191,242,116,
    130,252,57,9,98,177,232,91,54,43,85,48,40,35,162,86,
    68,196,253,50,34,36,103,236,215,92,113,83,107,144,239,207,
    13,129,199,26,172,81,232,68,97,129,172,65,207,166,216,225,
    146,82,228,161,37,138,84,70,41,112,105,59,96,195,28,105,
    147,149,238,215,158,165,230,243,85,166,14,178,195,163,177,63,
    57,14,253,199,207,104,69,90,54,40,130,205,40,116,104,86,
    117,160,64,17,87,169,193,175,247,10,93,94,174,50,109,124,
    15,23,40,117,224,32,9,147,128,115,197,179,161,108,77,228,
    228,24,143,89,195,104,218,234,143,253,1,251,201,204,117,252,
    184,208,81,177,163,47,110,194,92,191,28,37,173,32,137,49,
    187,207,2,149,164,173,80,226,241,67,134,26,228,203,225,202,
    21,157,159,14,50,46,222,78,94,81,119,213,62,245,240,44,
    25,97,201,250,219,194,30,250,148,83,230,116,174,82,117,196,
    224,190,136,71,8,53,215,217,235,33,53,223,161,230,14,188,
    129,212,223,193,5,186,180,18,153,206,198,4,227,8,22,181,
    160,121,74,95,100,151,35,246,175,95,39,98,245,21,68,30,
    183,54,81,202,53,58,205,82,235,80,242,239,213,139,193,13,
    110,55,121,176,81,12,94,227,118,139,7,155,197,213,199,54,
    15,238,64,111,151,238,15,104,100,143,114,193,218,127,155,11,
    56,136,86,29,62,159,254,79,83,128,123,255,77,170,224,114,
    169,249,159,194,95,84,245,107,232,240,31,137,162,32,175,42,
    199,231,253,253,75,56,244,130,84,250,74,106,127,189,181,90,
    101,57,185,232,245,127,87,122,173,208,168,60,151,188,95,106,
    117,206,101,210,124,175,82,44,179,19,197,115,172,105,176,160,
    62,101,197,61,67,215,212,11,104,90,165,254,116,247,16,203,
    87,222,178,13,116,201,76,194,248,211,169,140,195,69,57,204,
    51,171,116,63,229,46,31,22,21,10,214,190,123,248,92,14,
    67,210,169,162,34,187,175,86,6,222,138,29,201,168,237,23,
    46,228,235,193,69,158,118,201,129,58,51,151,73,217,253,81,
    233,146,195,203,144,60,158,245,179,47,232,180,117,245,36,214,
    72,124,217,192,111,234,224,50,89,56,155,76,153,197,85,115,
    196,129,141,136,47,95,69,196,119,83,87,48,224,185,130,1,
    189,176,223,56,186,66,57,150,74,94,0,152,34,237,243,227,
    110,40,113,3,78,230,120,16,227,19,13,190,143,61,111,229,
    155,212,15,112,129,30,173,68,17,65,155,148,141,219,212,62,
    255,59,150,35,184,18,184,112,141,171,197,163,58,65,87,239,
    243,204,229,28,181,85,186,146,239,27,139,173,152,195,150,78,
    158,71,254,68,223,33,241,197,136,251,45,106,222,46,208,192,
    81,167,79,117,124,102,210,103,85,12,81,62,173,114,85,226,
    222,165,113,90,165,162,198,7,228,181,197,88,55,154,232,139,
    51,181,189,76,151,143,110,20,62,212,239,188,71,47,37,67,
    246,77,42,7,81,134,38,99,38,21,242,60,75,144,205,212,
    205,203,104,168,126,186,106,71,234,234,87,31,230,31,147,237,
    178,71,216,208,149,150,179,229,8,219,160,187,83,83,212,69,
    67,88,98,179,225,152,142,237,212,76,116,54,141,236,138,186,
    233,212,55,5,253,223,64,167,215,141,27,13,71,252,27,179,
    52,126,221,
};

EmbeddedPython embedded_m5_internal_param_EtherTap(
    "m5/internal/param_EtherTap.py",
    "/nfs/ug/homes-0/m/moham356/ece552/Lab6/gem5/build/ALPHA/python/m5/internal/param_EtherTap.py",
    "m5.internal.param_EtherTap",
    data_m5_internal_param_EtherTap,
    2115,
    6465);

} // anonymous namespace
