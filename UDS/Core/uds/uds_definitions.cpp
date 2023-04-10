#include "uds_definitions.h"

std::string_view TranslateServiceID(uint8_t SID){
    switch(SID){
        case 0x10: return "Diagnostic session control";
        case 0x11: return "ECU Reset";
        case 0x27: return "Security access";
        case 0x28: return "Communication control";
        case 0x3E: return "Tester Present";
        case 0x83: return "Access Timing Parameter";
        case 0x84: return "Secured data transmission";
        case 0x85: return "Control DTC Setting";
        case 0x86: return "Response on Event";
        case 0x87: return "Link Control";
        case 0x22: return "Read data by IDentifier";
        case 0x23: return "Read memory by address";
        case 0x24: return "Read scaling data by IDentifier";
        case 0x2A: return "Read data by periodic IDentifier";
        case 0x2C: return "Dynamically define data IDentifier";
        case 0x2E: return "Write data by IDentifier";
        case 0x3D: return "Write data by Address";
        case 0x14: return "Clear diagnostic information";
        case 0x19: return "Read DTC information";
        case 0x2F: return "I/O Control by IDentifier";
        case 0x31: return "Routine control";
        case 0x34: return "Request download";
        case 0x35: return "Request upload";
        case 0x36: return "Transfer data";
        case 0x37: return "Request transfer Exit";

        default: return "Unknown";
    }
}
