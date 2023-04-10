#include "../Log.h"
#include "uds_main.h"

#include <memory>
#include "UDS_Handlers/routine_handler.h"
#include "UDS_Handlers/session_handler.h"
#include "UDS_Handlers/security_handler.h"
#include "UDS_Handlers/tester_present_handler.h"
#include "UDS_Handlers/read_data_by_id_handler.hpp"
#include "UDS_Handlers/read_mem_by_addr_handler.hpp"
#include "UDS_Handlers/write_mem_by_addr_handler.hpp"

UDS_Manager UDS_Manager::s_UDS_Manager_Handler;

void UDS_Manager::OnStart()
{
    m_MSG_Handler.Init(CommunicationDriver::CAN);

    ServiceHandlerSystem::RegisterHandle(RoutineHandler::GetName(),std::make_shared<RoutineHandler>());
    ServiceHandlerSystem::RegisterHandle(SessionHandler::GetName(),std::make_shared<SessionHandler>());
    ServiceHandlerSystem::RegisterHandle(SecurityAccessHandler::GetName(),std::make_shared<SecurityAccessHandler>());
    ServiceHandlerSystem::RegisterHandle(TesterPresentHandler::GetName(),std::make_shared<TesterPresentHandler>());
    ServiceHandlerSystem::RegisterHandle(ReadDataByIdentifierHandler::GetName(),std::make_shared<ReadDataByIdentifierHandler>());
    ServiceHandlerSystem::RegisterHandle(ReadMemByAddressHandler::GetName(),std::make_shared<ReadMemByAddressHandler>());
    ServiceHandlerSystem::RegisterHandle(WriteMemByAddressHandler::GetName(),std::make_shared<WriteMemByAddressHandler>());

    for(auto& [serviceName,serviceHandler] : ServiceHandlerSystem::GetHandlers()){
        serviceHandler->Init();
    }
}

void UDS_Manager::OnStop()
{
    for(auto& [serviceName,serviceHandler] : ServiceHandlerSystem::GetHandlers()){
        serviceHandler->PostHandle();
        ServiceHandlerSystem::DestroyHandle(serviceName);
    }
    m_MSG_Handler.Destroy();
}

void UDS_Manager::OnUpdate()
{
    auto message = m_MSG_Handler.WaitForMessage();

    std::vector<uint8_t> suppressResponse_messages_ids = {0x10,0x11,0x3E};
    for(const auto& messageID : suppressResponse_messages_ids){
        if(messageID == message[ServiceHandlerSystem::SID_Offset] &&
           0x80 == (message[ServiceHandlerSystem::SubFunc_Offset] & 0x80)){
            m_SuppressPositiveResponse = true;
            message[ServiceHandlerSystem::SubFunc_Offset] &= 0x7F;
            break;
        }
    }

    this->HandleMessage(message);
    if(m_SuppressPositiveResponse)
        m_SuppressPositiveResponse = false;
}
void UDS_Manager::HandleMessage(Message message){
    bool found = false;
    for(auto& [serviceName,serviceHandler] : ServiceHandlerSystem::GetHandlers()){
        if(message[ServiceHandlerSystem::SID_Offset] == serviceHandler->GetRequestSID()) {
            found = true;
            if(!m_SuppressPositiveResponse){
                LOG_INFO("%s ", serviceName.data());
                LOG_MESSAGE("Received",message);
            }

            serviceHandler->MainHandle(message);

            if (!m_SuppressPositiveResponse) {
                m_MSG_Handler.SendMessage(serviceHandler->GetResponseMessage());

                LOG_INFO("%s ", serviceName.data());
                LOG_MESSAGE("Sending", serviceHandler->GetResponseMessage());
            }
        }
    }
    if(!found && message.length() > 1){
        LOG_MESSAGE("UNKNOWN: ",message);
    }
}
