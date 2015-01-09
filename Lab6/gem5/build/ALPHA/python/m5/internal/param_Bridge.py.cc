#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_Bridge[] = {
    120,156,197,88,109,115,219,198,17,222,3,72,74,164,68,139,
    122,151,108,37,102,234,122,202,102,98,211,117,106,167,47,30,
    77,157,190,119,82,197,133,218,218,97,50,65,33,224,72,130,
    34,1,22,56,201,97,70,250,82,121,218,126,235,143,232,228,
    67,255,71,255,82,63,183,187,123,56,8,162,44,77,50,109,
    25,137,184,57,236,45,246,110,119,159,221,219,59,31,178,191,
    50,62,63,106,2,164,29,1,16,224,79,192,16,96,36,0,
    223,133,20,16,172,194,97,25,146,239,66,80,134,87,0,29,
    11,164,5,103,216,177,225,99,11,162,69,254,166,2,67,155,
    41,2,38,53,144,37,232,148,225,121,180,12,37,89,129,195,
    26,36,127,0,33,68,36,224,69,48,7,193,60,188,66,233,
    216,169,178,192,121,8,106,220,169,66,176,192,157,26,76,26,
    32,23,160,131,194,231,160,83,71,81,111,163,168,27,44,234,
    159,36,42,192,145,53,8,234,196,142,107,249,136,56,75,196,
    201,115,220,96,41,75,102,101,13,232,52,76,127,25,58,203,
    166,191,2,157,21,211,95,133,206,42,4,75,32,87,96,176,
    6,93,84,187,145,203,94,7,105,195,96,3,58,27,32,241,
    183,14,103,104,153,96,153,121,55,153,119,37,231,221,98,222,
    109,232,108,131,196,223,150,230,173,192,126,107,29,237,28,254,
    27,255,90,104,103,80,139,216,28,203,36,13,227,200,13,163,
    110,28,90,52,94,161,134,188,226,83,51,151,185,231,199,228,
    158,127,0,251,38,176,50,247,156,2,10,22,180,254,161,5,
    167,220,57,181,96,210,130,19,1,131,18,4,54,156,224,52,
    101,90,64,79,192,153,5,159,216,196,112,138,109,9,13,250,
    38,148,148,246,205,128,13,170,37,205,193,105,25,78,202,176,
    255,226,196,34,194,97,21,146,47,224,243,29,22,58,207,66,
    45,56,193,182,4,103,37,56,173,192,115,100,66,210,160,74,
    234,139,23,39,168,41,82,246,91,37,92,237,94,65,93,82,
    37,8,147,200,27,73,85,199,190,59,246,18,111,228,190,159,
    132,65,79,182,106,134,37,78,239,143,61,213,119,248,27,155,
    140,49,26,43,150,21,71,82,45,96,167,27,70,129,59,138,
    131,163,161,84,243,36,200,237,134,67,233,186,60,248,203,209,
    56,78,212,79,147,36,78,28,178,39,19,135,177,151,127,65,
    214,244,135,113,42,91,52,27,79,227,144,120,69,220,221,49,
    75,164,5,240,58,233,227,64,166,126,18,142,21,186,73,75,
    36,110,146,214,34,7,113,147,118,176,105,71,221,180,125,212,
    107,247,227,145,76,239,61,104,143,218,163,184,239,141,222,125,
    244,184,45,125,249,232,209,195,246,7,222,193,227,118,79,142,
    30,181,15,142,194,97,208,126,250,193,179,95,60,109,143,39,
    170,31,71,109,164,134,145,146,104,159,97,187,104,153,251,56,
    190,66,115,188,12,123,110,200,218,185,125,57,28,203,132,22,
    151,222,164,249,69,67,44,138,138,176,69,75,212,177,87,198,
    199,22,59,214,130,216,11,73,63,159,116,38,92,217,6,73,
    127,7,246,25,186,252,208,130,100,135,112,50,192,159,32,199,
    34,90,246,105,204,226,177,223,144,97,52,117,96,147,247,53,
    241,132,177,133,32,67,206,39,228,238,8,24,32,101,24,84,
    64,3,7,241,166,145,148,76,168,69,118,18,99,161,240,18,
    164,127,187,40,33,106,0,26,30,227,23,73,27,56,213,159,
    24,139,251,45,90,248,30,195,66,245,195,52,126,25,177,241,
    169,207,209,179,143,54,121,54,249,240,96,32,125,149,222,70,
    194,71,241,81,211,247,162,40,86,77,47,8,154,158,82,73,
    120,112,164,100,218,84,113,243,110,218,170,146,183,151,13,178,
    114,121,147,177,65,18,121,29,145,164,95,130,208,87,248,178,
    202,47,108,255,84,42,68,69,63,14,82,164,147,136,158,84,
    14,45,82,221,192,230,169,153,142,225,215,170,24,176,164,114,
    216,85,53,198,157,151,166,46,79,71,116,134,24,125,125,236,
    13,143,164,34,254,84,121,10,103,165,174,158,104,118,32,219,
    34,53,141,150,100,57,55,138,163,96,130,139,12,253,59,52,
    255,22,67,109,17,8,108,235,8,180,57,108,43,80,71,224,
    53,44,159,244,41,101,48,99,136,109,144,246,192,110,23,89,
    202,64,184,157,97,98,105,89,156,25,88,49,14,191,38,245,
    232,99,135,208,236,220,162,102,135,154,55,140,238,51,49,64,
    125,218,0,15,104,82,139,181,246,237,76,191,60,132,246,46,
    132,208,246,121,8,97,22,220,167,80,176,40,96,206,67,193,
    38,11,36,187,25,238,41,200,208,245,56,92,64,59,219,197,
    105,144,190,21,3,84,135,208,87,132,96,175,0,65,135,92,
    194,248,115,182,175,178,225,237,175,201,134,61,109,195,119,105,
    210,197,12,57,117,70,76,77,248,228,118,43,179,40,91,243,
    39,216,153,108,146,53,139,118,220,196,77,237,121,84,231,221,
    137,119,56,222,219,117,226,208,230,213,157,18,97,172,107,195,
    70,182,235,164,20,231,227,36,254,108,210,140,187,77,5,102,
    13,79,238,166,247,239,166,63,196,76,208,220,229,220,162,115,
    129,142,246,68,142,19,140,234,42,191,232,72,117,57,106,221,
    108,235,64,123,211,14,206,110,98,43,115,98,74,85,66,249,
    104,118,38,174,229,38,166,21,127,159,102,172,177,125,109,216,
    196,167,38,120,89,110,204,89,145,139,8,30,197,231,125,178,
    52,41,43,129,74,59,103,95,47,154,245,33,205,156,111,93,
    192,202,44,180,113,222,166,117,153,56,171,64,142,12,122,108,
    90,47,65,255,47,192,53,150,128,63,3,161,0,157,157,5,
    11,135,37,61,228,204,85,98,255,20,56,225,188,102,103,179,
    116,208,89,89,74,194,152,76,223,99,86,189,209,253,10,254,
    90,200,86,103,54,8,218,148,236,172,138,42,110,74,165,60,
    76,25,62,95,106,227,41,93,140,103,242,80,223,75,137,77,
    71,174,157,71,238,121,226,203,43,32,76,71,51,65,214,188,
    158,203,165,101,253,252,28,87,148,241,111,137,85,171,128,150,
    119,168,185,151,3,69,24,218,255,123,133,183,167,83,116,97,
    143,114,117,90,252,25,45,163,196,11,95,170,240,70,170,63,
    207,35,161,108,34,225,97,30,9,146,179,244,43,174,174,169,
    181,200,235,103,150,192,227,12,214,36,116,146,40,129,44,67,
    167,66,49,195,5,164,200,66,74,152,4,70,137,239,194,22,
    192,70,217,211,230,202,29,175,125,74,205,103,179,75,24,228,
    214,39,67,111,116,16,120,187,191,163,249,104,82,223,4,153,
    101,52,104,20,53,160,0,17,87,41,193,175,15,140,38,199,
    179,75,22,223,65,241,185,6,28,26,65,236,115,134,248,109,
    95,54,71,114,116,128,199,169,126,56,110,118,135,94,143,125,
    100,103,26,126,104,52,84,236,228,233,77,151,171,149,189,184,
    233,199,17,230,243,35,95,197,73,51,144,120,208,144,129,6,
    247,197,32,229,234,205,75,122,41,227,235,240,37,117,103,235,
    79,23,79,140,33,22,167,191,55,214,208,167,153,60,139,115,
    61,170,35,5,247,65,60,44,168,137,206,88,143,169,249,54,
    53,119,97,230,201,190,77,158,162,121,200,108,21,76,42,85,
    193,117,188,230,120,70,220,233,229,56,253,215,151,137,83,125,
    225,144,69,107,133,56,229,28,157,87,169,173,82,178,239,212,
    12,113,129,219,69,38,214,13,241,6,183,75,76,108,24,226,
    50,183,43,76,92,53,196,53,110,215,153,184,97,136,155,220,
    110,49,113,219,16,111,114,123,139,137,59,134,248,6,183,111,
    50,241,182,185,81,105,50,241,45,232,124,131,174,34,136,114,
    135,82,205,220,127,155,106,56,74,103,27,159,159,252,79,51,
    140,243,240,235,83,192,225,218,245,186,236,34,138,218,213,117,
    118,25,8,83,223,23,85,227,139,131,213,41,168,187,126,34,
    61,37,181,167,110,206,82,81,206,91,122,246,79,115,127,25,
    109,242,35,206,123,185,70,103,92,119,77,214,10,149,55,187,
    79,60,199,34,9,171,243,19,86,218,181,116,129,126,14,201,
    82,174,59,249,62,146,47,221,162,254,186,250,166,165,120,227,
    177,140,130,243,202,154,71,102,231,118,74,138,61,56,47,120,
    176,140,94,195,231,114,232,145,62,5,245,216,113,229,60,216,
    102,234,66,198,234,208,56,175,245,77,40,166,127,135,92,167,
    19,126,158,235,157,31,228,206,216,156,6,98,226,69,61,153,
    210,153,237,202,49,44,184,216,85,250,85,221,156,102,123,153,
    132,74,186,158,127,200,82,174,25,38,65,116,200,202,41,106,
    251,210,148,242,143,110,26,126,46,89,212,213,163,36,137,54,
    67,67,80,27,211,172,129,28,122,19,150,114,197,16,137,32,
    7,242,155,186,53,205,20,209,130,207,133,92,55,78,146,8,
    62,231,164,203,70,72,100,58,62,87,236,154,97,99,163,156,
    162,238,77,51,243,69,224,200,75,17,29,46,150,45,17,30,
    246,232,34,217,143,143,34,197,226,191,218,23,52,35,29,61,
    174,99,82,239,188,86,100,58,244,142,229,235,215,240,149,62,
    72,51,11,95,195,195,145,202,121,20,45,44,17,62,69,225,
    156,99,178,91,146,0,33,154,196,19,60,193,243,97,152,28,
    226,186,51,174,118,190,135,226,63,166,121,200,174,84,237,84,
    176,222,89,159,250,175,150,170,130,11,203,169,219,127,189,76,
    46,54,249,8,56,73,29,222,147,150,242,32,230,139,106,83,
    219,113,170,38,196,236,121,35,125,253,200,183,106,206,91,212,
    220,49,121,128,3,88,95,12,240,193,91,95,118,96,90,230,
    235,14,46,114,157,251,38,91,63,13,130,196,161,96,119,143,
    37,21,196,28,39,28,253,138,22,161,181,253,181,28,233,235,
    215,2,109,63,52,52,18,159,115,112,245,87,216,3,217,81,
    137,236,133,132,53,254,60,103,205,182,7,50,224,229,240,47,
    126,54,91,143,234,147,148,190,12,218,37,221,210,93,108,232,
    58,180,186,84,21,21,139,110,221,109,81,19,117,81,18,139,
    245,170,93,173,84,203,54,122,157,40,171,162,102,87,107,139,
    66,255,111,163,215,107,214,246,74,85,252,7,144,6,50,11,
};

EmbeddedPython embedded_m5_internal_param_Bridge(
    "m5/internal/param_Bridge.py",
    "/nfs/ug/homes-0/m/moham356/ece552/Lab6/gem5/build/ALPHA/python/m5/internal/param_Bridge.py",
    "m5.internal.param_Bridge",
    data_m5_internal_param_Bridge,
    2272,
    7045);

} // anonymous namespace