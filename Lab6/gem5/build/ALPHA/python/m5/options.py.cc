#include "sim/init.hh"

namespace {

const uint8_t data_m5_options[] = {
    120,156,181,88,221,111,220,68,16,95,219,247,229,75,218,148,
    150,68,9,164,200,64,35,174,148,244,10,40,21,69,105,85,
    149,22,10,170,210,224,43,2,162,182,150,99,239,221,57,185,
    179,175,246,94,219,72,201,3,10,47,69,130,119,30,121,224,
    239,132,249,205,218,190,124,180,60,113,73,237,204,206,142,119,
    119,102,126,243,177,13,68,254,99,209,115,219,17,34,235,19,
    17,210,63,67,12,132,216,42,105,67,108,25,76,155,224,63,
    10,45,33,77,209,37,86,69,252,42,196,161,16,63,111,89,
    34,172,22,220,90,201,173,136,176,46,100,149,185,141,146,91,
    195,162,157,150,77,155,69,255,208,207,70,203,32,82,225,245,
    177,2,55,78,66,217,245,199,3,21,20,39,196,220,29,156,
    176,65,132,20,56,143,219,105,97,166,101,226,91,176,61,47,
    246,135,210,243,84,147,7,195,36,28,15,104,168,165,202,87,
    118,151,94,237,184,155,181,199,189,118,63,25,202,108,245,90,
    123,216,30,38,125,127,248,249,218,245,182,12,228,218,218,103,
    237,7,254,246,245,118,79,14,215,218,89,26,180,71,123,170,
    159,196,109,26,37,35,21,37,113,118,117,180,231,226,76,31,
    96,69,156,160,166,207,144,141,6,145,82,50,61,125,240,119,
    202,131,147,33,201,18,91,38,172,0,194,130,42,88,35,192,
    171,120,190,194,71,103,136,216,55,196,62,233,195,206,232,176,
    165,114,123,85,139,253,180,9,42,24,202,65,215,173,78,71,
    223,220,198,81,28,41,207,91,41,244,22,70,128,253,234,244,
    84,138,83,63,193,169,45,177,35,112,112,122,31,26,226,160,
    10,255,238,87,196,142,9,133,118,44,113,104,138,131,154,216,
    175,65,173,221,134,72,31,64,161,163,2,251,85,113,104,9,
    35,62,3,161,157,26,143,13,97,28,177,2,54,101,109,21,
    168,158,84,190,82,169,170,17,253,220,31,140,101,198,38,9,
    233,47,19,27,73,44,89,48,59,34,40,95,42,25,135,122,
    37,140,153,169,117,102,89,34,189,140,100,171,197,162,44,48,
    242,211,76,166,46,160,234,54,167,106,237,192,31,12,60,239,
    35,172,220,100,107,159,55,230,141,89,99,201,108,65,37,23,
    30,112,17,189,46,107,112,254,216,89,254,103,184,99,195,75,
    88,17,68,205,176,77,53,75,196,67,22,216,100,131,148,160,
    55,11,208,63,254,15,208,83,50,1,65,41,194,98,162,154,
    167,19,164,135,42,19,245,60,149,108,53,144,70,64,216,34,
    180,57,147,80,70,154,65,216,192,40,129,145,167,48,60,15,
    177,237,247,0,160,9,232,209,110,132,59,194,20,37,30,66,
    156,161,52,180,12,76,255,193,248,244,42,140,82,2,94,21,
    66,70,164,185,181,156,11,186,174,67,15,90,109,112,126,234,
    38,233,208,71,152,183,224,37,206,55,4,170,60,103,177,231,
    200,110,12,18,117,129,6,143,34,53,144,225,125,57,24,125,
    93,124,232,130,207,107,121,165,232,18,208,26,101,254,54,101,
    173,40,38,161,108,68,143,12,61,63,237,101,26,15,132,6,
    18,207,24,132,94,47,77,198,163,150,85,66,23,126,97,81,
    140,118,95,128,156,6,14,128,180,107,19,64,46,16,32,207,
    152,182,117,218,11,80,81,39,128,29,99,98,242,34,120,25,
    186,139,56,247,172,54,159,151,219,47,155,168,228,46,227,117,
    113,74,128,126,143,22,250,242,72,30,43,20,168,20,10,220,
    208,217,119,54,189,136,179,243,31,145,103,53,207,16,241,98,
    161,157,121,28,80,134,46,111,88,53,91,214,186,57,170,47,
    157,96,156,166,50,86,142,62,130,195,238,219,208,202,194,14,
    238,187,48,198,57,56,49,12,61,45,116,210,199,83,53,8,
    195,17,142,224,77,111,98,80,227,104,62,107,204,153,108,157,
    218,81,235,252,125,52,200,40,38,41,188,40,164,119,77,145,
    134,8,105,154,218,173,129,134,140,9,14,202,128,37,122,252,
    21,133,250,58,69,57,168,26,81,117,166,12,177,174,44,84,
    142,67,54,39,113,215,99,49,137,206,210,200,7,21,46,20,
    53,84,21,170,10,16,168,139,221,186,72,255,2,95,15,137,
    207,31,87,242,70,35,187,169,13,235,248,113,225,0,149,188,
    209,45,159,56,73,234,244,6,201,182,63,112,98,170,27,14,
    153,133,195,202,15,184,52,48,57,26,81,233,152,212,159,34,
    252,49,71,37,35,138,123,28,145,106,111,36,57,120,145,202,
    183,253,96,119,67,39,13,248,148,74,150,59,83,12,70,201,
    136,115,172,198,65,243,24,14,184,202,184,104,33,90,181,211,
    88,224,51,184,103,197,244,170,145,123,153,22,194,98,217,2,
    214,173,93,50,230,140,38,255,94,48,231,13,155,70,231,204,
    0,135,135,54,80,143,251,128,63,5,99,131,252,182,64,46,
    11,77,77,177,35,129,26,11,40,200,219,0,66,205,173,60,
    83,31,212,1,129,131,134,136,231,152,168,23,252,6,187,214,
    130,79,9,58,132,155,28,54,196,175,19,100,172,3,187,16,
    168,178,0,85,138,38,55,24,36,208,96,1,26,146,76,83,
    116,77,66,5,142,202,13,47,163,194,217,78,146,129,156,128,
    3,222,146,161,179,186,138,158,146,64,195,100,194,163,171,77,
    39,255,185,27,81,255,229,239,57,125,74,237,78,40,129,7,
    114,187,67,159,191,232,71,65,223,137,50,70,88,145,216,96,
    160,213,213,149,44,171,51,65,203,173,100,220,245,174,242,219,
    115,223,47,171,137,74,82,233,169,116,44,221,15,139,212,142,
    77,212,76,57,217,245,7,153,212,254,174,20,16,76,37,29,
    39,144,46,156,164,208,59,118,126,216,220,116,239,117,58,222,
    253,123,15,54,217,137,172,246,164,94,64,31,222,194,93,21,
    121,75,169,192,99,170,203,179,205,114,130,79,192,19,76,241,
    182,100,46,38,186,68,76,35,39,225,184,112,77,30,8,63,
    137,188,149,22,21,160,239,188,65,141,8,181,34,104,71,22,
    137,162,199,44,187,104,171,192,225,67,157,199,117,166,162,220,
    146,174,0,82,202,4,92,8,127,186,33,32,126,71,183,218,
    72,91,55,64,208,112,169,243,122,73,221,12,184,87,74,243,
    107,175,249,169,202,94,68,170,175,123,243,241,168,40,244,200,
    234,158,151,119,168,209,246,88,225,94,98,30,243,4,102,166,
    101,192,114,107,186,21,137,178,114,207,25,11,230,172,209,48,
    131,162,232,149,6,251,253,164,193,174,188,198,96,20,122,232,
    168,226,167,249,13,133,146,52,44,55,18,17,207,17,243,58,
    165,123,76,84,17,199,180,166,49,177,239,43,22,225,93,214,
    159,189,18,241,210,155,55,152,244,94,218,220,156,251,80,154,
    93,20,111,109,95,173,100,86,40,201,153,146,235,187,110,147,
    249,147,117,188,224,8,206,198,101,179,49,133,100,121,139,22,
    122,142,21,207,229,118,94,166,231,12,253,206,34,77,34,212,
    171,249,195,214,126,42,142,244,73,212,130,62,166,92,71,165,
    210,20,47,239,176,23,216,30,196,191,251,228,83,158,179,242,
    2,136,139,147,45,178,111,97,93,152,181,14,96,235,2,72,
    156,245,103,43,130,254,253,184,111,150,45,23,151,137,197,2,
    173,220,116,30,233,45,189,48,10,232,102,199,93,64,68,221,
    39,61,195,140,203,147,254,176,68,42,58,80,46,62,92,182,
    118,229,30,255,165,219,209,52,108,121,155,22,250,101,130,217,
    121,115,153,130,252,45,243,244,85,121,245,132,21,1,54,109,
    161,244,50,78,138,94,158,193,108,196,199,174,210,39,140,66,
    117,91,121,72,111,147,194,156,237,233,155,164,124,153,95,181,
    181,41,26,57,43,72,66,57,141,192,197,193,198,153,223,147,
    191,137,162,19,99,8,109,180,208,48,159,188,250,1,236,174,
    131,23,178,188,251,5,94,104,121,24,140,108,69,86,200,253,
    78,76,241,138,136,88,108,99,69,92,68,41,39,55,109,203,
    174,219,111,219,243,182,109,207,216,182,190,102,163,56,185,223,
    136,226,174,189,189,35,3,197,255,151,194,221,143,190,179,19,
    18,121,177,105,157,148,157,183,174,255,135,232,214,197,2,94,
    179,198,172,217,52,23,204,133,153,127,1,34,45,216,106,
};

EmbeddedPython embedded_m5_options(
    "m5/options.py",
    "/nfs/ug/homes-0/m/moham356/ece552/Lab6/gem5/src/python/m5/options.py",
    "m5.options",
    data_m5_options,
    1823,
    4890);

} // anonymous namespace