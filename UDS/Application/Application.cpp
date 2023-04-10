#include "Application.h"
#include "Log.h"

#include <exception>

#ifdef _WIN32
#include <Windows.h>
#endif

void Application::Init()
{
    m_uds_manager = UDS_Manager::GetHandle();
    m_uds_manager->OnStart();
}

bool Application::Run()
{
    try{
        while(true){
            m_uds_manager->OnUpdate();
        }
    }catch(std::exception& e){
        LOG_ERROR(e.what());
        return false;
    }
    return true;
}

void Application::Destroy()
{
    m_uds_manager->OnStop();
}