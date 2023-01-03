#pragma once
#include "can_definitions.h"

class Can_Handler{
public:
    static CAN_Message GetMessage();
    static void SendMessage(CAN_Message message);
};