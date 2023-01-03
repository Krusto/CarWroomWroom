#pragma once
#include "uds/uds_main.h"

class Application{
public:
    Application() = default;
    void Init();
    bool Run();
    void Destroy();
private:
    UDS_Manager* m_uds_manager;
};