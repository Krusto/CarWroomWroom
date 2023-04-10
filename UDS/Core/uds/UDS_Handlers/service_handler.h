#pragma once
#include "../../driver/message_drv.h"
#include "uds_definitions.h"
#include "session_data.hpp"

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
     * @param message Message received from the communication driver
     */
    virtual void MainHandle(Message message) = 0;

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
        m_Response.AddByte(0);
        m_Response.AddByte(0);
    }

    /**
     * @brief Adds byte to response buffer
     * @param data - uint8_t
     */
    void AddByteToRespBuffer(uint8_t data) {
        m_Response.AddByte(data);
        m_Response.data()[0] += 1;
    }
    /**
     * @brief Adds byte array to response buffer
     * @param data - uint8_t* data buffer
     * @param length - data buffer length in bytes
     */
    void AddByteArrayToRespBuffer(uint8_t* data,uint32_t length) {
        for (uint32_t i = 0; i < length; ++i){
            m_Response.AddByte(data[i]);
        }
        m_Response.data()[0] += length;
    }

    /**
     * @param sub_function - subfunction number (0x00:0xFF- subfunction, 0x01FF:0xFFFF - ignore)
     * @brief Sets response to be positive
     */
    void SendPositiveResponse(uint16_t sub_function = 0x01FF) {
        m_Response.data()[1] = m_RES_SID;
        if(sub_function < 0x01FF){
            m_Response.InsertByte(2,sub_function);
            m_Response.data()[0] += 1;
        }
        m_Response.data()[0] += 1;

    }

    /**
     * @brief Sets response to be negative
     */
    void SendNegativeResponse(uint16_t code = 0xFF00) {
        if(code != 0xFF){
            AddByteToRespBuffer(code & 0xFF);
            m_Response.data()[0] += 1;
        }
        m_Response.data()[0] += 1;
        m_Response.data()[1] = UDS_NEGATIVE_RESPONSE_SID;
        m_Response.InsertByte(2, m_REQ_SID);
    }

    Message& GetResponseMessage() { return m_Response; }

    static SessionData currentSession;

protected:

    uint8_t m_REQ_SID{};
    uint8_t m_RES_SID{};
    Message m_Response{};

};