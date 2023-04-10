#pragma once
#include <cstdint>

class Memory {
public:
    static uint8_t ReadFromEEPROM(uint32_t address,uint8_t& value);
    static uint8_t WriteToEEPROM(uint32_t address,uint8_t value);
    static uint8_t ReadBufferFromEEPROM(uint32_t address,uint8_t* buffer,uint32_t bufferSize);
    static uint8_t WriteBufferToEEPROM(uint32_t address,uint8_t* buffer,uint32_t bufferSize);

    static void InitEEPROM();
protected:
    static inline int s_EEPROM_fd{0};
    static inline uint8_t* s_EEPROM{nullptr};
};
