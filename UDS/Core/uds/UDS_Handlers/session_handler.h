#pragma once
#include "service_handler.h"

#include <string_view>

class SessionHandler : public ServiceHandler{
public:
    SessionHandler();
    virtual void Init() override{}
    virtual void Destroy() override{};
    virtual void MainHandle(Message message) override;
    virtual void PostHandle() override;
    static std::string_view GetName() { return "Session control handler";};

};
