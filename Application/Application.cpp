#include "Application.h"
#include "Log.h"

#include <exception>
#include <Windows.h>

void Application::Init()
{
    m_uds_manager = UDS_Manager::GetHandle();
    LOG_INFO("Init");
    m_uds_manager->OnStart();
}

bool Application::Run()
{
    try{
        while(true){
            LOG_INFO("Loop");
            m_uds_manager->OnUpdate();
        }
        return true;
    }catch(std::exception& e){
        LOG_ERROR(e.what());
        return false;
    }
}

void Application::Destroy()
{
    m_uds_manager->OnStop();
}