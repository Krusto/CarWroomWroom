#pragma once

#include <cstdint>
#include <memory>
#include <vector>
#include <cstring>

constexpr uint8_t MAX_CAN_MESSAGE_DATA_LENGTH = 0xFF;

struct CAN_Message{
    public:
        CAN_Message() = default;
        CAN_Message(uint8_t* data,uint8_t size){
            if(size < 0xFF){
                memcpy(&m_data[0],data,size);
                m_Offset = 0;
                m_size  = size;
            }
        }
        uint8_t* data() { return &m_data[m_Offset];}
        uint8_t& size() { return m_size;}
        const uint8_t& size() const { return m_size;}
        CAN_Message* Offset(uint32_t nBytes){
            m_Offset += nBytes;
            m_size  -= nBytes;
            return this;
        }
        void AddByte(uint8_t byte){
            if(m_size + 1 < MAX_CAN_MESSAGE_DATA_LENGTH){
                m_data[0] += 1;
                m_data[m_size] = byte;
                m_size++;
            }
        }
        void Clear(){
            m_size = 2;
            m_Offset = 0;
            memset(m_data,0,MAX_CAN_MESSAGE_DATA_LENGTH);
            m_data[0] = 1;
        }
        operator uint8_t*(){return &m_data[m_Offset];}
        uint8_t& operator[](int index){
            return m_data[m_Offset + index];
        }

    private:
        uint8_t m_data[MAX_CAN_MESSAGE_DATA_LENGTH];
        uint8_t m_Offset{};
        uint8_t m_size;
};