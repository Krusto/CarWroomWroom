#include "session_handler.h"

SessionHandler::SessionHandler() {
    m_REQ_SID = UDS_DIAG_SESSION_CONTROL_REQUEST_SID;
    m_RES_SID = UDS_DIAG_SESSION_CONTROL_RESPONSE_SID;
}

void SessionHandler::MainHandle(Message message) {
    InitResponseBuffer();

    if (message.length() == 2) {
        auto requestedSession = (DiagnosticSession) message[1];
        if (requestedSession == SessionData::GetCurrentDiagnosticSession()) {
            AddByteToRespBuffer(message[1]);
            SendPositiveResponse();
            return;
        } else {
            if(requestedSession == DiagnosticSession::Default ||
               requestedSession == DiagnosticSession::Programming ||
               requestedSession == DiagnosticSession::Extended)
            {
                AddByteToRespBuffer(message[1]);
                SessionData::SetDiagnosticSession(requestedSession);
                SendPositiveResponse();
                return;
            }else{
                SendNegativeResponse(NRC::RequestOutOfRange);
            }
        }
    } else {
        SendNegativeResponse(NRC::IncorrectMessageLengthOrInvalidFormat);
    }
}

void SessionHandler::PostHandle() {
    InitResponseBuffer();
    AddByteToRespBuffer(0x00);
    AddByteToRespBuffer(0x01);
    AddByteToRespBuffer(0x02);
    AddByteToRespBuffer(0x03);
    SendPositiveResponse();
}
