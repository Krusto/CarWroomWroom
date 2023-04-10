#include "Client.h"
#include <mutex>
#include <cstring>

#define DEFAULT_BUFLEN 512

std::mutex m;

Client::Client(std::string address, int port) : address(address), port(port), ConnectSocket(INVALID_SOCKET) {}

void Client::Init(std::string address, int port) {
    this->address = address;
    this->port = port;
    this->ConnectSocket = INVALID_SOCKET;
}

int Client::Connect() {
    int iResult;

    #ifdef _WIN32
    iResult = InitSocket();
    if (iResult != 0) {
        std::cout << "WSAStartup failed with error: " << iResult << std::endl;
        return 1;
    }
    #endif

    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(this->port);
    inet_pton(AF_INET, this->address.c_str(), &server_address.sin_addr);

    while (ConnectSocket == INVALID_SOCKET) {
        ConnectSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (ConnectSocket == INVALID_SOCKET) {
#ifdef _WIN32
            printf("Socket failed with error: %x\n", WSAGetLastError());
            closesocket(ConnectSocket);
            DestroySocketContext();
#else
            std::cerr << "Socket failed with error: " << std::strerror(errno) << std::endl;
            close(ConnectSocket);
#endif
            continue;
        }
        std::cout << "Connecting to " << address << ":" << port << "..." << std::endl;
        iResult = connect(ConnectSocket, (sockaddr *) &server_address, sizeof(server_address));
        if (iResult == SOCKET_ERROR) {
            #ifdef _WIN32
            closesocket(ConnectSocket);
            #else
            close(ConnectSocket);
            #endif
            ConnectSocket = INVALID_SOCKET;
        }

        if (ConnectSocket == INVALID_SOCKET) {
            std::cout << "Unable to connect to server!" << std::endl;
        }
    }

    std::cout << "Connected to server" << std::endl;

    recvThread = std::thread(Client::ReceiveLoop, this);
    return 0;
}

int Client::Send(char *sendbuf, int sendlen) {
    std::lock_guard<std::mutex> lock(m);
    int iResult = send(ConnectSocket, sendbuf, sendlen, 0);

    if (iResult == SOCKET_ERROR) {
        #ifdef _WIN32
        std::cout << "Send failed with error: " << WSAGetLastError() << std::endl;
        closesocket(ConnectSocket);
        #else
        std::cout << "Send failed with error: " << strerror(errno) << std::endl;
        close(ConnectSocket);
        #endif

        DestroySocketContext();
        return 1;
    }

    return iResult;
}

void Client::ReceiveLoop(Client *client) {

    for (int i = 0; i < DEFAULT_BUFLEN; i++) {
        client->m_messageBuffer.push_back(0);
    }

    int iResult;
    while (!client->stopReceiving) {
        iResult = recv(client->ConnectSocket, &client->m_messageBuffer[0], DEFAULT_BUFLEN, 0);
        if (iResult > 0) {
            {
                std::unique_lock<std::mutex> lock(client->messageMutex);
                client->data.size = iResult;
                client->data.received = true;
                for (int i = 0; i < iResult; i++)
                    client->data.buffer.push_back(client->m_messageBuffer[i]);
            }
            client->cv.notify_one();

            if (!client->suppressLog) {
                for (int i = 0; i < iResult; i++) {
                    std::cout << std::hex << std::uppercase << ((int) client->m_messageBuffer[i] & 0xFF) << " ";
                }
                std::cout << "          ";
                for (int i = 2; i < iResult; i++) {
                    int value = ((int) client->m_messageBuffer[i] & 0xFF);
                    if((value >= '0' && value <= '9') || (value >= 'a' && value <='z') || (value >= 'A' && value <= 'Z')) {
                        std::cout << (char)(client->m_messageBuffer[i] & 0xFF);
                    }else{
                        std::cout<<'.';
                    }
                }
                std::cout << std::endl << std::endl;

            }
        } else if (iResult == 0) {
            std::cout << "Closing connection" << std::endl;
        } else {
            #ifdef _WIN32
            printf("recv failed with error: %d\n", WSAGetLastError());
            #else
            std::cout << "recv failed with error: " << strerror(errno) << std::endl;
            #endif
            std::cin.ignore();
            exit(1);
        }

    }
}

void Client::Close() {
    std::cout << "Closing" << std::endl;

    stopReceiving = true;
    recvThread.detach();

    #ifdef _WIN32
    closesocket(ConnectSocket);
    DestroySocketContext();
    #else
    close(ConnectSocket);
    #endif
}
