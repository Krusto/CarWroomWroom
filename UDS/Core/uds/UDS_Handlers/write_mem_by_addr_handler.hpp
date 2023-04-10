#pragma once

#include "service_handler.h"

#include <string_view>

class WriteMemByAddressHandler : public ServiceHandler {
public:
    WriteMemByAddressHandler();

    virtual void Init() override {}

    virtual void Destroy() override {};

    virtual void MainHandle(Message message) override;

    virtual void PostHandle() override;

    static std::string_view GetName() { return "WriteMemByAddress handler"; };

private:
    int WriteData(uint32_t address,uint32_t size,Message& message,uint8_t messageOffset);
};