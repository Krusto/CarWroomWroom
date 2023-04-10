#include "Application.h"
#include "../Core/Log.h"

#include <fstream>
#include <string>
#include <stdlib.h>
#include <filesystem>
#include <thread>
#include <chrono>

#ifdef _WIN32
#include <Windows.h>
#endif

void Application::Init()
{
    m_MSG_Handler.Init(CommunicationDriver::CAN);
}

bool Application::Run()
{
    LOG_INFO("Working directory: %s\n",std::filesystem::current_path().string().c_str());

    std::fstream file("./tests/test1.txt",std::ios::in);
    if(file.good()) {
        std::string line;
        std::vector<uint8_t> bytes;
        while(std::getline(file,line)){
            size_t pos = 0;
            while ((pos = line.find(" ")) != std::string::npos) {
                bytes.push_back((uint8_t)strtol(line.substr(0, pos).c_str(),NULL,16));
                line.erase(0, pos + std::string(" ").length());
            }
            bytes.push_back((uint8_t)strtol(line.c_str(),NULL,16));

            Message request;
            request.AddByteArray(bytes.data(),bytes.size());
            //LOG_INFO("Size: %d \n",(uint32_t)bytes.size());
            //LOG_MESSAGE("Sending: ",request);
            m_MSG_Handler.SendMessage(request);
            bytes.clear();
            std::this_thread::sleep_for (std::chrono::milliseconds(10));
            //auto serverResponse = m_MSG_Handler.WaitForMessage();
            //LOG_MESSAGE("Response: ",serverResponse);
        }
    }

    return true;
}

void Application::Destroy()
{
    m_MSG_Handler.Destroy();
}