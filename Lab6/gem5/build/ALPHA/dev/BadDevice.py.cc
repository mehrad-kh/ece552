#include "sim/init.hh"

namespace {

const uint8_t data_m5_objects_BadDevice[] = {
    120,156,181,144,193,74,195,64,16,134,103,147,180,104,15,226,
    89,40,236,49,8,118,69,77,79,34,69,60,74,41,169,23,
    115,9,49,187,73,35,217,108,201,110,133,158,235,123,235,204,
    198,234,19,184,36,63,255,44,51,179,223,76,9,63,39,196,
    127,193,1,236,29,26,137,31,131,22,224,133,92,0,45,3,
    29,64,22,0,147,33,168,0,42,6,50,130,79,128,3,192,
    107,22,130,28,193,58,30,99,97,243,133,39,102,232,28,201,
    229,96,207,80,30,11,219,148,171,198,60,169,143,166,84,238,
    212,95,201,33,42,143,16,1,221,18,196,20,141,2,200,24,
    161,224,187,42,132,247,136,152,14,12,178,17,164,235,152,82,
    83,18,123,129,178,44,180,226,166,226,210,247,227,206,112,213,
    247,166,231,166,243,88,238,4,37,207,59,204,202,115,55,241,
    129,54,114,215,82,24,81,194,126,171,220,8,205,170,232,11,
    237,168,102,237,250,166,171,125,242,208,149,170,99,162,252,19,
    187,64,17,93,101,197,174,22,27,163,149,189,186,22,90,104,
    179,41,244,109,50,23,170,84,73,114,35,158,139,183,185,168,
    149,78,132,237,75,129,221,196,239,232,179,237,222,79,193,169,
    27,145,140,217,152,45,99,207,68,59,210,201,108,75,72,214,
    51,13,53,41,59,206,254,31,56,126,87,247,195,118,30,166,
    71,172,9,59,15,190,1,136,109,118,58,
};

EmbeddedPython embedded_m5_objects_BadDevice(
    "m5/objects/BadDevice.py",
    "/nfs/ug/homes-0/m/moham356/ece552/Lab6/gem5/src/dev/BadDevice.py",
    "m5.objects.BadDevice",
    data_m5_objects_BadDevice,
    315,
    556);

} // anonymous namespace