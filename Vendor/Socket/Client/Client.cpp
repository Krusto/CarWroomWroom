#include "client.h"

#define DEFAULT_BUFLEN 512
std::mutex m;

Client::Client(std::string address, int port) : address(address), port(port), ConnectSocket(INVALID_SOCKET) {}

int Client::Connect() {
    int iResult;
    struct addrinfo *result = NULL, *ptr = NULL;
    struct addrinfo  hints;

    iResult = InitSocket();
    if (iResult != 0) {
        std::cout << "WSAStartup failed with error: " << iResult << std::endl;
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    iResult = getaddrinfo(address.c_str(), std::to_string(port).c_str(), &hints, &result);
    if (iResult != 0) {
        std::cout << "getaddrinfo failed with error: " << iResult << std::endl;
        WSACleanup();
        return 1;
    }

    ptr = result;
    while(ConnectSocket == INVALID_SOCKET) {
        ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        if (ConnectSocket == INVALID_SOCKET) {
            std::cout << "socket failed with error: " << WSAGetLastError() << std::endl;
            continue;
        }
        std::cout << "Connecting to " << address << ":" << port << "..." << std::endl;
        iResult = connect(ConnectSocket, ptr->ai_addr, (int) ptr->ai_addrlen);
        if (iResult == SOCKET_ERROR) {
            closesocket(ConnectSocket);
            ConnectSocket = INVALID_SOCKET;
        }

        if (ConnectSocket == INVALID_SOCKET) {
            std::cout << "Unable to connect to server!" << std::endl;
        }
    }
    freeaddrinfo(result);

    std::cout<<"Connected to server" << std::endl;

    recvThread = std::thread(Client::ReceiveLoop,this);
    return 0;
}

int Client::Send(char *sendbuf, int sendlen) {
    std::lock_guard<std::mutex> lock(m);
    int iResult = send(ConnectSocket, sendbuf, sendlen, 0);

    if (iResult == SOCKET_ERROR) {
        std::cout << "Send failed with error: " << WSAGetLastError() << std::endl;
        closesocket(ConnectSocket);
        DestroySocketContext();
        return 1;
    }

    return iResult;
}

void Client::ReceiveLoop(Client* client) {
    char recvbuf[DEFAULT_BUFLEN];
    int recvlen = DEFAULT_BUFLEN;
    int iResult;
    while(!client->stopReceiving) {
        iResult = recv(client->ConnectSocket, recvbuf, recvlen, 0);
        if (iResult > 0) {
            recvlen = iResult;
            std::cout << "Received " << recvlen << " bytes: ";
            for (int i = 0; i < recvlen; i++) {
                std::cout << std::hex << std::uppercase << ((int) recvbuf[i]&0xFF) << " ";
            }
            std::cout << std::endl;
        }
    }
}

void Client::Close() {
    stopReceiving = true;
    recvThread.detach();
    closesocket(ConnectSocket);
    DestroySocketContext();
}
