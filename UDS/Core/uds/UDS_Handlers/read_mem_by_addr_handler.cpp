#include "read_mem_by_addr_handler.hpp"
#include "../uds_definitions.h"
#include "memory_map.hpp"
#include <string>

ReadMemByAddressHandler::ReadMemByAddressHandler() {
    m_REQ_SID = UDS_READ_MEMORY_BY_ADDRESS_REQUEST_SID;
    m_RES_SID = UDS_READ_MEMORY_BY_ADDRESS_RESPONSE_SID;
}

void ReadMemByAddressHandler::MainHandle(Message message) {
    InitResponseBuffer();
    if (!SessionData::GetSecurityAccessStatus()) {
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
        } else if (message.length() != 2 + addressLength + sizeLength) {
            SendNegativeResponse(NRC::IncorrectMessageLengthOrInvalidFormat);
        } else {
            int status = ReadData(address, size);
            if (status != 0) {
                SendNegativeResponse();
            } else {
                SendPositiveResponse();
            }
        }

    }
}

int ReadMemByAddressHandler::ReadData(uint32_t address, uint32_t size) {
    auto data = new uint8_t[size];

    int status = SessionData::ReadBufferFromEEPROM(address, data, size);
    if (status != 0)
        return 1;

    for (int i = 0; i < size; ++i)
        AddByteToRespBuffer(data[i]);

    delete[] data;
    return 0;
}

void ReadMemByAddressHandler::PostHandle() {
}
