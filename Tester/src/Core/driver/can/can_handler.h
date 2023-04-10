#pragma once
#include "can_definitions.h"
#include "Client.h"

class Can_Handler{
public:
    Can_Handler() = default;
    ~Can_Handler() = default;

    static void Init();
    static CAN_Message& WaitForMessage();
    static void SendMessage(CAN_Message& message);

    static void Destroy();
private:
    static inline CAN_Message s_CanCommBuffer;
    Client client {};
protected:
    static Can_Handler s_handler;
};