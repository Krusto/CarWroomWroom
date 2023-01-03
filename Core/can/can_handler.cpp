#include "can_handler.h"
#include <cstdlib>
CAN_Message Can_Handler::GetMessage()
{
    //DUMMY IMPLEMENTATION
    CAN_Message msg;
    msg.size() = 10;
    msg[0] = 9;
    msg[1] = 0x31;
    for (size_t i = 2; i <= 9; i++)
        msg[i] = i;
    
    return msg;
}

void Can_Handler::SendMessage(CAN_Message message)
{
    //SIMULATING CAN SENDING
    int a = 0;
    for (uint32_t i = 0; i < UINT32_MAX; i++)
    {
        a++;
    }

    message.size() = 0;
}
