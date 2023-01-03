cmake_minimum_required(VERSION 3.0.0)
project(CanLogParser VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

add_compile_options("-g")

include_directories(
    ${CMAKE_SOURCE_DIR}/Core
    ${CMAKE_SOURCE_DIR}/Core/can
    ${CMAKE_SOURCE_DIR}/Core/uds
)

add_executable(CanLogParser
    ${CMAKE_SOURCE_DIR}/main.cpp   
    ${CMAKE_SOURCE_DIR}/Application/Application.cpp   
    ${CMAKE_SOURCE_DIR}/Core/uds/uds_handler.cpp
    ${CMAKE_SOURCE_DIR}/Core/uds/uds_main.cpp
    ${CMAKE_SOURCE_DIR}/Core/uds/UDS_Handlers/routine_handler.cpp
    ${CMAKE_SOURCE_DIR}/Core/uds/UDS_Handlers/session_handler.cpp
    ${CMAKE_SOURCE_DIR}/Core/can/can_handler.cpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
