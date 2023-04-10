cmake_minimum_required(VERSION 3.10)
project(server)
include(CheckCXXCompilerFlag)

CHECK_CXX_COMPILER_FLAG("-std=c++2a" COMPILER_SUPPORTS_CXX20)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)

if (COMPILER_SUPPORTS_CXX20)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a")
elseif (COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else ()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++20 support. Please use a different C++ compiler.")
endif ()

include_directories(${CMAKE_SOURCE_DIR}/asio-1.24.0/include)
include_directories(${CMAKE_SOURCE_DIR}/libmicrohttpd/include)
link_directories(${CMAKE_SOURCE_DIR}/libmicrohttpd/lib)

add_executable(server main.cpp Server.h Server.cpp Socket.h Socket.cpp)

if (WIN32)
    target_link_libraries(server Ws2_32)
    target_link_libraries(server wsock32)
endif ()
if (UNIX)
    target_link_libraries(server pthread)
endif ()
