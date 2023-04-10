#pragma once

#include "Socket.h"

#include <iostream>
#include <vector>
#include <sstream>
#include <chrono>
#include <thread>
#include <condition_variable>

class Client {
private:
#ifdef _WIN32
    SOCKET ConnectSocket;
#else
    int ConnectSocket;
#endif
    std::string address;
    int port;

    std::thread recvThread;
    bool stopReceiving = false;

    std::vector<char> m_messageBuffer;

public:
    Client() = default;
    Client(std::string address, int port);
    void Init(std::string address, int port);
    int Connect();
    int Send(char *sendbuf, int sendlen);
    static void ReceiveLoop(Client* client);
    void Close();

    bool suppressLog = false;

    std::condition_variable cv;
    std::mutex messageMutex;

    struct Data {
        std::vector<char> buffer;
        unsigned int size;
        bool received;
    };
    Data data;
};