#include "write_mem_by_addr_handler.hpp"
#include "../uds_definitions.h"
#include "memory_map.hpp"
#include <string>

WriteMemByAddressHandler::WriteMemByAddressHandler() {
    m_REQ_SID = UDS_WRITE_MEMORY_BY_ADDRESS_REQUEST_SID;
    m_RES_SID = UDS_WRITE_MEMORY_BY_ADDRESS_RESPONSE_SID;
}

void WriteMemByAddressHandler::MainHandle(Message message) {
    InitResponseBuffer();
    if (SessionData::GetSecurityAccessStatus() == false) {
        SendNegativeResponse(NRC::SecurityAccessDenied);
    } else if (message.length() < 2) {
        SendNegativeResponse(NRC::IncorrectMessageLengthOrInvalidFormat);
    } else {
        uint8_t addressLength = message[1] & 0x0F;
        uint8_t sizeLength = (message[1] & 0xF0) >> 4;

        uint32_t address = 0;
        for (uint8_t i = 1; i <= addressLength; ++i) {
            address |= (uint32_t) message[1 + i] << (8 * (addressLength - i));
        }
        uint32_t size = 0;
        for (uint8_t i = 1; i <= sizeLength; ++i) {
            size |= (uint32_t) message[1 + addressLength + i] << (8 * (sizeLength - i));
        }

        if ((address > MEM_SIZE) || (address + size > MEM_SIZE)) {
            SendNegativeResponse(NRC::RequestOutOfRange);
        } else if (message.length() != 2 + addressLength + sizeLength + size) {
            SendNegativeResponse(NRC::IncorrectMessageLengthOrInvalidFormat);
        } else {
            int status = WriteData(address, size,message,2 + addressLength + sizeLength + 1);
            if (status != 0) {
                SendNegativeResponse(NRC::GeneralProgrammingFailure);
            } else {
                AddByteToRespBuffer(message[1]);
                for (uint8_t i = 1; i <= addressLength; ++i) {
                    AddByteToRespBuffer(message[1 + i]);
                }
                for (uint8_t i = 1; i <= sizeLength; ++i) {
                    AddByteToRespBuffer(message[1 + addressLength + i]);
                }
                SendPositiveResponse();
            }
        }

    }
}

int WriteMemByAddressHandler:: WriteData(uint32_t address,uint32_t size,Message& message,uint8_t messageOffset){
    int status = SessionData::WriteBufferToEEPROM(address,&message.data()[messageOffset], size);
    if (status != 0)
        return 1;
    return 0;
}

void WriteMemByAddressHandler::PostHandle() {
}
