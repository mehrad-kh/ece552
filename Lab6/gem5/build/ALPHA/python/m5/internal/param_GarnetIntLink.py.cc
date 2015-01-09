#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_GarnetIntLink[] = {
    120,156,197,88,109,115,219,198,17,222,3,64,72,164,68,139,
    122,179,44,217,173,217,201,104,194,102,18,211,117,106,167,47,
    30,79,157,190,164,233,120,20,23,204,84,14,211,6,129,128,
    35,9,138,4,56,192,201,10,59,210,151,202,211,246,91,127,
    68,167,31,250,63,250,191,218,221,61,0,2,101,57,227,153,
    116,72,137,184,57,28,14,123,251,242,60,123,123,240,33,251,
    171,224,245,139,38,64,154,8,128,0,127,2,70,0,99,1,
    93,1,66,10,8,54,225,184,2,201,143,33,168,192,43,128,
    174,1,210,128,11,236,152,240,165,1,209,42,191,99,195,200,
    228,17,1,211,26,72,11,186,21,56,140,214,193,146,54,28,
    215,32,249,26,132,16,145,128,23,193,18,4,203,240,10,165,
    99,167,202,2,151,33,168,113,167,10,193,10,119,106,48,109,
    128,92,129,46,10,95,130,110,29,69,189,135,162,110,176,168,
    255,144,168,0,159,108,65,80,167,233,168,203,23,52,211,162,
    153,188,198,13,150,178,150,107,214,128,110,35,239,175,67,119,
    61,239,111,64,119,35,239,111,66,119,51,239,111,65,119,43,
    239,111,67,119,27,130,53,144,155,48,188,9,61,116,71,163,
    88,115,7,164,9,195,91,208,189,5,18,127,59,112,129,30,
    11,214,121,238,46,207,221,40,230,238,241,220,219,208,189,13,
    18,127,123,122,174,13,157,214,54,250,63,252,47,254,181,208,
    255,160,86,177,121,41,147,52,140,35,55,140,122,113,104,208,
    115,155,26,138,150,79,205,82,22,182,95,82,216,254,13,28,
    179,192,200,194,118,14,40,88,144,254,35,3,206,185,115,110,
    192,180,5,103,2,134,22,4,38,156,225,50,21,82,160,47,
    224,194,128,63,154,52,225,28,91,11,29,253,125,176,148,142,
    217,144,29,173,37,45,193,121,5,206,42,208,121,113,102,208,
    192,113,21,146,127,193,159,239,176,208,101,22,106,192,25,182,
    22,92,88,112,110,195,33,78,194,161,97,149,204,23,47,206,
    208,82,28,233,180,44,212,246,160,100,46,153,18,132,73,228,
    141,165,218,194,190,59,241,18,111,236,126,226,37,145,84,159,
    70,234,89,24,29,183,106,249,204,56,189,55,241,212,192,225,
    87,77,242,201,120,162,88,100,140,211,87,176,211,11,163,192,
    29,199,193,201,72,170,101,146,231,246,194,145,116,93,126,248,
    233,120,18,39,234,215,73,18,39,14,185,149,7,71,177,87,
    188,65,78,245,71,113,42,91,180,26,47,227,144,120,69,179,
    123,19,150,72,10,176,186,244,114,32,83,63,9,39,10,163,
    165,37,210,108,146,214,162,56,113,147,122,216,180,163,94,218,
    62,233,183,7,241,88,166,31,220,111,143,219,227,120,224,141,
    63,124,248,168,45,125,249,240,225,131,246,51,239,232,81,187,
    47,199,15,219,71,39,225,40,104,63,125,246,252,183,79,219,
    147,169,26,196,81,27,71,195,72,73,116,211,168,125,141,131,
    238,225,180,13,90,234,52,236,187,33,27,233,14,228,104,34,
    19,210,49,221,35,53,68,67,172,10,91,152,162,37,234,216,
    171,224,101,138,59,198,138,56,8,201,76,159,76,39,148,153,
    57,174,254,9,28,65,4,192,177,1,201,29,66,205,16,127,
    130,194,140,216,233,208,51,131,159,253,158,252,163,71,135,38,
    97,65,15,158,49,210,16,114,56,243,49,5,63,2,134,75,
    5,134,54,104,24,33,250,52,174,146,41,181,56,157,196,24,
    40,220,130,244,31,179,18,162,6,160,255,145,229,56,116,19,
    151,250,11,35,179,211,34,197,15,24,29,106,16,166,241,105,
    196,49,160,62,115,169,131,62,121,62,253,236,104,40,125,149,
    222,197,129,47,226,147,166,239,69,81,172,154,94,16,52,61,
    165,146,240,232,68,201,180,169,226,230,126,218,170,82,208,215,
    115,128,21,242,166,147,28,80,20,124,4,148,190,9,66,95,
    225,205,38,223,176,255,83,169,16,28,131,56,72,113,156,68,
    244,165,114,72,73,117,3,155,167,249,114,140,194,150,157,99,
    38,149,163,158,170,49,252,188,52,117,121,57,26,103,164,209,
    219,47,189,209,137,84,52,63,85,158,194,85,169,171,23,154,
    59,214,110,145,181,185,177,228,64,55,138,163,96,138,186,134,
    254,59,164,198,45,70,220,42,16,230,182,17,111,75,216,218,
    80,71,252,53,12,159,204,178,50,180,49,210,110,146,19,128,
    163,47,178,60,130,168,187,192,108,211,50,56,93,176,125,76,
    198,38,245,232,101,135,64,237,220,166,230,14,53,223,203,93,
    48,79,63,212,175,250,225,62,173,109,176,241,190,153,153,89,
    16,234,96,134,80,187,151,132,194,12,217,33,98,24,68,159,
    75,98,152,228,136,228,73,198,2,162,28,2,1,31,151,176,
    207,238,113,26,100,182,157,195,214,33,44,150,1,217,47,1,
    210,161,200,48,26,157,221,55,185,242,238,98,93,217,215,174,
    252,144,214,94,205,112,84,103,252,212,132,79,32,48,50,199,
    178,83,127,133,157,233,14,57,181,236,206,29,220,247,14,163,
    58,111,96,188,9,114,89,160,179,137,246,178,238,88,132,184,
    158,9,55,179,141,41,37,242,79,146,248,155,105,51,238,53,
    21,228,58,60,222,79,239,237,167,63,199,244,208,124,194,9,
    71,39,8,157,2,18,57,73,144,234,85,190,209,244,117,153,
    202,110,182,173,160,219,105,147,231,104,177,179,57,91,165,42,
    161,36,53,119,79,215,10,79,147,226,63,165,133,107,236,102,
    19,118,240,170,9,214,206,141,57,99,114,185,193,79,241,250,
    152,28,78,54,75,160,226,208,233,104,221,217,44,50,208,121,
    119,6,57,115,52,202,121,143,212,203,201,103,67,129,19,186,
    76,82,155,248,240,55,224,162,76,192,95,129,48,129,161,207,
    24,196,92,165,139,66,187,73,211,191,2,78,70,215,108,126,
    134,102,162,145,165,43,36,106,250,17,79,213,123,225,239,224,
    239,165,76,118,97,130,160,125,203,204,202,174,242,190,101,21,
    220,101,48,189,213,222,100,205,146,156,2,53,240,82,154,166,
    233,108,22,116,190,76,138,69,173,132,57,106,158,56,91,214,
    75,186,164,221,39,151,40,163,77,225,182,216,52,74,216,121,
    159,154,15,10,216,136,124,108,78,138,222,189,154,197,75,187,
    153,171,51,231,111,72,27,139,245,95,179,57,87,205,72,41,
    88,82,201,89,242,160,96,137,228,124,254,138,107,116,106,13,
    130,194,133,33,240,176,132,181,12,157,83,44,144,21,232,218,
    196,39,174,63,69,70,55,145,231,56,90,111,102,179,96,23,
    29,104,231,21,104,208,129,166,230,155,185,231,20,138,245,227,
    145,55,62,10,188,39,135,180,44,173,237,231,4,52,114,67,
    26,101,67,136,60,226,77,182,240,237,253,220,160,151,115,207,
    39,63,194,85,10,67,152,61,65,236,115,18,249,124,32,155,
    99,57,62,194,35,218,32,156,52,123,35,175,207,17,51,51,
    67,63,203,13,85,28,242,171,155,53,23,59,7,113,211,143,
    35,220,0,78,124,21,39,205,64,226,169,69,6,26,248,179,
    60,230,26,208,75,250,41,151,123,199,167,212,93,72,116,93,
    60,140,134,88,233,190,200,157,162,79,72,69,218,231,226,86,
    179,8,247,79,60,121,168,169,206,109,143,168,249,33,53,251,
    176,168,221,161,141,171,252,129,150,35,39,218,152,126,170,130,
    11,164,153,137,207,233,221,244,117,42,31,189,13,149,245,23,
    143,140,208,54,205,148,75,116,48,166,182,74,155,68,183,150,
    127,63,89,225,193,85,250,88,129,231,127,26,185,65,212,95,
    250,174,212,103,186,44,132,40,95,253,95,25,239,60,88,184,
    29,14,23,159,223,198,118,81,54,178,174,217,62,20,121,157,
    94,182,144,191,10,236,93,15,54,215,79,164,167,164,14,223,
    222,2,204,230,172,162,149,248,186,8,98,110,91,113,112,249,
    168,176,239,130,11,167,233,86,169,144,230,152,138,67,172,114,
    176,216,62,99,23,184,134,174,183,47,225,106,21,158,216,193,
    38,146,167,238,53,222,208,53,53,105,228,77,38,50,10,46,
    235,101,126,50,119,72,80,230,34,242,231,133,11,22,199,91,
    120,189,78,82,178,174,100,44,71,179,82,208,114,17,113,101,
    56,247,243,136,182,214,160,156,170,29,138,167,78,206,69,94,
    118,126,86,68,104,255,13,88,197,129,211,56,57,118,71,56,
    148,210,41,237,45,103,98,81,197,21,211,204,40,59,151,105,
    17,200,145,84,242,58,60,40,82,49,59,195,6,18,119,203,
    120,138,7,43,62,156,224,253,200,117,23,179,153,252,4,87,
    249,19,45,71,59,30,109,38,54,110,39,219,162,106,85,5,
    239,219,87,62,216,106,253,168,28,215,69,248,52,117,56,197,
    172,21,14,231,143,138,249,158,201,92,163,163,228,129,55,214,
    223,136,248,155,135,243,3,106,222,201,99,198,44,209,39,52,
    62,250,232,195,39,242,138,143,159,92,67,56,247,104,156,190,
    10,30,104,199,147,254,238,75,73,21,135,34,62,105,243,74,
    15,213,90,49,218,9,199,250,139,25,11,208,99,31,123,105,
    232,103,126,40,9,224,97,39,198,67,74,82,18,192,163,60,
    147,142,207,229,87,121,51,126,61,33,114,152,19,217,15,83,
    18,180,113,229,165,44,65,144,235,85,243,13,168,43,11,88,
    8,50,116,21,172,143,252,79,40,32,41,157,72,233,19,88,
    117,173,42,108,131,62,184,154,162,38,234,194,18,171,245,170,
    89,181,171,21,19,209,67,35,155,162,102,86,107,171,226,242,
    127,23,241,84,51,118,87,170,226,127,24,244,174,69,
};

EmbeddedPython embedded_m5_internal_param_GarnetIntLink(
    "m5/internal/param_GarnetIntLink.py",
    "/nfs/ug/homes-0/m/moham356/ece552/Lab6/gem5/build/ALPHA/python/m5/internal/param_GarnetIntLink.py",
    "m5.internal.param_GarnetIntLink",
    data_m5_internal_param_GarnetIntLink,
    2126,
    6570);

} // anonymous namespace