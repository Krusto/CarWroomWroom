#pragma once
#include <memory>
#include <vector>
#include <cstring>
#include <iostream>

class Message{
    public:
        Message() = default;
        Message(const Message&) = default;
    public:
        auto& data() { return m_data;}
        const auto& data() const{ return m_data;}
        
        uint8_t length() { return m_data.size();}
        const uint8_t length() const { return m_data.size();}

        void AddByte(uint8_t value){
            if(m_data.size() + 1 < m_max_length){
                m_data.push_back(value);
            }
        }
        void InsertByte(uint8_t pos,uint8_t value){
            if(pos < m_max_length && pos <= m_data.size() && m_data.size()+1 < m_max_length){
                uint8_t* temp = new uint8_t[m_data.size()-pos];
                memcpy(temp,&m_data[pos],m_data.size()-pos);
                m_data.push_back(0);
                m_data[pos] = value;
                memcpy(&m_data[pos+1],temp,m_data.size()-pos);
                delete[] temp;
            }
        }
      
        void AddByteArray(uint8_t* data,uint32_t length){
            if(m_data.size() + length < m_max_length){
                m_data.insert(m_data.end(),data,(data+length));
            }else{
                m_data.insert(m_data.end(),data,(data+(m_max_length-m_data.size())));
            }
        }
        void AddByteArray(const std::vector<uint8_t>& data,uint32_t length){
            if(m_data.size() + length < m_max_length){
                m_data.insert(m_data.end(),data.begin(),(data.begin()+length));
            }else{
                m_data.insert(m_data.end(),data.begin(),(data.begin()+(m_max_length-m_data.size())));
            }
        }

        void AddByteArray(char* data,uint32_t length){
            if(m_data.size() + length < m_max_length){
                m_data.insert(m_data.end(),data,(data+length));
            }else{
                m_data.insert(m_data.end(),data,(data+(m_max_length-m_data.size())));
            }
        }
        void AddByteArray(const std::vector<char>& data,uint32_t length){
            if(m_data.size() + length < m_max_length){
                m_data.insert(m_data.end(),data.begin(),(data.begin()+length));
            }else{
                m_data.insert(m_data.end(),data.begin(),(data.begin()+(m_max_length-m_data.size())));
            }
        }

        void Clear(){
            memset(m_data.data(),0,m_data.size());
        }
        
    public:
        uint8_t operator[](int index){
            return m_data[index];
        }

    private:
        std::vector<uint8_t> m_data{};
        uint32_t m_max_length{4096};
};