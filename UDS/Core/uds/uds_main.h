#pragma once
#include "uds_handler.h"
#include "../driver/message_drv.h"
class UDS_Manager{
    public:
        UDS_Manager() = default;

        void OnStart();
        void OnStop();
        void OnUpdate();

        static UDS_Manager* GetHandle() { return &UDS_Manager::s_UDS_Manager_Handler;}
    private:
        void HandleMessage(Message message);

        MessageHandler m_MSG_Handler;
        static UDS_Manager s_UDS_Manager_Handler;
        bool m_SuppressPositiveResponse = false;
};