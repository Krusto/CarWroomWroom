#pragma once
#include "../../can/can_definitions.h"

#include <cstdlib>
#include <string_view>

class ServiceHandler{
    public:
        /**
         * @brief Inits service handler
         */
        virtual void Init() = 0;
        /**
         * @brief Destroys service handler
         */
        virtual void Destroy() = 0;
        /**
         * @brief Main callback function used for service handling
         * @param message Message from the CAN Bus - CAN_Message
         */
        virtual void MainHandle(CAN_Message message) = 0;
        /**
         * @brief Callback function used after confirmation of request transmission
         */
        virtual void PostHandle() = 0;
        /**
         * @brief Function which returns Request SID
         * @return Service Request SID - uint8_t
         */
        uint8_t GetRequestSID() { return m_REQ_SID; }
        /**
         * @brief  Function which returns Response SID
         * @return Service Response SID - uint8_t
         */
        uint8_t GetResponseSID() { return m_RES_SID; }

        /**
         * @brief Used to init response buffer
         */
        void InitResponseBuffer() {
            m_Response.Clear();
        }
        /**
         * @brief Adds byte to response buffer
         * @param data - uint8_t
         */
        void AddByteToRespBuffer(uint8_t data) { 
            m_Response.AddByte(data);
        }
        /**
         * @brief Sets response to be positive
         */
        void SendPositiveResponse() { m_Response[1] = m_RES_SID;}
        /**
         * @brief Sets response to be negative
         */
        void SendNegativeResponse() { m_Response[1] = 0x7F;}

        CAN_Message GetMessageResponse() { return m_Response;}
    protected:
        uint8_t m_REQ_SID{};
        uint8_t m_RES_SID{};
        CAN_Message m_Response{};
};