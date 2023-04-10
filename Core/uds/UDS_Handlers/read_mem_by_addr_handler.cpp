#include "read_data_by_id_handler.hpp"
#include "../uds_definitions.h"
#include "memory_map.hpp"
#include <string>

ReadDataByIdentifierHandler::ReadDataByIdentifierHandler() {
    m_REQ_SID = UDS_READ_DATA_BY_ID_REQUEST_SID;
    m_RES_SID = UDS_READ_DATA_BY_ID_RESPONSE_SID;
}

void ReadDataByIdentifierHandler::MainHandle(CAN_Message message) {
    InitResponseBuffer();

    if (message[0] != 3) {
        AddByteToRespBuffer(NRC::IncorrectMessageLengthOrInvalidFormat);
        SendNegativeResponse();
    } else {



        uint16_t did = (((uint16_t) message[2]) << 8) | ((uint16_t) message[3] & 0xFF);
        int status = HandleDID(did,message);
        if (status == 0) {
            SendPositiveResponse();
        }else{
            SendNegativeResponse();
        }
    }
}

int ReadDataByIdentifierHandler::HandleDID(uint16_t did, CAN_Message& message) {
    switch (did) {
        case RDID_ActiveDiagnosticSession:
            AddByteToRespBuffer((uint8_t) SessionData::GetCurrentDiagnosticSession());
            break;
        case RDID_SoftwareVersionNumber: {
            uint8_t version[4] = {'\0', '\0', '\0', '\0'};
            uint8_t status = SessionData::ReadBufferFromEEPROM(MEM_RDID_SoftwareVersionNumber_Location,version,MEM_RDID_SoftwareVersionNumber_Size);
            if(status == 0) {
                AddByteArrayToRespBuffer(version, MEM_RDID_SoftwareVersionNumber_Size);
            }else{
                return 1;
            }
            break;
        }
        case RDID_EngineType: {
            uint8_t type[13] = {'\0', '\0', '\0', '\0','\0', '\0', '\0', '\0','\0', '\0', '\0', '\0','\0'};
            uint8_t status = SessionData::ReadBufferFromEEPROM(MEM_RDID_EngineType_Location,type,MEM_RDID_EngineType_Size);
            if(status == 0) {
                AddByteArrayToRespBuffer(type, MEM_RDID_EngineType_Size);
            }else{
                return 1;
            }
            break;
        }
        case 0xFFFF:{
            uint16_t address = ((uint16_t)message[4]<<8) | ((uint16_t)message[5] & 0xFF);
            switch(address){
                case RDID_SoftwareVersionNumber:
                {
                    uint8_t version[MEM_RDID_SoftwareVersionNumber_Size] = {'X','_','0','0'};
                    if (currentSession.WriteBufferToEEPROM(MEM_RDID_SoftwareVersionNumber_Location,version,MEM_RDID_SoftwareVersionNumber_Size) != 0) {
                        return 1;
                    }
                    break;
                }
                case RDID_EngineType:
                {
                    uint8_t version[MEM_RDID_EngineType_Size] = {'g','a','s','o','l','i','n','e','-','-','-','-','-'};
                    if (currentSession.WriteBufferToEEPROM(MEM_RDID_EngineType_Location,version,MEM_RDID_EngineType_Size) != 0) {
                        return 1;
                    }
                    break;
                }
            }


            break;
        }
        default:
            AddByteToRespBuffer(NRC::RequestOutOfRange);
            return 1;
    }
    return 0;
}

void ReadDataByIdentifierHandler::PostHandle() {
}
