#pragma once

#include <cstdint>
#include <memory>
#include <vector>
#include <cstring>
#include "../../Log.h"

constexpr uint8_t MAX_CAN_MESSAGE_DATA_LENGTH = 0xFF;

class CAN_Message{
    public:
        CAN_Message() = default;
    public:
        uint8_t* data(){ return m_data.data();}
        uint8_t size() { return m_data.size();}
        const uint8_t size() const { return m_data.size();}

        void Set(uint32_t pos,uint8_t value){
            if(pos < m_data.size()){
                m_data[pos] = value;
            }
        }
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
        
        void AddByteArray(const uint8_t* data,uint32_t length){
            for(uint8_t i =0; i < length;i++)
                m_data.push_back(data[i]);
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
        uint8_t operator[](int index){
            return m_data[index];
        }


    private:
        std::vector<uint8_t> m_data;
};