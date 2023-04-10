cmake_minimum_required(VERSION 3.0.0)
project(UDS VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

include(CheckCXXCompilerFlag)

add_subdirectory("${CMAKE_SOURCE_DIR}/Vendor/Socket/Client")
add_subdirectory("${CMAKE_SOURCE_DIR}/Vendor/Socket/Server")

add_compile_options("-g")

include_directories(
        ${CMAKE_SOURCE_DIR}/UDS/Core
        ${CMAKE_SOURCE_DIR}/UDS/Core/can
        ${CMAKE_SOURCE_DIR}/UDS/Core/uds
        ${CMAKE_SOURCE_DIR}/Vendor/Socket/Client
)

#UDS_app
add_executable(UDS_app
        ${CMAKE_SOURCE_DIR}/UDS/main.cpp
        ${CMAKE_SOURCE_DIR}/UDS/Application/Application.cpp
        ${CMAKE_SOURCE_DIR}/UDS/Core/uds/uds_definitions.cpp
        ${CMAKE_SOURCE_DIR}/UDS/Core/uds/uds_handler.cpp
        ${CMAKE_SOURCE_DIR}/UDS/Core/uds/uds_main.cpp
        ${CMAKE_SOURCE_DIR}/UDS/Core/uds/UDS_Handlers/routine_handler.cpp
        ${CMAKE_SOURCE_DIR}/UDS/Core/uds/UDS_Handlers/session_handler.cpp
        ${CMAKE_SOURCE_DIR}/UDS/Core/uds/UDS_Handlers/security_handler.cpp
        ${CMAKE_SOURCE_DIR}/UDS/Core/uds/UDS_Handlers/tester_present_handler.cpp
        ${CMAKE_SOURCE_DIR}/UDS/Core/uds/UDS_Handlers/read_data_by_id_handler.cpp
        ${CMAKE_SOURCE_DIR}/UDS/Core/uds/UDS_Handlers/read_mem_by_addr_handler.cpp
        ${CMAKE_SOURCE_DIR}/UDS/Core/uds/UDS_Handlers/write_mem_by_addr_handler.cpp
        ${CMAKE_SOURCE_DIR}/UDS/Core/uds/UDS_Handlers/session_data.cpp
        ${CMAKE_SOURCE_DIR}/UDS/Core/uds/UDS_Handlers/memory.cpp
        ${CMAKE_SOURCE_DIR}/UDS/Core/driver/can/can_handler.cpp
        ${CMAKE_SOURCE_DIR}/UDS/Core/driver/message_drv.cpp
        ${CMAKE_SOURCE_DIR}/Vendor/Socket/Client/Client.cpp
        ${CMAKE_SOURCE_DIR}/Vendor/Socket/Client/Socket.cpp
        )

target_include_directories(UDS_app PRIVATE
                ${CMAKE_SOURCE_DIR}/UDS/Core
                ${CMAKE_SOURCE_DIR}/UDS/Core/can
                ${CMAKE_SOURCE_DIR}/UDS/Core/uds
                ${CMAKE_SOURCE_DIR}/Vendor/Socket/Client)
if (WIN32)
    target_link_libraries(UDS_app Ws2_32)
    target_link_libraries(UDS_app wsock32)
endif ()
if (UNIX)
    target_link_libraries(UDS_app pthread)
endif ()

#UDS_tester

add_executable(UDS_tester
        ${CMAKE_SOURCE_DIR}/Tester/src/main.cpp
        ${CMAKE_SOURCE_DIR}/Tester/src/Application/Application.cpp
        ${CMAKE_SOURCE_DIR}/Tester/src/Core/File.cpp
        ${CMAKE_SOURCE_DIR}/Tester/src/Core/uds/uds_definitions.cpp
        ${CMAKE_SOURCE_DIR}/Tester/src/Core/driver/can/can_handler.cpp
        ${CMAKE_SOURCE_DIR}/Tester/src/Core/driver/message_drv.cpp
        ${CMAKE_SOURCE_DIR}/Vendor/Socket/Client/Client.cpp
        ${CMAKE_SOURCE_DIR}/Vendor/Socket/Client/Socket.cpp
        )

target_include_directories(UDS_tester PRIVATE
                ${CMAKE_SOURCE_DIR}/Tester/src
                ${CMAKE_SOURCE_DIR}/Vendor/Socket/Client)
                
if (WIN32)
    target_link_libraries(UDS_tester Ws2_32)
    target_link_libraries(UDS_tester wsock32)
endif ()
if (UNIX)
    target_link_libraries(UDS_tester pthread)
endif ()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
