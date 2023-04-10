#include "message_drv.h"
#include "can/can_handler.h"
#include "can/can_definitions.h"

void MessageHandler::Init(CommunicationDriver comDriver)
{
    m_ComDriver = comDriver;
    switch(comDriver){
        case CommunicationDriver::CAN:
            Can_Handler::Init();
            break;
        case CommunicationDriver::DoIP:
        case CommunicationDriver::DoK_Line:
        case CommunicationDriver::FlexRay:
        case CommunicationDriver::LIN:
        case CommunicationDriver::None:
            break;
    }
}

Message MessageHandler::WaitForMessage()
{
    Message msg;
    switch(m_ComDriver){
        case CommunicationDriver::CAN:
        {
            auto& receivedMsg = Can_Handler::WaitForMessage();
            uint8_t PCI_msg_type = receivedMsg[0] >> 4; 
            if(PCI_msg_type == 0){ // Check if message is single framed
                msg.AddByteArray(&receivedMsg.data()[1],receivedMsg.size()-1);
                return msg;
            }else if(PCI_msg_type == 1){ // Check if message is first frame
                uint32_t complete_msg_length = ((uint32_t)(receivedMsg[0] & 0x0F) << 8) | (uint32_t)receivedMsg[1];
                uint32_t current_msg_length = receivedMsg.size();
                msg.AddByteArray(&receivedMsg.data()[2],receivedMsg.size()-2);
                std::cout<<"First Frame Complete size: "<< complete_msg_length<<'\n';
                std::cout<<"Progress "<<current_msg_length <<"/"<<complete_msg_length<<std::endl;
                for(uint32_t frameIndex = 1;frameIndex <= UINT32_MAX; frameIndex++){
                    receivedMsg = Can_Handler::WaitForMessage();
                    PCI_msg_type = receivedMsg[0] >> 4; 
                    uint8_t PCI_msg_index = receivedMsg[0] & 0x0F;
                    if(PCI_msg_type == 2 && PCI_msg_index == frameIndex){ // Check if message is consecutive frame
                        msg.AddByteArray(&receivedMsg.data()[1],receivedMsg.size()-1);
                        current_msg_length += receivedMsg.size()-1;
                        std::cout<<"Progress "<<current_msg_length <<"/"<<complete_msg_length<<std::endl;
                    }

                    if(current_msg_length >= complete_msg_length-2){
                        std::cout<<"Completed\n"<<std::endl;
                        return msg;
                    }
                }
            }

            break;
        }
        case CommunicationDriver::DoIP:
        case CommunicationDriver::DoK_Line:
        case CommunicationDriver::FlexRay:
        case CommunicationDriver::LIN:
        case CommunicationDriver::None:
            break;
    }
    return msg;
}

void MessageHandler::SendMessage(Message message)
{
    CAN_Message msg;
    switch(m_ComDriver){
        case CommunicationDriver::CAN:
        {
            msg.AddByteArray(message.data(),message.length());
            Can_Handler::SendMessage(msg);
            break;
        }
        case CommunicationDriver::DoIP:
        case CommunicationDriver::DoK_Line:
        case CommunicationDriver::FlexRay:
        case CommunicationDriver::LIN:
        case CommunicationDriver::None:
            break;
    }
    msg.Clear();
}

void MessageHandler::Destroy()
{
    switch(m_ComDriver){
        case CommunicationDriver::CAN:
            Can_Handler::Destroy();
            break;
        case CommunicationDriver::DoIP:
        case CommunicationDriver::DoK_Line:
        case CommunicationDriver::FlexRay:
        case CommunicationDriver::LIN:
        case CommunicationDriver::None:
            break;
    }
}