#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_TimingSimpleCPU[] = {
    120,156,205,88,235,114,19,201,21,62,61,35,201,150,108,97,
    25,223,48,24,16,203,82,81,182,178,136,176,129,205,133,162,
    2,155,27,41,240,58,178,83,176,147,84,102,199,51,45,105,
    100,205,140,106,166,13,171,148,253,39,166,146,252,203,67,164,
    242,35,239,177,207,145,87,73,206,57,61,61,146,12,108,109,
    85,82,40,70,106,142,122,122,78,159,203,119,46,221,62,228,
    127,101,252,254,180,9,144,253,75,0,4,248,17,48,4,136,
    4,56,2,132,20,16,172,193,81,25,210,31,64,80,134,215,
    0,142,5,210,130,51,36,108,248,157,5,241,50,191,83,129,
    161,205,51,2,198,53,144,37,112,202,240,60,94,133,146,172,
    192,81,13,210,47,65,8,17,11,120,17,44,64,176,8,175,
    145,59,18,85,102,184,8,65,141,137,42,4,75,76,212,96,
    220,0,185,4,14,50,95,0,167,142,172,62,66,86,23,152,
    213,215,196,42,192,39,235,16,212,105,57,202,242,5,173,44,
    209,74,222,227,2,115,89,49,146,53,192,105,24,122,21,156,
    85,67,95,4,231,162,161,215,192,89,51,244,58,56,235,134,
    222,0,103,195,208,155,224,108,26,122,11,156,45,67,95,2,
    231,146,161,183,193,217,54,244,101,112,46,27,250,10,56,87,
    12,189,3,206,142,161,175,130,115,213,208,215,192,185,6,193,
    10,200,6,12,174,67,23,77,223,40,244,107,130,180,97,112,
    3,156,27,32,241,211,132,51,244,78,176,202,107,63,224,181,
    23,139,181,55,121,237,135,224,124,8,18,63,55,245,218,10,
    236,183,54,208,215,225,191,241,175,133,190,6,181,140,195,75,
    153,102,97,18,187,97,220,77,66,139,158,87,104,32,100,248,
    52,44,228,16,249,140,32,242,79,96,124,4,86,14,145,83,
    64,198,130,228,31,90,112,202,196,169,5,227,22,156,8,24,
    148,32,176,225,4,183,41,147,0,61,1,103,22,252,222,166,
    5,167,56,150,208,169,215,160,164,52,62,6,236,84,205,105,
    1,78,203,112,82,134,253,23,39,22,77,28,85,33,253,7,
    252,113,135,153,46,50,83,11,78,112,44,193,89,9,78,43,
    240,28,23,225,212,160,74,234,139,23,39,168,41,206,236,183,
    74,40,237,238,148,186,164,74,16,166,177,23,73,181,137,180,
    59,242,82,47,114,15,194,40,140,123,251,97,52,26,202,207,
    246,126,219,170,153,181,73,118,123,228,169,126,135,95,182,201,
    42,209,72,49,211,36,150,106,9,137,110,24,7,110,148,4,
    199,67,169,22,137,163,219,13,135,210,117,249,225,147,104,148,
    164,234,231,105,154,164,29,50,44,79,14,19,175,120,131,204,
    234,15,147,76,182,104,55,222,166,67,236,21,173,238,142,152,
    35,9,192,2,211,203,129,204,252,52,28,41,244,151,230,72,
    171,137,91,139,60,197,67,70,78,107,199,221,172,125,220,107,
    247,147,72,102,31,223,105,71,237,40,233,123,209,39,247,238,
    183,165,47,239,221,187,219,126,234,29,222,111,247,100,116,175,
    125,120,28,14,131,246,163,167,123,191,122,212,30,141,85,63,
    137,219,56,27,198,74,162,161,134,237,183,154,232,54,46,188,
    72,155,189,10,123,110,200,106,186,125,57,28,201,148,164,204,
    46,147,32,162,33,150,69,69,216,162,37,234,72,149,241,107,
    139,29,107,73,236,134,164,168,79,202,19,210,108,131,173,191,
    3,123,17,65,112,100,65,186,67,200,25,224,71,144,171,17,
    63,251,244,204,226,103,191,33,11,233,217,129,77,120,208,147,
    39,140,54,132,29,174,124,64,0,136,129,33,83,134,65,5,
    52,148,16,129,26,91,233,152,70,92,78,108,44,100,94,130,
    236,111,179,28,226,6,160,7,48,171,224,212,38,110,245,39,
    70,231,126,139,4,223,101,124,168,126,152,37,175,98,246,2,
    209,28,79,251,104,147,189,241,231,135,3,233,171,236,58,78,
    124,145,28,55,125,47,142,19,213,244,130,160,233,41,149,134,
    135,199,74,102,77,149,52,111,101,173,42,185,125,213,64,172,
    224,55,30,25,72,145,251,17,82,250,71,16,250,10,127,172,
    241,15,182,127,38,21,194,163,159,4,25,206,19,139,158,84,
    29,18,82,93,192,225,145,217,142,113,216,170,24,212,100,114,
    216,85,53,6,160,151,101,46,111,71,243,140,53,122,251,165,
    55,60,150,138,214,103,202,83,184,43,145,122,163,57,160,237,
    18,233,107,212,37,19,186,113,18,7,99,148,54,244,111,146,
    32,151,24,115,203,64,168,219,64,196,45,224,88,129,58,34,
    176,97,249,164,88,41,199,27,99,141,162,95,1,251,95,228,
    217,4,113,119,134,57,167,101,113,210,96,13,57,32,155,68,
    209,203,29,130,117,231,10,13,59,52,92,53,70,120,191,150,
    168,159,183,196,29,218,221,98,245,125,59,87,180,8,170,221,
    153,160,218,158,4,21,102,202,125,10,14,139,66,104,18,28,
    54,153,34,125,152,71,2,133,29,130,1,31,79,225,159,13,
    212,105,144,226,21,3,221,14,225,113,26,148,189,41,80,118,
    200,55,140,200,206,246,187,140,121,125,222,198,236,105,99,126,
    66,187,47,231,88,170,51,134,106,194,39,32,88,185,105,217,
    172,63,67,98,188,69,102,157,54,232,22,86,192,231,113,157,
    75,25,151,67,110,70,116,78,209,118,214,68,137,80,215,181,
    97,51,47,81,25,165,128,81,154,124,53,110,38,221,166,2,
    35,195,131,91,217,237,91,217,79,48,73,52,31,114,218,209,
    105,66,39,130,84,142,82,12,248,42,255,208,65,236,114,64,
    187,121,121,65,195,83,185,103,127,177,185,57,103,101,42,165,
    84,53,7,91,215,10,91,147,232,63,162,173,107,108,104,27,
    182,240,91,19,44,159,155,112,230,228,214,131,159,226,247,49,
    153,156,180,150,64,77,105,103,95,75,207,138,145,138,157,239,
    204,160,231,189,170,213,249,136,4,52,33,88,129,2,43,244,
    181,73,112,138,138,191,0,183,104,2,254,12,132,11,116,127,
    30,71,28,177,244,37,247,174,209,242,63,0,39,165,183,148,
    65,75,199,163,149,167,45,12,215,236,83,94,170,171,226,175,
    225,175,83,25,237,204,6,65,21,204,206,155,176,233,10,86,
    42,34,152,1,245,173,170,84,105,54,212,201,85,125,47,163,
    101,58,168,237,34,168,39,201,177,232,155,48,83,189,95,172,
    45,234,77,93,146,239,151,19,164,81,121,184,34,214,172,41,
    252,124,143,134,143,11,232,8,51,247,222,68,189,126,62,159,
    79,85,54,87,231,208,95,144,60,37,214,96,165,162,86,240,
    255,115,124,138,104,41,155,104,185,91,68,139,228,220,254,154,
    251,118,26,45,2,196,153,37,240,176,134,189,13,157,147,74,
    32,203,224,84,40,174,184,35,21,121,216,9,147,237,40,75,
    206,20,14,54,211,174,54,96,129,9,237,110,26,190,154,67,
    118,33,143,63,24,122,209,97,224,61,252,146,54,166,221,125,
    19,136,150,81,165,49,173,10,5,145,120,151,54,252,243,142,
    81,233,229,28,50,203,247,113,159,66,21,142,163,32,241,57,
    157,28,244,101,51,146,209,33,30,221,250,225,168,217,29,122,
    61,246,154,157,171,250,185,81,85,177,219,207,23,111,110,127,
    118,147,166,159,196,88,14,142,125,149,164,205,64,226,89,70,
    6,58,0,102,35,154,251,66,47,237,101,220,2,30,189,34,
    114,78,30,118,241,152,26,98,255,235,25,179,232,147,83,81,
    4,184,229,213,209,132,245,20,207,35,106,172,243,220,125,26,
    190,75,195,45,152,95,173,104,147,116,180,33,25,178,130,169,
    168,42,212,198,155,225,188,71,239,103,111,6,245,179,111,19,
    212,250,238,37,15,237,138,185,180,89,0,185,72,7,100,167,
    70,55,13,52,179,68,241,190,240,223,198,59,71,200,156,98,
    163,247,63,13,243,206,221,255,3,77,58,220,127,126,83,136,
    139,105,53,235,58,196,7,194,52,235,211,58,242,5,193,206,
    187,208,229,250,169,244,148,212,78,188,60,23,213,57,157,104,
    49,194,194,149,70,191,226,4,243,105,161,227,25,247,78,227,
    245,169,126,154,61,43,158,99,163,131,61,247,9,155,193,181,
    116,219,61,129,109,169,176,6,229,181,88,190,58,47,139,182,
    136,110,174,73,38,111,52,146,113,48,105,156,249,201,28,160,
    65,73,107,0,147,238,5,187,228,117,252,190,25,176,164,225,
    148,194,236,211,114,17,162,243,241,46,3,59,49,126,109,209,
    121,102,146,167,59,228,85,157,153,139,164,220,249,49,152,68,
    93,64,55,144,67,169,228,219,253,165,232,245,252,184,25,72,
    44,100,201,24,79,64,124,134,192,223,67,215,157,87,150,255,
    33,238,211,133,252,12,71,89,190,130,121,190,90,170,10,46,
    169,231,238,88,181,124,164,191,238,148,199,89,135,19,193,74,
    97,7,190,5,52,197,140,163,129,206,124,187,94,164,175,116,
    248,130,162,115,131,134,155,198,158,140,98,125,144,226,243,137,
    62,37,34,242,249,156,200,229,189,115,27,242,19,187,214,227,
    177,151,201,66,11,62,23,79,230,105,230,66,49,243,104,56,
    234,123,7,79,31,159,91,68,51,43,197,12,178,210,87,96,
    124,39,150,207,141,51,37,35,94,36,227,227,200,125,38,163,
    36,29,63,75,2,201,69,240,209,33,250,208,243,149,158,118,
    95,74,234,75,212,250,100,223,153,231,124,71,149,122,49,158,
    219,39,187,226,163,124,215,141,89,113,159,144,211,210,227,145,
    202,88,145,189,52,241,37,30,152,243,61,38,138,228,15,24,
    90,122,230,9,182,72,7,184,173,212,203,102,204,196,245,252,
    109,41,150,65,153,202,94,136,10,167,108,228,153,247,242,124,
    67,56,81,31,188,51,65,79,243,152,19,148,117,87,173,175,
    19,30,18,134,178,3,28,232,138,173,186,82,21,21,139,174,
    116,109,81,19,117,81,18,203,245,170,93,173,84,203,54,194,
    157,102,214,68,205,174,214,150,197,55,253,219,198,160,168,89,
    219,181,170,248,15,235,128,223,86,
};

EmbeddedPython embedded_m5_internal_param_TimingSimpleCPU(
    "m5/internal/param_TimingSimpleCPU.py",
    "/nfs/ug/homes-0/m/moham356/ece552/Lab6/gem5/build/ALPHA/python/m5/internal/param_TimingSimpleCPU.py",
    "m5.internal.param_TimingSimpleCPU",
    data_m5_internal_param_TimingSimpleCPU,
    2217,
    6798);

} // anonymous namespace
