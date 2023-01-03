#pragma once
#include "service_handler.h"

#include <string_view>

class SessionHandler : public ServiceHandler{
public:
    SessionHandler() = default;
    virtual void Init() override{}
    virtual void Destroy() override{};
    virtual void MainHandle(CAN_Message message) override{};
    virtual void PostHandle() override{};
    static std::string_view GetName() { return "Session control handler";};
};
