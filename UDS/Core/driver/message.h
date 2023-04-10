#pragma once
#include <memory>
#include <vector>
#include <cstring>
#include <iostream>

class Message{
    public:
        Message() = default;
        Message(const Message&) = default;
        ~Message(){}
    public:
        auto& data() { return m_data;}
        const auto& data() const{ return m_data;}
        
        uint32_t length() { return m_length;}
        const uint32_t length() const { return m_length;}

        void AddByte(uint8_t value){
            if(m_length + 1 < m_max_length){
                m_data[m_length] = value;
                m_length++;
            }
        }
        void InsertByte(uint8_t pos,uint8_t value){
            if(pos < m_max_length && pos <= m_length && m_length+1 < m_max_length){
                uint8_t* temp = new uint8_t[m_length-pos];
                memcpy(temp,&m_data[pos],m_length-pos);
                m_data[pos] = value;
                memcpy(&m_data[pos+1],temp,m_length-pos);
                m_length++;
                delete[] temp;
            }
        }
      
        void AddByteArray(uint8_t* data,uint32_t length){
            TryInit();
            if(m_length + length < m_max_length){
                memcpy(&m_data[m_length],data,length);
                m_length +=length;
            }else{
                memcpy(&m_data[m_length],data,(m_max_length-m_length));
                m_length +=m_max_length-m_length;
            }
        }
        void AddByteArray(const std::vector<uint8_t>& data,uint32_t length){
            TryInit();
            if(m_length + length < m_max_length){
                memcpy(&m_data[m_length],data.data(),length);
                m_length +=length;
            }else{
                memcpy(&m_data[m_length],data.data(),(m_max_length-m_length));
                m_length +=m_max_length-m_length;
            }
        }

        void AddByteArray(char* data,uint32_t length){
            TryInit();
            if(m_length + length < m_max_length){
                memcpy(&m_data[m_length],data,length);
                m_length +=length;
            }else{
                memcpy(&m_data[m_length],data,(m_max_length-m_length));
                m_length +=m_max_length-m_length;
            }
        }
        void AddByteArray(const std::vector<char>& data,uint32_t length){
            TryInit();
            if(m_length + length < m_max_length){
                memcpy(&m_data[m_length],data.data(),length);
                m_length +=length;
            }else{
                memcpy(&m_data[m_length],data.data(),(m_max_length-m_length));
                m_length +=m_max_length-m_length;
            }
        }

        void Clear(){
            memset(m_data,0,m_length);
            m_length = 0;
        }
        
    public:
        uint8_t& operator[](int index){
            return m_data[index];
        }
    private:
        void TryInit(){}
    private:
        uint8_t m_data[4096];
        uint32_t m_max_length{4096};
        uint32_t m_length{};
};