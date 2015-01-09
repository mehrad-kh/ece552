#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_enum_MemoryMode[] = {
    120,156,197,86,91,115,219,68,20,62,43,201,78,172,196,141,
    211,244,74,3,53,195,116,48,29,26,119,104,83,134,161,211,
    161,220,97,74,40,242,67,91,115,17,138,180,182,229,88,146,
    71,187,110,49,227,188,144,14,240,198,143,96,120,224,127,240,
    191,202,57,103,37,199,201,192,12,79,198,137,118,142,86,187,
    231,242,237,119,206,217,16,138,95,5,159,247,154,0,234,5,
    10,17,254,11,24,1,36,2,186,2,132,20,16,109,192,65,
    5,242,219,16,85,224,57,64,215,2,105,193,17,10,54,124,
    109,65,186,206,123,170,48,178,121,70,192,212,5,233,64,183,
    2,143,210,77,112,100,21,14,92,200,191,7,33,68,42,224,
    113,180,2,209,42,60,71,237,40,212,88,225,42,68,46,11,
    53,136,214,88,112,97,218,0,185,6,93,84,190,2,221,58,
    170,186,142,170,206,176,170,191,72,85,132,95,26,16,213,105,
    57,250,242,132,86,58,180,146,109,156,97,45,27,32,109,24,
    54,160,219,96,97,19,186,155,44,156,133,238,89,22,182,160,
    187,197,194,57,232,158,163,24,58,173,77,196,32,126,129,191,
    150,64,73,175,227,240,84,230,42,206,82,63,78,123,89,108,
    209,247,42,13,4,93,72,195,74,129,225,7,132,225,159,192,
    0,70,86,129,225,33,128,160,119,128,145,5,135,44,28,90,
    48,109,193,76,192,208,129,200,134,25,154,169,192,145,128,190,
    128,35,11,190,177,105,193,33,142,14,70,253,10,56,218,0,
    56,228,168,141,166,21,56,172,192,172,2,157,199,51,139,38,
    14,106,144,255,1,63,110,179,210,85,86,106,193,12,71,7,
    142,28,56,172,194,35,92,132,83,195,26,97,37,30,207,48,
    82,156,233,180,28,244,118,111,33,92,10,37,138,243,52,72,
    164,110,160,236,203,116,146,248,95,200,36,203,167,95,100,145,
    108,185,229,170,76,237,140,3,61,240,120,155,77,120,36,99,
    205,234,178,84,234,53,20,122,113,26,249,73,22,77,70,82,
    175,146,46,191,23,143,164,239,243,199,207,146,113,150,235,143,
    242,60,203,61,130,148,39,71,89,48,223,65,128,134,163,76,
    201,22,89,99,51,30,169,215,180,186,55,102,141,228,0,187,
    74,155,35,169,194,60,30,107,60,41,163,145,86,147,182,22,
    157,17,15,234,91,28,218,105,79,181,39,253,246,32,75,164,
    186,113,179,157,180,147,108,16,36,183,118,239,180,101,40,119,
    119,223,106,63,8,246,239,180,251,50,217,109,239,79,226,81,
    212,190,255,224,225,167,247,219,227,169,30,100,105,27,103,227,
    84,75,132,104,212,62,5,206,14,46,57,75,102,158,197,125,
    63,230,0,253,129,28,141,101,78,254,169,151,200,5,209,16,
    235,162,42,108,209,18,117,148,42,248,216,98,219,90,19,123,
    49,133,24,82,216,196,46,187,228,211,239,192,39,135,7,127,
    96,65,190,77,108,25,226,191,160,227,69,206,116,232,155,197,
    223,190,34,108,204,236,208,38,14,152,201,25,51,12,169,134,
    43,239,210,161,167,192,52,169,192,176,10,134,62,200,58,195,
    167,124,74,35,46,39,53,22,42,119,64,253,118,82,67,218,
    0,196,30,83,13,167,46,160,169,159,152,145,157,22,57,190,
    199,204,208,131,88,101,207,82,198,159,100,206,161,14,98,242,
    112,250,229,254,80,134,90,93,197,137,39,217,164,25,6,105,
    154,233,102,16,69,205,64,235,60,222,159,104,169,154,58,107,
    94,83,173,26,29,248,102,73,174,185,190,233,184,36,19,29,
    60,146,201,188,68,113,168,241,101,139,95,24,127,37,53,18,
    99,144,69,10,231,73,69,95,106,143,156,212,103,112,184,95,
    154,99,6,182,170,37,95,148,28,245,180,203,212,11,148,242,
    217,28,205,51,203,104,247,211,96,52,145,154,214,43,29,104,
    180,74,162,49,180,84,158,93,162,72,203,64,9,60,63,205,
    210,104,138,126,198,225,107,228,194,37,102,219,58,16,223,206,
    35,215,86,112,172,66,29,185,215,176,66,10,201,41,152,198,
    44,187,64,0,0,159,188,40,106,7,50,238,8,43,76,203,
    226,18,193,177,113,18,54,73,162,205,30,17,218,187,66,195,
    54,13,47,151,225,47,11,131,250,105,12,110,146,93,139,3,
    15,237,34,196,121,34,237,157,72,164,203,199,137,132,21,177,
    67,9,97,81,218,28,39,132,77,32,228,247,10,246,83,170,
    33,1,240,243,2,231,25,26,143,234,36,51,136,233,234,17,
    7,23,137,216,95,32,162,71,167,194,44,244,46,255,27,140,
    87,255,63,24,251,6,198,91,100,119,189,224,79,157,121,227,
    138,144,14,223,42,64,101,64,63,68,97,122,145,0,93,132,
    242,34,246,184,71,105,157,155,21,55,60,238,199,166,130,24,
    132,141,224,16,211,122,54,92,40,154,144,162,132,31,231,217,
    15,211,102,214,107,106,40,125,184,123,77,237,92,83,239,98,
    73,104,222,227,34,99,138,130,73,251,92,142,115,76,239,26,
    191,152,148,245,57,125,253,162,141,32,228,231,9,74,171,4,
    154,43,148,210,57,21,166,165,162,236,206,81,38,167,223,33,
    163,46,67,108,195,69,124,92,193,158,249,25,87,72,190,86,
    240,87,124,222,39,176,41,94,9,116,35,243,58,198,111,14,
    137,130,243,94,63,193,152,37,5,228,93,39,215,202,132,171,
    194,156,31,244,216,228,50,229,192,47,216,171,5,81,228,103,
    32,46,224,145,23,89,195,249,73,15,29,233,22,45,255,14,
    184,248,252,67,163,179,76,246,89,69,121,194,228,84,111,243,
    82,211,247,62,135,95,23,42,215,145,13,130,122,148,93,92,
    173,22,123,148,51,207,87,38,209,127,234,67,206,201,196,166,
    67,26,4,138,150,153,20,182,231,41,124,92,4,231,119,34,
    172,75,203,226,215,170,49,231,147,103,159,28,179,139,26,192,
    21,177,101,45,112,230,77,26,110,204,233,34,202,185,37,56,
    121,245,116,197,94,232,90,190,169,146,31,147,39,14,251,190,
    81,101,116,79,93,185,141,215,231,231,16,79,149,71,51,222,
    6,13,86,89,27,176,146,224,189,75,79,185,219,27,147,243,
    41,42,23,123,216,208,205,237,179,73,251,94,165,129,250,166,
    247,6,105,32,99,38,19,153,230,166,192,164,242,25,151,24,
    62,119,111,167,100,67,156,226,157,32,142,120,79,160,179,164,
    184,19,232,56,137,211,62,155,223,59,129,3,223,39,194,167,
    65,190,244,148,101,96,238,154,194,120,143,66,82,183,113,160,
    11,66,109,163,38,170,22,93,69,109,225,226,101,193,17,235,
    245,154,93,171,214,42,54,94,24,104,102,75,184,118,205,173,
    9,254,179,254,6,113,157,8,149,
};

EmbeddedPython embedded_m5_internal_enum_MemoryMode(
    "m5/internal/enum_MemoryMode.py",
    "/nfs/ug/homes-0/m/moham356/ece552/Lab6/gem5/build/ALPHA/python/m5/internal/enum_MemoryMode.py",
    "m5.internal.enum_MemoryMode",
    data_m5_internal_enum_MemoryMode,
    1481,
    3643);

} // anonymous namespace
