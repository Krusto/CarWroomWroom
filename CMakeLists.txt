cmake_minimum_required(VERSION 3.0.0)
project(CanLogParser VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

include(CheckCXXCompilerFlag)

add_subdirectory("${CMAKE_SOURCE_DIR}/Vendor/Socket/Client")
add_subdirectory("${CMAKE_SOURCE_DIR}/Vendor/Socket/Server")

add_compile_options("-g")

include_directories(
        ${CMAKE_SOURCE_DIR}/Core
        ${CMAKE_SOURCE_DIR}/Core/can
        ${CMAKE_SOURCE_DIR}/Core/uds
        ${CMAKE_SOURCE_DIR}/Vendor/Socket/Client
)

add_executable(CanLogParser
        ${CMAKE_SOURCE_DIR}/main.cpp
        ${CMAKE_SOURCE_DIR}/Application/Application.cpp
        ${CMAKE_SOURCE_DIR}/Core/uds/uds_definitions.cpp
        ${CMAKE_SOURCE_DIR}/Core/uds/uds_handler.cpp
        ${CMAKE_SOURCE_DIR}/Core/uds/uds_main.cpp
        ${CMAKE_SOURCE_DIR}/Core/uds/UDS_Handlers/routine_handler.cpp
        ${CMAKE_SOURCE_DIR}/Core/uds/UDS_Handlers/session_handler.cpp
        ${CMAKE_SOURCE_DIR}/Core/uds/UDS_Handlers/security_handler.cpp
        ${CMAKE_SOURCE_DIR}/Core/uds/UDS_Handlers/tester_present_handler.cpp
        ${CMAKE_SOURCE_DIR}/Core/uds/UDS_Handlers/session_data.cpp
        ${CMAKE_SOURCE_DIR}/Core/can/can_handler.cpp
        ${CMAKE_SOURCE_DIR}/Vendor/Socket/Client/Client.cpp
        ${CMAKE_SOURCE_DIR}/Vendor/Socket/Client/Socket.cpp
        )

if(WIN32)
target_link_libraries(CanLogParser Ws2_32)
target_link_libraries(CanLogParser wsock32)
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
