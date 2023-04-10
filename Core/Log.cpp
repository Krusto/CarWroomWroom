#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>

template <typename T>
inline std::string int_to_hex(T val, size_t width=sizeof(T)*2)
{
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(width) << std::hex << (val|0);
    return ss.str();
}

#define LOG_USE_STD // replace this with wanted logger

#ifdef LOG_USE_STD
    #define LOG_INFO(...) printf(__VA_ARGS__);fflush(stdout)
    #define LOG_ERROR(x) printf("Error: %s \n",x);fflush(stdout)

    void log_can_message(){
        std::string canData = "";
        for(uint8_t i = 0; i < msg.size(); i++){\
            canData += int_to_hex(msg[i]) + " ";\
            }\
            LOG_INFO("%s { %s}\n",prefix,canData.data()); \
    }

    #define LOG_CAN_MESSAGE(prefix,msg)
#else
    #error "No Logger Defined!"
#endif
