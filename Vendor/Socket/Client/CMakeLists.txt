cmake_minimum_required(VERSION 3.10)
project(client)
set(CMAKE_VERBOSE_MAKEFILE on)

message("Compiler Version: ${CMAKE_CXX_COMPILER_VERSION}")

CHECK_CXX_COMPILER_FLAG("-std=c++2b" COMPILER_SUPPORTS_CXX20)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)

if (COMPILER_SUPPORTS_CXX20)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2b")
elseif (COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else ()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++20 support. Please use a different C++ compiler.")
endif ()

add_executable(client main.cpp Client.cpp Client.h Socket.cpp Socket.h)

if (WIN32)
    target_link_libraries(client Ws2_32)
    target_link_libraries(client wsock32)
endif ()
if (UNIX)
    target_link_libraries(client pthread)
endif ()
