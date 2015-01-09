#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_PciDevice[] = {
    120,156,197,90,219,122,219,198,17,30,128,20,109,210,146,37,
    89,242,65,182,108,51,73,221,40,105,98,234,232,36,141,235,
    198,145,115,80,42,203,10,233,198,14,115,64,32,96,69,65,
    38,1,22,0,101,51,149,122,136,220,36,61,166,205,77,31,
    160,95,47,122,211,167,232,43,245,186,157,153,197,66,160,12,
    80,234,215,86,142,197,201,226,199,96,176,59,243,207,236,46,
    0,11,162,255,6,240,247,70,25,32,248,187,6,96,227,159,
    6,77,128,150,6,117,13,52,161,129,61,6,15,6,192,159,
    7,123,0,30,3,212,117,16,58,236,98,35,7,31,233,224,
    14,242,53,5,104,230,24,209,160,91,2,145,135,250,0,220,
    115,71,33,47,10,240,160,4,254,103,160,105,154,171,193,125,
    251,24,216,199,225,49,90,199,70,145,13,30,7,187,196,141,
    34,216,39,184,81,130,238,8,136,19,80,71,227,199,160,62,
    132,166,94,68,83,39,217,212,63,200,148,141,103,198,193,30,
    34,117,236,203,135,164,153,39,77,190,199,73,182,50,172,122,
    54,2,245,17,213,30,133,250,168,106,159,130,250,41,213,30,
    131,250,152,106,143,67,125,92,181,79,67,253,180,106,159,129,
    250,25,213,62,11,245,179,170,125,14,234,231,84,123,2,234,
    19,170,125,30,234,231,193,30,6,49,1,155,23,96,29,93,
    57,18,247,119,18,68,14,54,47,66,253,34,8,252,155,132,
    93,244,182,61,202,186,151,88,247,84,172,123,153,117,203,80,
    47,131,192,191,203,82,183,0,181,169,211,24,59,231,95,248,
    223,20,198,14,194,65,20,91,194,15,28,207,53,28,119,221,
    115,116,58,95,32,65,145,182,72,28,139,66,190,72,33,255,
    27,112,188,109,61,10,249,14,160,97,141,250,223,212,97,135,
    27,59,58,116,167,96,91,131,205,60,216,57,216,198,219,12,
    80,7,26,26,236,234,240,113,142,20,118,80,230,49,72,151,
    32,31,202,120,111,114,144,164,165,99,176,51,0,219,3,80,
    187,191,173,19,240,160,8,254,95,225,243,73,54,122,156,141,
    234,176,141,50,15,187,121,216,41,192,61,84,66,104,179,72,
    195,215,238,111,227,72,17,169,77,229,177,183,43,137,225,210,
    80,108,199,119,205,150,8,71,176,109,180,77,223,108,25,171,
    150,115,75,108,57,150,152,42,41,45,47,184,218,54,195,141,
    42,95,150,35,127,180,218,33,155,243,92,17,158,192,198,186,
    227,218,70,203,179,59,77,17,30,39,91,198,186,211,20,134,
    193,39,151,90,109,207,15,223,242,125,207,175,146,75,25,108,
    122,102,124,5,57,212,106,122,129,152,162,187,241,109,170,100,
    62,36,237,245,54,91,164,14,112,87,233,98,91,4,150,239,
    180,67,140,148,180,72,218,100,109,138,98,196,34,248,4,69,
    197,93,15,42,157,70,101,195,107,137,224,229,233,74,171,210,
    242,54,204,214,220,194,181,138,176,196,194,194,108,101,217,92,
    187,86,105,136,214,66,101,173,227,52,237,202,205,229,213,119,
    111,86,218,221,112,195,115,43,136,58,110,40,208,69,205,202,
    62,231,92,69,149,83,116,155,135,78,195,112,120,128,198,134,
    104,182,133,79,253,11,206,83,23,180,17,109,80,43,104,57,
    109,74,27,194,214,0,254,114,218,164,126,66,91,113,104,136,
    22,13,155,216,149,83,124,250,11,112,228,48,240,15,116,240,
    39,137,45,155,248,167,81,120,145,51,53,58,167,243,185,247,
    201,55,18,221,204,17,7,36,184,205,12,67,170,161,230,117,
    10,186,11,76,147,1,216,44,128,164,15,178,78,242,201,239,
    146,68,117,50,163,163,241,60,4,223,244,90,112,71,0,125,
    143,149,1,161,51,120,171,47,152,145,181,41,234,248,10,51,
    35,220,112,2,239,161,203,254,167,54,231,80,13,125,178,218,
    189,179,182,41,172,48,184,140,192,135,94,167,108,153,174,235,
    133,101,211,182,203,102,24,250,206,90,39,20,65,57,244,202,
    87,130,169,34,5,124,84,145,43,182,215,109,43,50,81,224,
    145,76,242,192,118,172,16,15,198,248,128,253,31,136,16,137,
    177,225,217,1,226,100,162,33,194,42,117,50,60,137,226,166,
    186,29,51,112,170,160,248,18,136,230,122,88,98,234,153,65,
    96,240,237,8,103,150,209,213,91,102,179,35,66,210,15,66,
    51,196,187,82,83,222,232,72,121,118,142,70,170,6,74,206,
    51,92,207,181,187,216,79,199,122,142,186,112,142,217,54,8,
    196,183,211,200,181,99,40,11,48,132,220,27,209,45,26,82,
    62,98,26,179,236,12,57,0,56,242,90,84,59,144,113,187,
    88,97,166,116,46,17,60,54,78,194,50,181,232,226,42,17,
    186,122,129,196,36,137,139,106,248,71,229,131,161,253,62,152,
    166,251,234,60,112,43,23,13,49,78,164,149,158,68,154,216,
    75,36,172,136,53,74,8,157,210,102,47,33,114,228,4,255,
    70,196,126,74,53,36,0,158,78,112,158,93,83,165,58,201,
    12,98,186,86,137,131,73,34,54,18,68,172,82,84,152,133,
    213,137,44,55,94,126,122,110,108,72,55,206,209,125,7,35,
    254,12,49,111,74,154,69,193,215,35,167,178,67,111,97,163,
    123,150,28,154,116,229,89,156,227,238,185,67,60,89,241,132,
    199,203,7,89,65,164,135,101,35,79,76,91,207,193,153,104,
    18,10,40,225,219,190,247,168,91,246,214,203,33,168,62,92,
    191,18,92,189,18,188,142,37,161,124,131,139,140,44,10,50,
    237,125,209,246,49,189,139,124,32,83,214,224,244,53,162,105,
    4,93,78,19,58,71,138,29,205,21,42,8,125,42,76,71,
    234,229,82,236,101,234,244,107,116,211,18,187,56,7,103,241,
    87,210,184,103,134,199,21,146,151,21,124,22,127,111,146,179,
    105,188,2,104,1,89,173,201,126,243,144,104,112,213,231,123,
    24,115,68,3,170,190,72,93,83,9,87,128,152,31,244,203,
    81,151,41,7,190,2,94,120,105,240,37,16,23,48,228,81,
    214,112,126,210,143,66,58,70,234,159,2,23,159,148,137,78,
    151,217,167,71,229,9,147,51,120,133,85,229,188,247,30,124,
    157,168,92,187,57,208,104,142,202,69,75,171,228,28,149,143,
    243,149,73,116,168,121,40,223,155,216,20,164,13,51,32,53,
    153,194,185,56,133,247,138,96,188,38,194,186,116,84,252,58,
    46,111,103,80,207,222,217,99,23,77,0,23,180,49,61,193,
    153,151,72,188,28,211,69,83,216,17,116,242,242,254,138,157,
    152,181,12,89,37,223,166,158,228,185,239,195,5,206,236,216,
    66,156,21,3,42,43,102,227,172,16,92,183,31,243,218,155,
    164,78,225,223,213,53,220,64,225,90,133,246,46,121,16,3,
    80,47,80,254,240,218,82,139,210,75,83,245,140,234,96,207,
    164,192,174,89,145,78,139,25,32,131,75,226,209,145,214,15,
    138,239,245,166,217,90,179,205,27,31,211,45,233,190,150,74,
    56,93,13,98,36,57,8,74,22,45,107,28,124,56,173,6,
    179,117,164,181,99,6,239,16,15,130,51,197,246,44,46,24,
    119,55,68,185,37,90,107,184,229,218,112,218,229,245,166,217,
    224,72,229,162,65,222,81,131,12,57,212,251,39,99,94,200,
    172,120,101,203,115,177,200,119,172,208,243,203,182,192,157,136,
    176,37,209,123,115,150,215,118,166,223,8,120,25,247,224,33,
    53,143,60,170,6,110,44,29,92,189,126,162,28,34,119,60,
    113,105,231,5,171,204,26,156,31,113,55,17,118,101,13,187,
    70,226,5,18,87,224,105,204,0,21,188,195,71,116,43,114,
    94,1,203,76,81,11,135,147,9,187,74,215,4,79,166,237,
    63,115,135,72,91,249,196,3,21,68,1,54,143,177,60,78,
    181,191,94,84,96,137,229,9,6,7,21,56,196,242,36,131,
    195,10,28,97,57,202,224,41,5,142,177,28,103,240,180,2,
    207,176,60,203,224,57,5,78,176,60,207,224,5,5,78,178,
    188,200,224,37,5,94,102,89,102,240,25,5,62,203,242,57,
    6,191,163,192,43,44,191,203,224,243,10,156,98,249,2,131,
    47,42,240,123,44,95,98,240,101,5,94,101,89,97,112,90,
    129,51,44,103,25,156,83,224,60,203,5,6,175,41,240,21,
    150,175,50,248,154,2,191,207,242,117,6,175,43,240,7,44,
    111,48,248,67,5,190,193,242,38,131,111,42,112,145,229,45,
    6,223,82,224,219,44,223,97,240,93,5,46,177,124,143,193,
    31,41,112,153,229,109,6,87,20,120,135,229,42,131,239,43,
    176,202,178,198,224,93,5,254,152,229,7,12,222,83,224,125,
    150,31,50,88,87,224,71,44,63,102,240,19,5,126,202,210,
    96,240,51,5,154,44,215,24,180,20,104,179,20,12,174,43,
    176,193,114,131,65,71,129,155,44,31,48,216,84,96,139,165,
    203,160,167,192,54,203,159,48,232,43,48,96,25,50,216,81,
    224,22,203,135,12,62,82,96,151,229,231,12,254,84,129,219,
    44,119,24,252,153,2,127,206,242,23,12,254,82,129,95,176,
    220,101,240,177,2,127,197,242,75,6,191,82,224,215,44,127,
    205,224,111,20,248,91,150,191,99,240,247,106,182,253,3,131,
    223,64,253,143,234,33,231,159,104,230,45,252,183,51,47,207,
    88,71,62,87,89,255,211,9,183,58,251,84,199,80,229,253,
    93,191,201,86,135,196,190,249,21,57,217,202,200,224,26,190,
    59,158,216,203,241,120,181,123,184,224,198,253,222,54,239,4,
    13,93,110,249,246,194,200,75,104,126,36,71,55,117,197,67,
    99,223,12,33,183,116,196,13,179,221,22,174,189,183,93,227,
    51,71,234,42,154,84,191,133,189,245,51,238,205,198,241,247,
    36,105,105,84,137,65,50,57,7,98,154,158,127,26,33,254,
    115,188,130,248,182,103,5,81,165,24,202,53,67,188,92,144,
    1,153,124,114,186,54,62,192,8,120,254,210,45,122,28,208,
    95,1,23,241,188,130,81,64,88,78,209,94,162,78,251,157,
    118,184,234,184,108,242,64,37,50,75,91,255,36,24,94,74,
    185,234,93,97,218,194,191,219,109,11,54,124,128,10,153,165,
    160,238,65,225,133,148,43,218,150,99,216,98,139,45,246,59,
    79,230,104,161,22,29,167,122,234,205,155,213,133,154,243,185,
    200,116,101,172,160,92,169,0,222,42,237,215,174,117,214,130,
    110,16,138,86,20,156,131,116,200,40,61,122,78,96,169,78,
    90,52,125,123,173,19,44,46,213,50,253,152,80,81,126,220,
    131,82,67,122,27,87,181,173,78,235,29,223,116,195,204,184,
    247,40,169,184,39,193,84,175,85,241,128,223,200,100,185,53,
    86,80,110,85,64,120,62,205,101,184,21,237,4,108,172,207,
    105,50,69,37,74,30,134,207,166,141,198,124,68,29,95,54,
    67,225,90,93,54,120,8,53,50,76,75,252,94,56,213,93,
    200,142,217,101,209,48,173,238,210,157,76,159,246,40,41,159,
    38,193,44,38,78,31,68,213,233,253,84,157,206,164,106,219,
    241,140,102,194,15,7,233,40,170,38,176,212,193,69,222,185,
    235,180,132,159,233,129,30,37,229,129,36,152,229,183,153,195,
    56,119,38,205,185,51,125,157,219,198,33,173,123,126,43,211,
    185,177,130,114,174,2,178,58,49,127,152,158,206,167,245,52,
    6,195,43,253,202,71,207,44,112,56,77,186,201,104,178,220,
    196,243,66,6,159,230,14,34,220,220,126,194,49,144,53,220,
    133,195,248,100,33,205,39,49,152,117,213,244,97,76,79,167,
    153,142,193,212,201,100,209,107,181,76,215,206,156,108,212,121,
    53,217,68,199,169,254,146,7,125,230,237,88,65,57,84,1,
    169,101,111,213,247,26,75,111,103,86,197,232,180,170,138,242,
    48,213,51,72,135,69,122,52,191,232,217,34,211,125,61,74,
    202,125,73,48,61,109,112,238,93,239,184,86,118,94,41,133,
    56,175,34,32,139,113,243,7,81,114,126,63,37,25,224,247,
    113,105,181,130,77,101,158,36,51,249,168,128,100,105,77,247,
    51,49,157,52,49,157,165,53,215,207,196,92,210,196,92,150,
    214,108,63,19,179,73,19,179,89,90,11,253,76,44,36,77,
    44,100,105,205,247,51,49,159,52,49,31,94,76,75,167,30,
    30,246,215,32,99,244,248,121,143,129,169,247,93,170,221,205,
    238,20,157,140,59,133,7,225,51,169,75,43,107,67,44,59,
    174,136,169,119,176,22,25,29,226,53,88,2,205,162,236,236,
    65,156,158,221,207,233,217,204,50,251,214,163,182,233,210,74,
    170,122,231,118,102,50,247,40,169,100,78,130,89,21,116,238,
    48,101,118,46,173,204,198,96,234,138,203,242,220,117,167,209,
    179,32,57,132,154,90,152,245,194,153,155,130,181,104,13,217,
    239,124,114,211,128,199,169,145,142,183,61,20,215,76,62,244,
    106,41,62,244,160,89,225,158,57,136,15,51,251,249,192,64,
    56,157,54,48,250,200,37,114,16,254,207,21,22,125,128,131,
    205,78,180,234,255,143,47,10,162,126,245,83,226,93,122,72,
    207,250,109,209,20,161,216,255,64,65,126,187,36,159,153,219,
    34,8,125,175,107,24,242,5,43,30,55,13,227,232,31,150,
    191,138,119,88,163,91,217,32,31,150,23,180,211,255,183,127,
    197,124,81,227,183,28,251,62,87,147,35,38,58,201,215,147,
    221,160,74,72,149,158,218,203,7,2,60,71,170,183,12,252,
    232,135,106,224,138,217,146,95,202,240,215,31,85,50,80,165,
    175,76,248,113,2,207,255,242,189,53,191,20,150,175,227,93,
    241,144,95,200,243,27,151,234,85,136,222,99,68,158,81,171,
    219,209,24,66,230,250,139,184,65,243,189,38,231,180,68,107,
    188,142,228,183,10,194,237,180,140,219,162,229,249,221,219,84,
    141,233,233,198,205,53,140,173,105,133,18,54,182,4,189,240,
    9,199,227,203,123,207,243,7,60,184,169,68,90,14,199,42,
    120,74,126,149,148,192,106,206,147,216,173,150,41,131,153,192,
    86,29,47,194,104,200,177,6,191,24,97,118,198,12,96,42,
    250,162,225,224,112,124,182,16,107,71,143,192,136,31,169,249,
    152,188,242,200,105,43,95,59,202,111,41,110,208,32,131,101,
    20,244,77,81,113,184,168,21,116,250,122,45,167,149,180,33,
    45,175,13,14,21,115,197,66,113,32,135,212,38,100,76,43,
    229,138,165,65,45,237,223,4,18,180,164,79,92,43,106,255,
    6,112,27,228,8,
};

EmbeddedPython embedded_m5_internal_param_PciDevice(
    "m5/internal/param_PciDevice.py",
    "/nfs/ug/homes-0/m/moham356/ece552/Lab6/gem5/build/ALPHA/python/m5/internal/param_PciDevice.py",
    "m5.internal.param_PciDevice",
    data_m5_internal_param_PciDevice,
    3189,
    11061);

} // anonymous namespace
