#include <random>

#include "security_handler.h"
#include "memory_map.hpp"

SecurityAccessHandler::SecurityAccessHandler() {
    m_REQ_SID = UDS_DIAG_SEC_ACCESS_REQUEST_SID;
    m_RES_SID = UDS_DIAG_SEC_ACCESS_RESPONSE_SID;
}

std::string exec(const char *cmd) {
#ifdef _WIN32
    std::string result = "";
#else
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
#endif
    return result;
}

void SecurityAccessHandler::MainHandle(Message message) {
    InitResponseBuffer();
    uint8_t sub_function = message[1];

    switch (sub_function) {
        case 0x01: {
            uint8_t status = RequestSeed(message);
            if (status == 0) {
                SendPositiveResponse(0x01);
            }
            break;
        }
        case 0x02: {
            uint8_t status = SendKey(message);
            if (status == 0) {
                SendPositiveResponse(0x02);
            }
            break;
        }
        default:
            SendNegativeResponse(NRC::SubFunctionNotSupported);
            break;
    }
}

uint8_t SecurityAccessHandler::SendKey(Message &message) {
    if (!SessionData::IsSecurityAccessSeedRequested()) {
        SendNegativeResponse(NRC::RequestSequenceError);
        return 1;
    }else if (message.length() != 6) {
        SendNegativeResponse(NRC::IncorrectMessageLengthOrInvalidFormat);
        return 1;
    }

    uint64_t receivedKey =
            (uint64_t) (message[2] << 24) |
            (uint64_t) (message[3] << 16) |
            (uint64_t) (message[4] << 8) |
            (uint64_t) (message[5]);

    if (receivedKey == m_ExpectedKey) {
        SessionData::SetSecurityAccessStatus(true);
    } else {
        SendNegativeResponse(NRC::InvalidKey);
        return 1;
    }
    return 0x00;
}

uint8_t SecurityAccessHandler::RequestSeed(Message &message) {

    if (message.length() != 2) {
        SendNegativeResponse(NRC::IncorrectMessageLengthOrInvalidFormat);
        return 1;
    }

    if (!SessionData::GetSecurityAccessStatus()) {
        std::random_device device;
        std::default_random_engine engine(device());
        std::uniform_int_distribution<uint64_t> uniform_dist(0, UINT64_MAX);

        m_Seed = uniform_dist(engine);
        m_Seed = 1;
        m_ExpectedKey = ~m_Seed + 1;

        AddByteToRespBuffer((uint8_t) ((m_Seed & 0xFF000000) >> 24));
        AddByteToRespBuffer((uint8_t) ((m_Seed & 0x00FF0000) >> 16));
        AddByteToRespBuffer((uint8_t) ((m_Seed & 0x0000FF00) >> 8));
        AddByteToRespBuffer((uint8_t) ((m_Seed & 0x000000FF)));

        SessionData::SetSecurityAccessSeedRequested(true);
    } else {
        AddByteToRespBuffer(0x00);
        AddByteToRespBuffer(0x00);
        AddByteToRespBuffer(0x00);
        AddByteToRespBuffer(0x00);
    }

    return 0;
}

void SecurityAccessHandler::PostHandle() {
}
