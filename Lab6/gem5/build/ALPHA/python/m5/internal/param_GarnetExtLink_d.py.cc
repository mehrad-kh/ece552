#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_GarnetExtLink_d[] = {
    120,156,205,88,109,111,219,200,17,158,37,41,217,146,165,88,
    126,143,19,95,172,246,144,158,122,232,69,105,174,201,245,37,
    8,154,75,175,215,30,2,95,74,21,72,142,119,40,75,147,
    43,137,50,69,10,228,58,142,10,251,75,29,180,253,214,255,
    208,162,31,250,63,250,191,218,153,89,146,150,156,228,16,160,
    69,212,88,218,172,134,203,217,121,121,230,101,215,135,252,95,
    5,191,63,111,3,100,127,19,0,1,126,4,68,0,99,1,
    142,0,33,5,4,27,112,84,129,244,71,16,84,224,37,128,
    99,128,52,224,28,39,38,124,109,64,220,224,119,170,16,153,
    76,17,48,173,131,180,192,169,192,211,120,13,44,89,133,163,
    58,164,191,7,33,68,44,224,89,176,4,193,50,188,68,238,
    56,169,49,195,101,8,234,60,169,65,176,194,147,58,76,91,
    32,87,192,65,230,75,224,52,145,213,135,200,234,10,179,250,
    23,177,10,240,201,38,4,77,90,142,178,124,69,43,45,90,
    201,123,92,97,46,171,133,100,45,112,90,197,124,13,156,181,
    98,190,14,206,122,49,223,0,103,163,152,111,130,179,89,204,
    183,192,217,42,230,219,224,108,23,243,29,112,118,138,249,85,
    112,174,22,243,93,112,118,33,88,5,185,5,163,107,208,71,
    243,181,74,25,175,131,52,97,180,7,206,30,72,252,92,135,
    115,180,112,176,198,107,223,227,181,235,229,218,27,188,118,31,
    156,125,144,248,185,161,215,86,161,215,217,66,127,133,255,198,
    127,29,244,23,168,6,14,207,101,154,133,73,236,134,113,63,
    9,13,122,94,165,129,188,235,211,176,148,187,249,17,185,249,
    159,192,62,14,140,220,205,103,128,140,5,201,31,25,112,198,
    147,51,3,166,29,56,21,48,178,32,48,225,20,183,169,144,
    0,3,1,231,6,124,99,210,130,51,28,45,116,204,13,176,
    148,246,241,136,29,163,57,45,193,89,5,78,43,208,123,118,
    106,16,225,168,6,233,63,224,15,123,204,116,153,153,26,112,
    138,163,5,231,22,156,85,225,41,46,66,210,168,70,234,139,
    103,167,168,41,82,122,29,11,165,61,152,81,151,84,9,194,
    52,246,198,82,109,227,220,157,120,169,55,118,63,247,210,88,
    170,207,94,168,199,97,124,228,6,157,122,177,54,201,110,77,
    60,53,180,249,101,147,172,50,158,40,102,154,224,11,43,56,
    233,135,113,224,142,147,224,56,146,106,153,56,186,253,48,146,
    174,203,15,127,61,158,36,169,250,44,77,147,212,38,195,50,
    49,74,188,242,13,50,171,31,37,153,236,208,110,188,141,77,
    236,21,173,238,79,152,35,9,192,2,211,203,129,204,252,52,
    156,40,244,151,230,72,171,137,91,135,60,197,67,70,78,235,
    198,253,172,123,60,232,14,147,177,204,62,186,221,29,119,199,
    201,208,27,127,124,247,94,87,250,242,238,221,59,221,199,222,
    225,189,238,64,142,239,118,15,143,195,40,232,62,124,252,228,
    87,15,187,147,169,26,38,113,23,169,97,172,36,26,42,234,
    190,214,68,183,112,225,58,109,118,18,14,220,144,213,116,135,
    50,154,200,148,164,204,174,145,32,162,37,26,162,42,76,209,
    17,77,156,85,240,107,138,61,99,69,28,132,164,168,79,202,
    19,210,204,2,91,127,7,246,34,130,224,200,128,116,143,144,
    51,194,143,32,87,35,126,122,244,204,224,103,191,33,11,105,
    234,200,36,60,104,226,41,163,13,97,135,43,239,19,0,98,
    96,200,84,96,84,5,13,37,68,160,198,86,58,165,17,151,
    19,27,3,153,91,144,253,117,158,67,220,2,244,0,102,6,
    36,109,227,86,127,100,116,246,58,36,248,1,227,67,13,195,
    44,57,137,217,11,52,231,120,234,161,77,158,76,191,60,28,
    73,95,101,251,72,248,42,57,110,251,94,28,39,170,237,5,
    65,219,83,42,13,15,143,149,204,218,42,105,223,204,58,53,
    114,251,90,1,177,146,223,116,82,64,138,220,143,144,210,63,
    130,208,87,248,99,131,127,176,253,51,169,16,30,195,36,200,
    144,78,44,6,82,217,36,164,186,130,195,195,98,59,198,97,
    167,90,160,38,147,81,95,213,25,128,94,150,185,188,29,209,
    25,107,244,246,115,47,58,150,138,214,103,202,83,184,43,77,
    245,70,11,64,219,85,210,183,80,151,76,232,198,73,28,76,
    81,218,208,127,159,4,185,202,152,107,0,161,110,11,17,183,
    132,99,21,154,136,192,150,225,147,98,86,142,55,198,26,69,
    191,2,246,191,200,179,9,226,238,28,115,78,199,224,164,193,
    26,114,64,182,105,70,47,219,4,107,251,58,13,123,52,188,
    87,24,225,221,90,162,121,217,18,183,105,119,131,213,247,205,
    92,209,50,168,14,230,130,106,247,34,168,48,83,246,40,56,
    12,10,161,139,224,48,201,20,233,131,60,18,40,236,16,12,
    248,120,6,255,108,32,187,69,138,87,11,232,218,132,199,89,
    80,14,102,64,105,147,111,24,145,246,238,155,140,185,191,104,
    99,14,180,49,63,166,221,27,57,150,154,140,161,186,240,9,
    8,70,110,90,54,235,47,112,50,221,33,179,206,26,116,7,
    43,224,211,184,201,165,140,203,33,55,20,58,167,104,59,235,
    137,69,168,235,155,176,157,151,168,140,82,192,36,77,94,76,
    219,73,191,173,160,144,225,254,205,236,214,205,236,103,152,36,
    218,15,56,237,232,52,161,19,65,42,39,41,6,124,141,127,
    232,32,118,57,160,221,188,188,160,225,169,220,179,191,216,220,
    156,179,50,149,82,170,90,128,173,235,165,173,73,244,159,208,
    214,117,54,180,9,59,248,173,11,150,207,77,56,115,114,235,
    193,79,241,251,41,153,156,180,150,64,141,165,221,211,210,179,
    98,164,162,253,193,28,122,222,169,90,246,135,36,96,17,130,
    85,40,177,66,95,147,4,167,168,248,51,112,139,38,224,79,
    64,184,64,247,231,113,196,17,75,95,114,239,6,45,255,29,
    112,82,122,77,25,52,116,60,26,121,218,194,112,205,62,225,
    165,186,42,126,1,127,153,201,104,231,38,8,170,96,102,222,
    132,205,86,48,171,140,96,6,212,91,85,41,107,62,212,201,
    85,67,47,163,101,58,168,205,50,168,47,146,99,217,55,97,
    166,122,183,88,91,214,155,186,36,223,231,23,72,163,242,112,
    93,108,24,51,248,249,1,13,31,149,208,17,5,237,157,137,
    186,127,57,159,207,84,54,87,231,208,95,146,60,22,107,176,
    90,85,171,248,255,37,62,101,180,84,138,104,185,83,70,139,
    228,220,254,146,251,118,26,13,2,196,185,33,240,192,133,189,
    13,157,117,44,144,21,112,170,20,87,220,145,138,60,236,68,
    145,237,40,75,206,21,14,54,211,129,54,96,137,9,237,110,
    26,94,44,32,187,144,199,239,71,222,248,48,240,30,124,77,
    27,211,238,126,17,136,70,161,74,107,86,21,10,34,241,38,
    109,248,231,237,66,165,231,11,200,44,63,196,125,74,85,56,
    142,130,196,231,116,242,219,161,108,143,229,248,16,143,110,195,
    112,210,238,71,222,128,189,102,230,170,126,89,168,170,216,237,
    151,139,55,183,63,7,73,219,79,98,44,7,199,190,74,210,
    118,32,241,44,35,3,29,0,243,17,205,125,161,151,14,50,
    110,1,143,78,104,186,32,15,187,120,76,13,177,255,253,166,
    48,139,62,57,149,69,128,91,94,29,77,88,79,241,60,162,
    166,58,207,221,163,225,251,52,220,132,197,213,138,46,238,227,
    208,134,100,200,42,166,162,154,80,91,175,134,243,19,122,63,
    123,53,168,79,222,38,168,245,253,73,30,218,85,90,41,151,
    232,216,76,99,141,138,134,83,47,136,43,60,54,152,216,44,
    174,104,174,48,113,149,175,61,170,76,89,163,204,176,244,223,
    102,6,142,165,5,69,209,225,255,52,33,216,119,254,15,52,
    177,185,83,253,182,100,32,102,213,108,234,100,48,18,69,91,
    63,171,35,95,37,236,189,9,135,174,159,74,79,73,237,196,
    107,11,81,157,19,143,22,35,40,93,89,232,87,158,117,62,
    41,117,60,231,46,107,186,57,211,121,179,103,197,83,108,137,
    176,59,63,101,51,184,134,110,208,47,96,107,149,214,160,12,
    24,203,147,203,178,104,139,232,54,156,100,242,38,19,25,7,
    23,45,54,63,89,0,52,40,189,13,224,162,207,193,126,122,
    19,191,175,6,44,105,56,163,48,251,180,82,134,232,98,188,
    203,192,142,10,191,118,232,98,233,34,163,219,228,85,157,195,
    203,244,109,255,180,244,211,7,111,68,45,146,78,146,244,200,
    141,144,152,209,241,238,173,215,98,31,198,7,195,57,170,250,
    222,183,197,71,128,69,233,98,163,183,92,74,251,52,52,176,
    75,34,123,146,99,49,144,145,84,242,245,0,84,100,143,252,
    164,29,72,172,225,201,20,15,127,124,124,194,223,145,235,46,
    170,192,253,152,98,2,242,180,74,5,174,138,37,110,11,255,
    106,86,77,112,71,113,233,138,89,203,216,134,226,160,48,205,
    108,206,110,171,165,135,249,18,180,168,229,28,226,116,228,61,
    240,198,250,70,139,239,103,236,239,208,240,126,1,18,14,77,
    125,142,228,227,153,62,36,99,56,243,49,153,187,27,251,22,
    209,55,137,147,246,178,214,193,125,46,169,27,226,155,12,173,
    228,220,99,238,189,53,189,23,142,245,29,31,175,125,196,46,
    156,231,177,94,174,157,125,58,67,254,212,203,66,63,55,31,
    139,162,201,246,241,225,244,81,18,163,83,163,8,149,110,205,
    61,232,77,51,37,199,106,109,158,137,157,224,73,45,157,145,
    142,169,204,151,0,54,187,17,247,32,175,75,246,140,166,84,
    14,194,140,88,173,95,122,45,79,124,228,95,245,221,55,194,
    123,150,197,130,32,168,15,2,250,6,228,1,249,61,251,2,
    7,186,21,172,173,214,68,213,160,91,104,83,212,69,83,88,
    162,209,172,153,181,106,173,98,34,76,137,178,33,234,102,173,
    222,16,175,254,237,34,124,235,198,110,163,38,254,3,185,11,
    22,247,
};

EmbeddedPython embedded_m5_internal_param_GarnetExtLink_d(
    "m5/internal/param_GarnetExtLink_d.py",
    "/nfs/ug/homes-0/m/moham356/ece552/Lab6/gem5/build/ALPHA/python/m5/internal/param_GarnetExtLink_d.py",
    "m5.internal.param_GarnetExtLink_d",
    data_m5_internal_param_GarnetExtLink_d,
    2210,
    6907);

} // anonymous namespace