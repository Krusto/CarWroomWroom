#pragma once
#include "UDS_Handlers/service_handler.h"

#include <memory>
#include <string_view>
#include <unordered_map>
#include <string>

class ServiceHandlerSystem{
    public:
        ServiceHandlerSystem() = default;
        /**
         * @brief Register new handler to the UDS with name
         * @param name Human readable SID format - string_view
         * @param serviceHandler Instance of the new service handler - shared_ptr<ServiceHandler>
         */
        static void RegisterHandle(std::string_view name,std::shared_ptr<ServiceHandler> serviceHandler);
        /**
         * @brief If handle with name exists it is removed from the registered handlers
         * @param name Name of the registered handler to be removed - string_view
         */
        static void DestroyHandle(std::string_view name);

        /**
         * @brief Used to get list of all handlers
         * @return Reference to registered handlers
         */
        static auto& GetHandlers() { return ServiceHandlerSystem::s_ServiceHandlerSystemMap; }
    private:
        static inline std::unordered_map<std::string_view,std::shared_ptr<ServiceHandler>> s_ServiceHandlerSystemMap;
};