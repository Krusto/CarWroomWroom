#pragma once
#include "can_definitions.h"
#include "uds_handler.h"

class UDS_Manager{
    public:
        UDS_Manager() = default;

        void OnStart();
        void OnStop();
        void OnUpdate();

        static UDS_Manager* GetHandle() { return &UDS_Manager::s_UDS_Manager_Handler;}
    private:
        void HandleMessage(CAN_Message message);

        static UDS_Manager s_UDS_Manager_Handler;
};