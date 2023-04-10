#include "routine_handler.h"
#include "../uds_definitions.h"

RoutineHandler::RoutineHandler()
{
    m_REQ_SID = UDS_ROUTINE_CTRL_REQUEST_SID;
    m_RES_SID = UDS_ROUTINE_CTRL_RESPONSE_SID;
}

void RoutineHandler::MainHandle(CAN_Message message)
{
    InitResponseBuffer();
    AddByteToRespBuffer(0x00);
    AddByteToRespBuffer(0x01);
    AddByteToRespBuffer(0x02);
    AddByteToRespBuffer(0x03);
    SendPositiveResponse();
}

void RoutineHandler::PostHandle()
{
    InitResponseBuffer();
    AddByteToRespBuffer(0x00);
    AddByteToRespBuffer(0x01);
    AddByteToRespBuffer(0x02);
    AddByteToRespBuffer(0x03);
    SendPositiveResponse();
}
