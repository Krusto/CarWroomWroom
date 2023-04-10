#pragma once

#include <cstdint>
#include <memory>
#include <vector>
#include <cstring>

constexpr uint16_t MAX_CAN_MESSAGE_DATA_LENGTH = 0x1000;

class CAN_Message{
    public:
        CAN_Message() = default;
        ~CAN_Message(){m_data.clear();}
    public:
        uint8_t* data() { return m_data.data();}
        uint8_t size() { return m_data.size();}
        const uint8_t size() const { return m_data.size();}

        void AddByte(uint8_t value){
            if(m_data.size() + 1 < MAX_CAN_MESSAGE_DATA_LENGTH){
                m_data.push_back(value);
            }
        }
        void InsertByte(uint8_t pos,uint8_t value){
            if(m_data.size() + 1 < MAX_CAN_MESSAGE_DATA_LENGTH){
                if(pos < m_data.size()){
                    m_data.insert(m_data.begin() + pos,value);
                }
            }
        }
        void Clear(){
            m_data.clear();
        }
        
        void AddByteArray(uint8_t* data,uint32_t length){
            m_data.insert(m_data.end(),data,(data+length));
        }
        void AddByteArray(const std::vector<uint8_t>& data,uint32_t length){
            if(m_data.size() > 0){
                m_data.insert(m_data.end(),data.begin(),(data.begin()+length));
            }else{
                m_data.insert(m_data.begin(),data.begin(),(data.begin()+length));
            }
        }
        void AddByteArray(char* data,uint32_t length){
            if(m_data.size() > 0){
                m_data.insert(m_data.end(),data,(data+length));
            }else{
                m_data.insert(m_data.begin(),data,(data+length));
            }
        }
        void AddByteArray(const std::vector<char>& data,uint32_t length){
                        if(m_data.size() > 0){
                m_data.insert(m_data.end(),data.begin(),(data.begin()+length));
            }else{
                m_data.insert(m_data.begin(),data.begin(),(data.begin()+length));
            }
        }
    public:
        operator uint8_t*(){return m_data.data();}
        uint8_t& operator[](int index){
            return m_data.at(index);
        }


    private:
        std::vector<uint8_t> m_data{};
};