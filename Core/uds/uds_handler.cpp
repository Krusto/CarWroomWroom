#include "uds_handler.h"

void ServiceHandlerSystem::RegisterHandle(std::string_view name, std::shared_ptr<ServiceHandler> serviceHandler)
{
    ServiceHandlerSystem::s_ServiceHandlerSystemMap.try_emplace(name,serviceHandler);
}

void ServiceHandlerSystem::DestroyHandle(std::string_view name)
{
    if(ServiceHandlerSystem::s_ServiceHandlerSystemMap.count(name))
        ServiceHandlerSystem::s_ServiceHandlerSystemMap.erase(name);
}
