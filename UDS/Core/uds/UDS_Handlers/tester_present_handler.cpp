#include "tester_present_handler.h"
#include "../uds_definitions.h"

TesterPresentHandler::TesterPresentHandler() {
    m_REQ_SID = UDS_DIAG_TESTER_PRESENT_REQUEST_SID;
    m_RES_SID = UDS_DIAG_TESTER_PRESENT_RESPONSE_SID;
}

void TesterPresentHandler::MainHandle(Message message) {
    InitResponseBuffer();

    if (message.length() != 0x02) {
        SendNegativeResponse(NRC::IncorrectMessageLengthOrInvalidFormat);
    } else if (message[1] != 0x00){
        SendNegativeResponse(NRC::SubFunctionNotSupported);
    }else {
        SessionData::SetTesterPresent(true);
        SendPositiveResponse(0x00);
    }
}

void TesterPresentHandler::PostHandle() {

}
