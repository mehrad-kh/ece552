#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_Uart8250[] = {
    120,156,197,88,109,115,219,198,17,222,3,72,74,164,68,139,
    178,222,44,91,177,232,100,60,101,51,141,233,58,149,147,182,
    30,79,157,164,47,233,196,138,10,166,99,7,77,139,66,192,
    145,4,69,0,28,224,36,135,29,233,75,229,105,251,173,63,
    162,211,15,253,31,157,254,173,118,119,143,7,146,114,221,201,
    76,91,90,34,110,22,119,135,189,125,121,118,111,239,2,152,
    252,149,241,249,81,19,32,255,135,0,8,241,39,96,8,16,
    11,112,5,8,41,32,220,128,147,50,100,223,131,176,12,47,
    1,92,11,164,5,151,72,216,240,43,11,146,85,254,166,2,
    67,155,123,4,140,107,32,75,224,150,225,89,178,14,37,89,
    129,147,26,100,191,5,33,68,34,224,121,184,4,225,50,188,
    68,238,72,84,153,225,50,132,53,38,170,16,174,48,81,131,
    113,3,228,10,184,200,124,9,220,58,178,122,23,89,93,99,
    86,127,39,86,33,142,108,66,88,167,233,40,203,151,52,179,
    68,51,121,141,107,204,101,205,72,214,0,183,97,232,117,112,
    215,13,125,29,220,235,134,222,0,119,195,208,155,224,110,26,
    122,11,220,45,67,111,131,187,109,232,29,112,119,12,125,3,
    220,27,134,222,5,119,215,208,55,193,189,105,232,91,224,222,
    50,244,30,184,123,16,174,129,108,192,224,45,232,162,137,27,
    133,30,183,65,218,48,216,7,119,31,36,254,110,195,37,122,
    33,92,231,185,77,158,123,189,152,123,135,231,190,13,238,219,
    32,241,119,71,207,173,64,167,181,133,62,141,254,137,127,45,
    244,41,168,85,108,206,100,150,71,105,226,69,73,55,141,44,
    26,175,80,67,8,8,168,89,154,64,225,99,130,194,223,128,
    113,16,90,19,40,92,0,50,22,36,255,208,130,11,38,46,
    44,24,183,224,92,192,160,4,161,13,231,184,76,153,4,232,
    9,184,180,224,43,155,38,92,96,91,66,231,221,134,146,210,
    56,24,176,243,52,167,37,184,40,195,121,25,58,207,207,45,
    234,56,169,66,246,87,248,221,30,51,93,102,166,22,156,99,
    91,130,203,18,92,84,224,25,78,194,174,65,149,212,23,207,
    207,81,83,236,233,180,74,40,237,225,140,186,164,74,24,101,
    137,31,75,181,134,180,55,242,51,63,246,126,233,103,234,195,
    7,7,247,91,53,51,41,205,239,141,124,213,119,248,43,155,
    204,17,143,20,115,75,19,169,86,144,232,70,73,232,197,105,
    120,58,148,106,153,88,121,221,104,40,61,143,7,63,141,71,
    105,166,126,156,101,105,230,144,69,185,115,152,250,197,23,100,
    207,96,152,230,178,69,171,241,50,14,177,87,52,187,59,98,
    142,36,0,75,74,31,135,50,15,178,104,164,208,81,154,35,
    205,38,110,45,114,17,55,249,87,216,180,147,110,222,62,237,
    181,251,105,44,243,247,238,183,227,118,156,246,253,248,253,131,
    135,109,25,200,131,131,7,237,207,252,227,135,237,158,140,15,
    218,199,167,209,48,108,63,249,236,232,103,79,218,163,177,234,
    167,73,27,123,163,68,73,180,208,176,61,111,155,123,56,227,
    58,173,242,34,234,121,17,235,231,245,229,112,36,51,18,47,
    191,73,18,136,134,88,21,21,97,139,150,168,35,85,198,199,
    22,123,214,138,56,140,72,195,128,180,38,108,217,6,77,127,
    1,246,27,186,253,196,130,108,143,176,50,192,159,32,231,34,
    98,58,52,102,241,216,47,200,52,186,119,96,19,2,116,231,
    57,227,11,129,134,51,31,145,203,19,96,144,148,97,80,1,
    13,30,196,156,70,83,54,166,22,167,19,27,11,153,151,32,
    255,243,60,135,164,1,104,122,204,23,216,181,141,75,253,158,
    241,216,105,145,224,135,12,12,213,143,242,244,69,194,230,39,
    154,35,168,131,54,57,26,127,126,60,144,129,202,247,177,227,
    203,244,180,25,248,73,146,170,166,31,134,77,95,169,44,58,
    62,85,50,111,170,180,121,55,111,85,201,223,235,6,91,5,
    191,241,200,96,137,252,142,88,210,47,97,20,40,124,217,224,
    23,182,127,46,21,226,162,159,134,57,246,19,139,158,84,14,
    9,169,174,97,243,196,44,199,0,108,85,12,92,114,57,236,
    170,26,35,207,207,115,143,151,163,126,6,25,125,125,230,15,
    79,165,162,249,185,242,21,174,74,164,94,104,145,48,187,65,
    138,26,61,201,118,94,146,38,225,24,197,140,130,119,72,130,
    27,12,182,85,32,184,109,33,212,150,176,173,64,29,161,215,
    176,2,210,168,52,1,26,131,108,155,244,7,118,188,152,36,
    14,4,220,37,166,151,150,197,249,129,85,227,16,108,18,69,
    31,59,132,103,231,22,53,123,212,188,101,180,95,144,9,234,
    87,77,112,159,150,181,88,239,192,158,104,88,132,209,225,92,
    24,237,78,195,8,179,97,135,194,193,162,160,153,134,131,77,
    54,200,30,79,176,79,129,134,238,199,225,25,196,179,101,156,
    6,105,92,49,96,117,8,129,179,48,236,205,192,208,33,167,
    48,6,157,221,215,89,113,255,141,89,177,167,173,248,62,45,
    187,58,65,79,157,81,83,19,1,185,222,154,216,148,237,249,
    9,18,227,29,178,231,172,37,119,112,123,123,150,212,121,159,
    226,189,142,43,10,157,62,180,129,53,81,34,156,117,109,216,
    158,236,63,57,69,251,40,75,191,30,55,211,110,83,129,145,
    225,209,221,252,222,221,252,135,152,15,154,143,57,195,232,140,
    160,99,62,147,163,12,99,187,202,47,58,94,61,142,93,111,
    178,133,160,197,105,47,103,71,177,157,57,61,229,42,163,172,
    180,72,35,215,10,35,147,204,223,167,53,107,108,97,27,118,
    240,169,9,22,204,75,57,59,114,65,193,163,248,124,68,182,
    38,117,37,80,73,233,116,180,216,172,17,233,230,124,107,14,
    47,139,209,199,121,151,36,51,209,86,129,2,29,244,216,36,
    49,5,192,31,129,43,46,1,127,0,66,2,58,124,18,50,
    28,156,244,144,67,55,104,250,111,128,19,207,191,217,227,44,
    29,122,214,36,53,97,100,230,31,240,84,189,229,253,28,254,
    52,147,181,46,109,16,180,61,217,147,154,106,118,123,42,21,
    193,202,16,250,70,91,80,105,62,170,201,71,125,63,167,105,
    58,126,237,34,126,167,9,176,168,134,48,41,45,8,93,203,
    122,53,143,4,251,233,20,91,148,251,111,137,13,107,6,49,
    223,161,230,189,2,44,194,244,253,255,101,220,191,154,172,103,
    246,43,79,39,200,159,144,32,37,22,125,173,194,74,25,6,
    69,68,148,77,68,60,40,34,66,114,198,126,201,21,55,181,
    22,249,254,210,18,120,156,194,26,133,78,50,37,144,101,112,
    43,20,59,92,82,138,73,104,9,147,202,40,5,206,109,7,
    108,152,67,109,178,194,253,218,179,212,124,189,200,212,65,118,
    120,52,244,227,227,208,127,76,97,146,211,178,129,9,54,203,
    232,208,152,213,129,2,69,188,78,13,126,189,111,116,57,91,
    100,218,248,46,46,80,232,192,65,18,166,1,231,138,47,250,
    178,25,203,248,24,143,89,253,104,212,236,14,253,30,251,201,
    158,232,248,185,209,81,177,163,175,110,194,92,191,28,166,205,
    32,77,48,187,159,6,42,205,154,161,196,227,135,12,53,200,
    231,195,149,43,58,63,235,229,92,188,157,188,32,114,209,62,
    245,240,44,25,97,201,234,25,123,232,83,78,145,211,185,74,
    213,17,131,251,34,30,33,212,88,103,175,135,212,124,155,154,
    187,240,6,82,127,27,23,248,53,173,68,166,171,96,130,169,
    10,22,213,204,57,162,47,242,87,35,246,233,55,137,88,125,
    245,49,137,219,138,185,51,89,2,185,76,231,86,183,70,23,
    0,212,179,66,193,188,244,223,6,51,71,193,162,241,47,255,
    167,49,236,60,120,147,42,56,92,43,254,167,248,21,179,250,
    213,117,252,14,132,169,168,103,149,227,3,251,214,43,64,242,
    130,76,250,74,106,127,221,92,172,178,156,29,244,250,189,194,
    107,70,163,226,96,241,65,161,213,37,215,57,227,205,153,106,
    151,157,40,158,97,81,130,21,241,57,43,238,89,186,40,158,
    66,179,84,232,79,151,7,137,124,225,205,219,64,215,188,36,
    140,63,26,201,36,156,214,179,60,178,72,247,83,242,233,195,
    180,196,192,226,117,19,159,87,195,144,116,154,81,145,221,87,
    46,2,111,193,142,100,212,198,198,133,45,58,88,76,19,173,
    67,14,212,169,181,200,170,206,15,192,100,218,2,151,161,28,
    74,37,175,184,70,209,119,147,147,94,40,113,239,73,199,120,
    6,225,98,30,223,135,158,183,240,252,252,161,54,188,62,62,
    81,126,174,96,134,174,150,170,130,183,191,43,119,151,90,48,
    186,47,208,37,235,56,119,56,174,215,10,205,249,146,205,236,
    63,12,117,58,110,29,250,177,190,56,225,219,0,231,14,53,
    239,24,11,50,82,245,81,134,15,10,250,128,134,176,230,35,
    26,111,197,206,61,234,39,12,77,21,224,93,68,191,126,33,
    179,56,66,245,212,122,209,245,105,162,178,143,83,108,210,33,
    95,39,233,222,206,56,87,50,230,107,74,153,156,198,222,83,
    25,167,217,248,105,26,74,118,217,147,99,244,136,31,40,221,
    237,157,73,42,12,212,102,241,249,252,56,95,239,100,126,210,
    211,247,158,122,10,14,233,59,171,153,190,78,100,250,166,34,
    31,13,125,213,77,179,120,134,251,71,126,30,5,71,81,250,
    137,60,139,130,89,158,211,190,210,36,223,241,174,58,151,253,
    24,82,153,236,69,168,96,198,150,162,145,73,62,32,31,171,
    91,175,230,202,217,111,22,13,60,93,168,234,115,247,99,242,
    120,126,132,13,221,62,85,215,170,162,98,209,53,167,45,106,
    162,46,74,98,181,94,181,171,149,106,217,70,112,82,207,134,
    168,217,213,218,170,120,221,255,46,194,183,102,237,214,170,226,
    95,203,246,109,152,
};

EmbeddedPython embedded_m5_internal_param_Uart8250(
    "m5/internal/param_Uart8250.py",
    "/nfs/ug/homes-0/m/moham356/ece552/Lab6/gem5/build/ALPHA/python/m5/internal/param_Uart8250.py",
    "m5.internal.param_Uart8250",
    data_m5_internal_param_Uart8250,
    2181,
    6520);

} // anonymous namespace
