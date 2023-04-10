#pragma once
#include "service_handler.h"

#include <string_view>

class RoutineHandler : public ServiceHandler{
public:
    RoutineHandler();
    virtual void Init() override{}
    virtual void Destroy() override{};
    virtual void MainHandle(Message message) override;
    virtual void PostHandle() override;
    static std::string_view GetName() { return "Routine control handler";};
};