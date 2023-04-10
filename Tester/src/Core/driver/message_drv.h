#pragma once
#include <cstdint>
#include <memory>
#include "./message.h"

enum class CommunicationDriver{
    None,
    CAN,
    FlexRay,
    DoIP,
    DoK_Line,
    LIN
};

class MessageHandler{
public:
    MessageHandler() = default;

    void Init(CommunicationDriver comDriver);
    Message WaitForMessage();
    void SendMessage(Message message);

    void Destroy();
private:
    CommunicationDriver m_ComDriver;
};
