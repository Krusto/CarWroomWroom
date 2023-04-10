#pragma once
#include "../Core/driver/message_drv.h"

class Application{
public:
    Application() = default;
    void Init();
    bool Run();
    void Destroy();
private:
    MessageHandler m_MSG_Handler;
};