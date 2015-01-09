#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_BasicRouter[] = {
    120,156,197,88,109,111,219,214,21,62,151,164,100,75,182,98,
    57,142,157,164,205,26,21,69,48,173,88,163,44,93,210,189,
    4,193,210,173,123,41,10,55,165,6,36,81,183,113,52,121,
    37,209,150,72,129,164,147,106,176,191,204,193,182,111,251,17,
    195,62,236,127,236,127,109,231,57,151,164,101,59,221,10,108,
    144,5,241,226,242,242,242,222,115,158,243,156,151,203,128,138,
    95,141,175,159,116,136,178,135,138,40,228,191,162,9,209,84,
    209,64,145,210,138,194,45,58,168,81,250,125,10,107,244,154,
    104,96,145,182,232,132,59,54,125,105,81,188,46,239,212,105,
    98,203,136,162,121,147,180,67,131,26,61,139,55,201,209,117,
    58,104,82,250,123,82,74,197,138,158,135,43,20,174,210,107,
    94,157,59,13,89,112,149,194,166,116,26,20,174,73,167,73,
    243,54,233,53,26,240,226,43,52,104,241,82,239,243,82,87,
    100,169,127,98,169,144,159,92,163,176,133,233,44,203,11,204,
    116,48,83,246,184,34,171,108,148,146,181,105,208,166,112,131,
    116,155,246,55,105,200,42,181,171,247,174,146,182,105,127,139,
    6,91,164,249,127,149,78,88,235,112,83,230,94,147,185,87,
    171,185,219,50,119,135,6,59,164,249,191,109,230,214,169,223,
    221,102,12,163,127,241,175,203,24,82,190,206,205,75,157,102,
    81,18,123,81,60,76,34,11,207,235,104,128,120,128,102,165,
    128,254,167,128,254,31,36,184,135,86,1,253,49,241,194,10,
    242,79,44,58,150,206,177,69,243,46,29,41,218,119,40,180,
    233,136,183,169,65,128,145,162,19,139,126,99,99,194,49,183,
    14,131,245,14,57,185,193,125,95,192,50,43,173,208,113,141,
    142,106,212,127,126,100,97,224,160,65,233,223,233,15,183,100,
    209,85,89,212,162,35,110,29,58,113,232,184,78,207,120,18,
    15,237,55,160,190,122,126,196,154,242,72,191,235,176,180,187,
    11,234,66,149,48,74,99,127,170,243,171,220,247,102,126,234,
    79,189,143,253,44,10,220,228,48,215,105,183,89,206,75,178,
    187,51,63,31,187,242,162,13,68,166,179,92,22,76,98,157,
    175,113,103,24,197,161,55,77,194,195,137,206,87,177,154,55,
    140,38,218,243,228,225,175,166,179,36,205,63,73,211,36,117,
    1,170,12,78,18,191,122,3,144,6,147,36,211,93,236,38,
    219,184,88,62,199,236,225,76,86,132,0,34,44,94,14,117,
    22,164,209,44,103,91,153,21,49,27,171,117,97,37,105,50,
    143,155,94,60,204,122,135,163,222,56,153,234,236,131,123,189,
    105,111,154,140,253,233,135,15,30,246,116,160,31,60,184,223,
    251,204,223,123,216,27,233,233,131,222,222,97,52,9,123,79,
    62,123,250,203,39,189,217,60,31,39,113,143,71,163,152,145,
    136,253,73,239,2,60,119,121,18,128,203,94,69,35,47,18,
    21,189,177,158,204,116,10,9,179,183,32,132,106,171,117,85,
    87,182,234,170,22,247,106,124,217,234,150,181,166,118,35,40,
    25,64,113,48,204,46,57,245,55,18,235,177,241,15,44,74,
    111,129,49,251,252,87,48,49,243,166,143,103,150,60,251,2,
    232,152,209,125,27,60,48,131,71,194,50,166,27,207,124,4,
    195,199,36,84,169,209,126,157,12,133,152,121,134,83,233,28,
    45,79,199,50,22,47,238,80,246,215,179,43,196,109,98,244,
    217,75,121,104,135,183,250,163,176,178,223,133,224,187,194,141,
    124,28,101,201,171,88,44,128,190,248,81,159,49,121,58,255,
    124,111,95,7,121,118,155,7,94,36,135,157,192,143,227,36,
    239,248,97,216,241,243,60,141,246,24,197,172,147,39,157,59,
    89,183,1,147,111,150,244,170,214,155,207,74,58,193,244,76,
    39,115,19,70,65,206,55,91,114,35,248,103,58,103,106,140,
    147,48,227,113,44,49,210,185,11,33,243,43,220,60,41,183,
    19,14,118,235,37,99,50,61,25,230,77,33,159,159,101,158,
    108,135,113,225,25,222,126,233,79,14,117,142,249,89,238,231,
    188,43,186,102,163,37,51,237,6,116,45,85,5,124,94,156,
    196,225,156,37,141,130,247,32,196,13,225,219,58,129,113,219,
    204,182,21,110,235,212,98,246,181,173,0,74,57,5,215,132,
    103,59,128,128,196,246,170,136,32,204,185,19,142,51,93,75,
    2,133,104,39,142,216,65,15,47,187,160,180,251,54,154,91,
    104,190,85,2,176,60,20,90,231,81,184,135,157,45,81,61,
    176,11,37,43,103,218,61,227,76,55,79,157,137,35,99,31,
    78,97,193,117,78,157,194,6,12,233,227,194,3,224,110,76,
    2,126,188,192,123,1,199,109,67,233,122,73,89,23,60,92,
    36,227,104,129,140,46,236,34,76,116,111,126,29,144,183,47,
    19,200,145,1,242,67,236,188,94,112,168,37,220,105,170,0,
    4,176,10,88,5,210,159,113,103,126,29,144,46,130,121,157,
    179,221,179,184,37,105,75,82,159,36,116,19,71,12,198,166,
    227,128,109,67,155,118,138,116,148,193,237,103,105,242,213,188,
    147,12,59,57,149,50,60,186,147,221,189,147,253,152,3,67,
    231,177,132,26,19,26,140,243,167,122,150,178,147,55,228,198,
    56,174,39,78,236,21,233,132,65,71,106,23,91,9,212,18,
    167,178,60,69,120,90,50,206,205,10,103,136,253,67,108,219,
    20,144,109,186,206,87,83,137,108,94,34,145,82,74,12,121,
    202,215,199,128,27,26,107,66,81,231,246,141,228,162,20,212,
    115,191,125,134,53,75,83,201,125,31,194,149,110,87,167,138,
    35,184,108,8,13,79,248,51,73,25,166,232,79,4,62,176,
    217,11,223,17,47,197,5,179,110,97,250,239,72,130,208,27,
    82,158,101,124,208,42,194,20,187,104,246,145,76,53,25,240,
    83,250,203,66,4,59,177,73,33,91,217,69,161,181,152,173,
    156,202,107,133,72,223,40,35,57,103,221,27,102,26,251,25,
    166,25,71,182,43,71,62,13,134,85,125,196,209,105,121,28,
    91,53,27,122,144,237,23,167,12,67,42,120,91,109,89,11,
    188,249,46,154,15,42,202,168,114,108,41,98,222,62,31,187,
    23,50,152,103,226,229,207,33,139,35,210,111,212,165,208,91,
    88,163,242,142,90,233,29,247,43,239,208,18,195,95,75,61,
    142,214,2,9,78,44,197,135,27,174,93,112,174,112,72,215,
    104,80,135,31,73,181,169,10,55,83,101,100,67,68,60,147,
    32,4,158,93,3,92,197,3,99,98,52,95,45,57,146,192,
    202,143,38,254,116,47,244,31,187,216,20,59,7,165,227,89,
    165,26,237,69,53,224,52,234,235,52,145,219,123,165,58,47,
    151,28,69,190,135,221,75,53,196,103,194,36,144,208,241,235,
    177,238,76,245,116,143,143,98,227,104,214,25,78,252,145,88,
    203,46,212,252,188,84,51,23,115,159,79,206,82,218,236,38,
    157,32,137,57,228,31,6,121,146,118,66,205,231,19,29,26,
    194,159,245,94,169,247,252,116,148,73,105,119,240,10,221,75,
    176,172,199,71,206,136,107,218,126,9,137,57,9,85,129,94,
    202,88,227,61,156,47,249,140,145,207,77,60,123,136,230,59,
    104,238,208,229,228,131,30,239,241,5,54,3,128,117,14,57,
    13,149,111,158,117,221,167,120,47,187,232,192,123,223,196,129,
    205,119,137,194,141,235,152,169,87,112,244,69,219,64,82,24,
    52,203,175,28,107,50,184,142,79,10,124,194,199,200,21,56,
    252,202,255,234,240,226,38,151,224,32,47,254,175,126,238,222,
    191,100,45,92,41,50,255,147,143,171,69,21,91,198,199,247,
    85,89,141,47,234,39,167,254,27,111,162,153,23,164,218,207,
    181,49,220,91,75,87,89,226,136,17,225,203,202,124,165,94,
    213,209,228,163,74,183,19,41,144,230,215,22,138,101,177,166,
    122,198,213,12,23,212,71,162,190,103,153,154,250,148,166,78,
    133,2,130,68,172,95,121,23,144,48,85,51,228,241,103,51,
    29,135,167,21,177,60,89,50,21,16,169,126,75,167,229,9,
    151,191,215,248,186,232,152,208,108,65,81,177,99,173,114,197,
    229,91,84,72,188,87,218,178,187,65,139,129,217,133,37,77,
    40,174,162,176,251,163,202,54,183,223,200,208,84,110,188,40,
    196,233,235,191,206,225,114,73,78,59,213,136,64,41,228,15,
    245,68,231,250,162,229,115,8,84,156,70,67,205,121,48,153,
    243,33,73,142,26,124,63,241,188,203,72,20,63,224,61,158,
    99,51,228,50,36,138,58,167,138,109,213,112,26,74,242,241,
    185,15,174,70,186,235,84,150,212,243,204,149,32,178,81,129,
    43,159,5,203,108,40,30,5,152,118,253,169,249,206,35,95,
    46,220,119,209,188,87,218,71,188,193,156,182,228,32,99,142,
    145,236,61,114,144,148,218,192,189,139,113,236,98,180,232,71,
    83,243,33,75,230,86,119,146,247,206,71,32,65,60,213,163,
    40,227,27,89,163,154,95,184,36,64,200,223,121,163,197,23,
    223,189,4,251,152,10,211,28,161,31,67,213,12,178,226,115,
    82,99,163,161,234,22,62,93,218,170,169,90,202,81,235,173,
    134,221,168,55,106,54,219,16,35,91,170,105,55,154,235,234,
    38,219,178,105,221,92,107,168,127,3,109,155,99,134,
};

EmbeddedPython embedded_m5_internal_param_BasicRouter(
    "m5/internal/param_BasicRouter.py",
    "/nfs/ug/homes-0/m/moham356/ece552/Lab6/gem5/build/ALPHA/python/m5/internal/param_BasicRouter.py",
    "m5.internal.param_BasicRouter",
    data_m5_internal_param_BasicRouter,
    2046,
    6314);

} // anonymous namespace
