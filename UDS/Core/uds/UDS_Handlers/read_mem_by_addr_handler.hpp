#pragma once

#include "service_handler.h"

#include <string_view>

class ReadMemByAddressHandler : public ServiceHandler {
public:
    ReadMemByAddressHandler();

    virtual void Init() override {}

    virtual void Destroy() override {};

    virtual void MainHandle(Message message) override;

    virtual void PostHandle() override;

    static std::string_view GetName() { return "ReadMemoryByAddress handler"; };

private:
    int ReadData(uint32_t address,uint32_t size);
};