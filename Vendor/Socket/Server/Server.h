//
// Created by Krusto on 31-Jan-23.
//
#pragma once
#include <string>
#include <thread>
#include <vector>

#include "Socket.h"

enum class ProtocolType{
    NONE = 0,
    TCP,
    UDP,
};
enum class MessageType{
    None = 0,
    Binary,
    Ascii
};

struct ServerSpec{
    std::string address;
    int port;
    ProtocolType protocolType = ProtocolType::TCP;
    int maxClients = 5;
    int currentClientCount = 0;
    int maxMessageBufferLength = 4096;
};
class Server {
public:
    Server() = default;
    Server(ServerSpec spec);

    void Init();
    void Run();
    void Stop();
private:

    static int broadcastMessage(ServerSpec* spec,char* message,int length);

    static void handleClient(ServerSpec* spec,int clientIndex);

    ServerSpec m_spec;
    Socket m_socket{};
    std::vector<std::thread> m_clientHandlers;

    inline static std::vector<Socket> s_clients;

};

