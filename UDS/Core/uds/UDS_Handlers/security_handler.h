#pragma once
#include "service_handler.h"

#include <string_view>

class SecurityAccessHandler : public ServiceHandler{
public:
    SecurityAccessHandler();
    virtual void Init() override{}
    virtual void Destroy() override{};
    virtual void MainHandle(Message message) override;
    virtual void PostHandle() override;
    static std::string_view GetName() { return "Security access control handler";};

private:
    uint8_t RequestSeed(Message& message);
    uint8_t SendKey(Message& message);

    uint64_t m_ExpectedKey{};
    uint64_t m_Seed{};
};