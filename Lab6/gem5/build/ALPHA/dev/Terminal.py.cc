#include "sim/init.hh"

namespace {

const uint8_t data_m5_objects_Terminal[] = {
    120,156,181,146,77,111,212,48,16,134,199,217,221,180,221,182,
    128,16,92,144,144,194,45,66,162,70,84,233,9,21,84,196,
    1,9,65,181,187,151,238,37,202,38,179,109,86,254,136,108,
    7,117,111,149,202,255,134,25,103,11,252,1,242,49,26,191,
    99,143,159,25,187,134,221,51,162,255,99,6,224,207,201,105,
    232,19,160,0,180,128,165,0,193,227,4,84,2,139,157,55,
    34,111,4,40,96,45,160,25,195,79,128,123,128,171,229,24,
    154,9,204,243,148,82,180,191,232,201,5,121,225,128,204,188,
    213,223,87,27,172,195,32,177,121,29,246,201,46,208,233,214,
    84,170,254,23,228,130,65,174,200,65,224,253,105,211,101,2,
    56,130,205,24,112,2,155,148,233,238,19,88,238,69,113,159,
    145,8,135,149,131,168,76,25,138,80,88,57,140,202,17,224,
    49,52,105,84,30,193,108,158,239,81,246,89,66,198,63,99,
    90,19,208,185,190,11,89,109,77,112,86,41,116,237,221,49,
    69,15,41,170,90,31,208,100,157,117,161,101,68,255,152,107,
    216,129,103,166,215,43,116,254,5,105,159,77,181,82,152,217,
    62,116,125,200,154,94,119,89,176,217,186,85,152,199,37,92,
    112,89,154,74,99,89,134,105,28,104,219,244,138,135,99,158,
    176,237,48,76,200,185,172,92,165,3,239,253,133,112,62,13,
    76,33,29,34,104,66,224,46,85,102,27,142,6,120,87,238,
    184,3,215,181,168,187,75,98,141,41,25,58,206,166,68,49,
    193,128,27,99,23,150,22,176,179,112,61,198,224,64,158,115,
    145,127,141,255,64,70,154,181,151,253,181,188,177,26,253,155,
    183,82,75,109,111,42,125,90,156,73,172,177,40,222,201,175,
    213,234,76,94,163,46,164,119,181,108,240,135,124,56,219,147,
    110,27,91,253,138,147,113,217,169,72,197,115,241,148,222,111,
    57,151,27,203,208,197,201,159,91,50,131,135,139,67,106,199,
    205,240,177,121,60,114,246,118,72,247,31,48,227,38,239,135,
    51,57,127,201,73,185,43,79,196,84,76,147,223,209,123,179,
    180,
};

EmbeddedPython embedded_m5_objects_Terminal(
    "m5/objects/Terminal.py",
    "/nfs/ug/homes-0/m/moham356/ece552/Lab6/gem5/src/dev/Terminal.py",
    "m5.objects.Terminal",
    data_m5_objects_Terminal,
    465,
    811);

} // anonymous namespace