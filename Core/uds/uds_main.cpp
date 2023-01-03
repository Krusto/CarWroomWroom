#include "../Log.h"
#include "uds_main.h"
#include "can_handler.h"
#include "UDS_Handlers/routine_handler.h"
#include "UDS_Handlers/session_handler.h"

UDS_Manager UDS_Manager::s_UDS_Manager_Handler;

void UDS_Manager::OnStart()
{
    ServiceHandlerSystem::RegisterHandle(RoutineHandler::GetName(),std::shared_ptr<RoutineHandler>(new RoutineHandler()));
    ServiceHandlerSystem::RegisterHandle(SessionHandler::GetName(),std::shared_ptr<SessionHandler>(new SessionHandler()));

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
}

void UDS_Manager::OnUpdate()
{
    this->HandleMessage(Can_Handler::GetMessage());
}
void UDS_Manager::HandleMessage(CAN_Message message){
    for(auto& [serviceName,serviceHandler] : ServiceHandlerSystem::GetHandlers()){
        if(message[1] == serviceHandler->GetRequestSID()){
            LOG_INFO("Service handler: %s \nReceived message with size %d\n",serviceName.data(), message[0]);
            serviceHandler->MainHandle(*message.Offset(1));

            auto responseMessage = serviceHandler->GetMessageResponse();

            LOG_INFO("Service handler: %s \nSending response with size %d\n",serviceName.data(), responseMessage[0]);

            std::string responseData = "";
            for(uint8_t i = 0; i < responseMessage.size(); i++){
                responseData += int_to_hex(responseMessage[i]) + " ";
            }
            LOG_INFO("Sending { %s}\n",responseData.data());
            Can_Handler::SendMessage(responseMessage);
        }
    }

}
