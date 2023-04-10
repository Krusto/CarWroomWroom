#pragma once

#include "Socket.h"

#include <iostream>
#include <thread>
#include <vector>
#include <sstream>
#include <chrono>

class Client {
private:
    SOCKET ConnectSocket;
    std::string address;
    int port;
    std::thread recvThread;
    bool stopReceiving = false;
public:
    Client(std::string address, int port);
    int Connect();
    int Send(char *sendbuf, int sendlen);
    static void ReceiveLoop(Client* client);
    void Close();
};