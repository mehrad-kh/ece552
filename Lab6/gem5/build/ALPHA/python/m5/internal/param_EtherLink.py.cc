#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_EtherLink[] = {
    120,156,197,88,235,115,219,198,17,223,3,64,74,160,68,139,
    122,75,182,28,179,147,241,148,201,36,166,227,212,78,31,30,
    79,221,38,125,141,71,113,193,116,236,48,15,20,2,142,36,
    40,18,224,0,71,59,236,72,95,42,79,219,111,253,35,58,
    253,208,255,163,223,250,71,165,187,123,0,4,189,60,201,180,
    67,219,226,205,97,177,216,219,199,111,247,246,206,135,236,95,
    5,127,63,111,2,164,251,2,32,192,63,1,35,128,177,128,
    174,0,33,5,4,235,112,88,129,228,71,16,84,224,21,64,
    215,0,105,192,9,78,76,248,194,128,104,153,191,169,194,200,
    100,138,128,89,13,164,5,221,10,60,139,86,193,146,85,56,
    172,65,242,71,16,66,68,2,158,7,11,16,44,194,43,148,
    142,19,155,5,46,66,80,227,137,13,193,18,79,106,48,107,
    128,92,130,46,10,95,128,110,29,69,189,139,162,174,177,168,
    127,147,168,0,223,108,64,80,39,118,212,229,115,226,180,136,
    147,215,184,198,82,86,114,205,26,208,109,228,243,85,232,174,
    230,243,53,232,174,65,176,2,114,13,134,235,208,67,83,27,
    133,188,13,144,38,12,55,161,187,9,18,255,54,224,4,189,
    17,172,50,239,22,243,174,21,188,219,204,187,3,221,29,144,
    248,183,173,121,171,208,105,109,162,111,195,111,241,95,11,125,
    11,106,25,135,23,50,73,195,56,114,195,168,23,135,6,189,
    175,210,64,145,240,105,88,200,66,242,75,10,201,191,128,227,
    17,24,89,72,142,1,5,11,210,127,100,192,49,79,142,13,
    152,181,224,72,192,208,130,192,132,35,92,166,66,10,244,5,
    156,24,240,165,73,12,199,56,90,232,196,183,192,82,58,30,
    67,118,162,150,180,0,199,21,56,170,64,231,249,145,65,132,
    67,27,146,127,194,159,246,88,232,34,11,53,224,8,71,11,
    78,44,56,174,194,51,100,66,210,208,38,243,197,243,35,180,
    20,41,157,150,133,218,238,151,204,37,83,130,48,137,188,177,
    84,13,156,187,19,47,241,198,238,39,106,32,147,39,97,116,
    216,170,229,92,113,122,103,226,169,129,195,159,153,228,143,241,
    68,177,184,56,146,106,9,39,189,48,10,220,113,28,76,71,
    82,45,146,44,183,23,142,164,235,242,203,223,142,39,113,162,
    62,73,146,56,113,200,165,76,28,197,94,241,5,57,212,31,
    197,169,108,209,106,188,140,67,226,21,113,247,38,44,145,20,
    96,85,233,227,64,166,126,18,78,20,70,74,75,36,110,146,
    214,162,24,241,144,126,133,67,59,234,165,237,105,191,61,136,
    199,50,125,255,110,123,220,30,199,3,111,252,225,253,7,109,
    233,203,251,247,239,181,159,120,7,15,218,125,57,190,223,62,
    152,134,163,160,253,248,201,211,223,60,110,79,102,106,16,71,
    109,164,134,145,146,232,162,81,251,156,115,238,32,203,26,45,
    243,50,236,187,33,27,232,14,228,104,34,19,210,47,189,78,
    42,136,134,88,22,85,97,138,150,168,227,172,130,63,83,236,
    25,75,98,63,36,19,125,50,155,208,101,230,120,250,7,112,
    228,48,240,135,6,36,123,132,150,33,254,9,10,47,98,166,
    67,239,12,126,247,123,242,141,166,14,77,194,128,38,30,49,
    194,16,106,200,249,144,130,30,1,195,164,2,195,42,104,248,
    32,234,52,158,146,25,141,200,78,98,12,20,110,65,250,247,
    179,18,162,6,160,239,49,115,145,180,133,75,253,153,17,217,
    105,145,226,251,140,12,53,8,211,248,101,196,254,167,57,231,
    80,7,125,242,116,246,233,193,80,250,42,189,133,132,207,227,
    105,211,247,162,40,86,77,47,8,154,158,82,73,120,48,85,
    50,109,170,184,121,59,109,217,20,240,213,28,92,133,188,217,
    36,7,19,5,30,193,164,31,130,208,87,248,176,206,15,236,
    255,84,42,4,198,32,14,82,164,147,136,190,84,14,41,169,
    174,225,240,56,95,142,17,216,170,230,120,73,229,168,167,106,
    12,61,47,77,93,94,142,232,140,50,250,250,133,55,154,74,
    69,252,169,242,20,174,74,83,189,208,92,113,182,67,150,230,
    134,146,243,220,40,142,130,25,234,25,250,111,147,10,59,140,
    182,101,32,188,109,34,214,22,112,172,66,29,177,215,48,124,
    50,201,202,144,198,40,219,34,7,0,71,94,100,181,3,17,
    119,130,21,166,101,112,137,96,219,56,9,155,52,163,143,29,
    2,180,115,131,134,61,26,110,230,230,207,203,7,245,243,62,
    184,75,235,26,108,184,111,102,38,22,137,180,127,38,145,118,
    79,19,9,43,98,135,18,194,160,180,57,77,8,147,156,144,
    60,202,208,79,169,134,0,192,215,37,204,179,107,28,170,147,
    140,32,134,171,67,24,44,3,177,95,2,162,67,81,97,20,
    58,187,87,185,241,214,155,115,99,95,187,241,67,90,119,57,
    195,79,157,113,83,19,62,5,223,200,156,202,14,253,24,39,
    179,109,114,104,217,149,219,184,199,61,139,234,188,89,241,134,
    199,219,187,174,32,218,195,122,98,17,210,122,38,108,101,155,
    80,74,9,63,73,226,111,102,205,184,215,84,144,235,240,240,
    118,122,231,118,250,51,44,9,205,71,92,100,116,81,208,105,
    159,200,73,130,233,109,243,131,78,89,151,211,215,205,182,17,
    116,57,109,232,28,41,118,52,87,168,84,37,84,152,230,234,
    229,90,225,101,82,250,39,180,104,141,93,108,194,54,254,106,
    130,53,115,99,174,144,220,86,240,91,252,253,130,156,77,246,
    74,160,6,207,233,104,189,217,36,50,206,249,225,25,196,204,
    201,32,231,93,82,45,79,184,42,20,248,160,159,73,42,83,
    14,252,21,184,241,18,240,23,32,44,96,200,179,172,225,252,
    164,31,133,116,157,216,191,6,46,62,151,108,116,134,206,62,
    35,43,79,152,156,233,71,204,170,247,189,223,193,223,74,149,
    235,196,4,65,123,148,153,181,86,229,61,202,42,242,149,65,
    244,157,246,33,235,108,98,83,144,6,94,74,108,58,133,205,
    34,133,79,139,96,209,19,97,93,154,23,190,22,245,114,46,
    105,246,235,83,116,209,6,112,67,172,27,37,204,188,71,195,
    251,5,92,68,78,155,131,146,183,206,87,236,210,174,229,234,
    42,249,43,210,196,98,221,87,170,156,217,133,132,34,43,42,
    121,86,220,43,178,66,114,221,126,197,189,55,141,6,133,255,
    196,16,120,192,193,94,133,206,22,22,200,10,116,171,148,63,
    220,91,138,44,189,68,94,207,168,14,158,217,20,216,53,251,
    218,105,5,2,116,112,105,248,102,174,245,131,226,251,112,228,
    141,15,2,239,209,103,180,36,173,235,231,9,103,228,70,52,
    202,70,80,178,136,171,236,224,199,187,185,49,47,230,90,59,
    62,192,21,10,35,56,83,130,216,231,130,241,217,64,54,199,
    114,124,128,71,174,65,56,105,246,70,94,159,35,101,102,70,
    126,154,27,169,56,212,231,55,99,110,100,246,227,166,31,71,
    88,228,167,190,138,147,102,32,241,36,34,3,13,244,179,57,
    203,189,157,151,244,83,110,227,14,95,210,116,238,81,117,241,
    96,25,98,247,250,135,220,33,250,196,83,148,118,110,88,117,
    214,224,254,136,167,9,53,211,53,236,1,13,239,208,112,27,
    222,196,14,208,198,21,58,180,20,57,175,138,101,198,22,106,
    165,156,176,79,233,155,244,98,218,254,231,187,164,173,190,145,
    200,146,183,74,156,114,129,14,183,52,218,180,9,116,107,57,
    113,137,199,101,38,214,115,226,53,30,87,152,216,200,137,171,
    60,174,49,113,61,39,110,240,184,201,196,173,156,184,205,227,
    14,19,119,243,139,148,235,76,188,1,221,61,186,141,32,202,
    77,170,39,11,255,107,61,225,60,156,123,6,126,241,127,45,
    35,206,189,55,106,131,195,93,235,235,74,136,40,27,88,215,
    37,100,40,242,230,190,108,29,95,31,108,93,68,178,235,39,
    210,83,82,135,236,250,156,205,229,18,165,21,248,170,8,92,
    110,83,113,202,249,168,176,235,132,59,174,217,70,169,243,230,
    56,138,103,216,30,97,119,126,196,166,187,134,110,208,79,225,
    105,21,30,32,103,70,242,165,123,206,11,186,1,39,109,188,
    201,68,70,193,105,115,205,111,230,10,1,42,129,1,156,118,
    59,216,73,111,224,239,98,50,90,154,49,55,146,35,88,41,
    210,111,222,177,100,232,134,121,20,91,111,65,185,222,59,20,
    67,93,225,139,226,238,252,180,136,202,238,37,184,12,228,200,
    155,209,241,237,53,111,177,227,226,27,12,126,82,55,175,228,
    123,225,37,44,233,245,28,36,205,206,165,17,229,210,149,211,
    137,148,193,149,122,233,183,185,94,252,196,247,26,23,86,157,
    142,39,44,228,202,151,36,131,35,140,15,234,206,37,92,124,
    23,135,1,249,192,197,206,32,194,19,22,221,231,250,241,52,
    82,44,248,123,126,66,203,17,100,174,102,121,173,196,187,223,
    95,137,75,62,57,175,196,69,22,206,14,174,99,24,37,169,
    228,249,68,214,55,188,186,179,8,36,246,75,241,12,143,207,
    124,12,165,72,187,238,252,91,138,31,227,10,93,200,174,175,
    168,165,168,98,83,177,89,250,111,91,182,224,254,237,220,69,
    188,214,146,80,166,15,94,179,212,225,93,97,165,200,27,190,
    48,206,251,39,46,147,132,223,125,111,172,239,0,249,94,203,
    249,1,13,111,231,169,199,69,78,159,200,249,184,171,47,26,
    176,36,242,85,3,247,146,14,69,141,187,158,146,53,31,19,
    12,79,105,157,112,172,47,62,213,234,89,190,140,186,148,7,
    94,63,115,95,117,118,251,225,24,37,178,31,166,232,58,150,
    82,226,207,170,50,185,78,237,93,150,102,165,111,231,30,81,
    125,110,209,151,49,143,200,125,233,67,28,232,82,210,94,177,
    69,213,160,235,111,83,212,68,93,88,98,185,110,155,118,213,
    174,152,24,117,162,172,139,154,105,215,150,5,253,223,197,184,
    215,140,221,134,45,254,11,28,171,23,191,
};

EmbeddedPython embedded_m5_internal_param_EtherLink(
    "m5/internal/param_EtherLink.py",
    "/nfs/ug/homes-0/m/moham356/ece552/Lab6/gem5/build/ALPHA/python/m5/internal/param_EtherLink.py",
    "m5.internal.param_EtherLink",
    data_m5_internal_param_EtherLink,
    2203,
    6918);

} // anonymous namespace