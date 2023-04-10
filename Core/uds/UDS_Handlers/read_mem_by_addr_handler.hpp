#pragma once

#include "service_handler.h"

#include <string_view>

class ReadMemByAddressHandler : public ServiceHandler {
public:
    ReadDataByIdentifierHandler();

    virtual void Init() override {}

    virtual void Destroy() override {};

    virtual void MainHandle(CAN_Message message) override;

    virtual void PostHandle() override;

    static std::string_view GetName() { return "ReadDataByIdentifier handler"; };

private:
    int HandleDID(uint16_t did, CAN_Message& message);
};