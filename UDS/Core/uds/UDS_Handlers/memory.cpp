#include "memory.hpp"

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

uint8_t Memory::ReadFromEEPROM(uint32_t address, uint8_t &value) {
    if (Memory::s_EEPROM_fd != 0) {
        auto offset = lseek(Memory::s_EEPROM_fd, address, SEEK_SET);
        if (offset == -1) {
            perror("offset");
            return 1;
        }
        ssize_t readByteCount = read(Memory::s_EEPROM_fd, &value, 1);
        if (readByteCount == -1) {
            perror("read");
            return 1;
        }
    }
    return 0;
}

uint8_t Memory::ReadBufferFromEEPROM(uint32_t address, uint8_t *buffer, uint32_t bufferSize) {
    if (Memory::s_EEPROM_fd != 0) {
        auto offset = lseek(Memory::s_EEPROM_fd, address, SEEK_SET);
        if (offset == -1) {
            perror("offset");
            return 1;
        }
        ssize_t readByteCount = read(Memory::s_EEPROM_fd, buffer, bufferSize);
        if (readByteCount == -1) {
            perror("read");
            return 1;
        }
    }
    return 0;
}

uint8_t Memory::WriteToEEPROM(uint32_t address, uint8_t value) {

    if (Memory::s_EEPROM_fd != 0) {
        auto offset = lseek(Memory::s_EEPROM_fd, address, SEEK_SET);
        if (offset == -1) {
            perror("offset");
            return 1;
        }
        ssize_t writtenByteCount = write(Memory::s_EEPROM_fd, &value, 1);
        if (writtenByteCount == -1 || writtenByteCount != 1) {
            perror("read");
            return 1;
        }
    }

    return 0;
}

uint8_t Memory::WriteBufferToEEPROM(uint32_t address, uint8_t *buffer, uint32_t bufferSize) {
    if (Memory::s_EEPROM_fd != 0) {
        auto offset = lseek(Memory::s_EEPROM_fd, address, SEEK_SET);
        if (offset == -1) {
            perror("offset");
            return 1;
        }
        ssize_t writtenByteCount = write(Memory::s_EEPROM_fd, buffer, bufferSize);
        if (writtenByteCount == -1 || writtenByteCount != bufferSize) {
            perror("read");
            return 1;
        }
    }

    return 0;
}

void Memory::InitEEPROM() {
    Memory::s_EEPROM_fd = open("/dev/eeprom", O_RDWR);
    if (Memory::s_EEPROM_fd == -1)
        perror("open");
}
