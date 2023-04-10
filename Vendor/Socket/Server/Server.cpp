//
// Created by Krusto on 31-Jan-23.
//

#include <iostream>
#include <vector>
#include <cstring>
#include "Server.h"
#include "Socket.h"

Server::Server(ServerSpec spec) {
    this->m_spec = spec;
    s_clients.resize(spec.maxClients);
}

void Server::Init() {
    int result;
    result = InitSocket();
    if (result != 0) {
        std::cout << "WSAStartup failed with error: " << result << std::endl;
        exit(1);
    }

    m_socket = socket(AF_INET,SOCK_STREAM, IPPROTO_TCP);
    if (m_socket == INVALID_SOCKET) {
        std::cerr << "Failed to create server socket" << std::endl;
        DestroySocketContext();
        exit(1);
    }else{
        std::cout<<"Server started on "<<m_spec.address<<":"<<m_spec.port<<std::endl;
    }

    struct sockaddr_in saServer;
    saServer.sin_family = AF_INET;
    saServer.sin_port = htons(m_spec.port);
    inet_pton(AF_INET, m_spec.address.c_str(), &saServer.sin_addr);

    // Setup the TCP listening socket
    result = bind( m_socket, (sockaddr*)&saServer,sizeof(sockaddr));
    if (result == SOCKET_ERROR) {
        #ifdef _WIN32
        printf("bind failed with error: %d\n", WSAGetLastError());
        closesocket(m_socket);
        DestroySocketContext();
        #else
         printf("bind failed with error: %s\n", strerror(errno));
         close(m_socket);
        #endif
        exit(1);
    }
}
int Server::broadcastMessage(ServerSpec* spec,char* message,int length,int excludedClient) {
    int result;
    for (int i = 0; i < spec->maxClients; i++) {
        if (Server::s_clients[i] != 0 && i != excludedClient) {
            result = send(Server::s_clients[i], message, length, 0);
        }
    }
    return result;
}
void Server::handleClient(ServerSpec* spec,int clientIndex) {
    char recvBuf[spec->maxMessageBufferLength];
    auto ClientSocket = Server::s_clients[clientIndex];
    int receivedBytes = 0;
    do {
        receivedBytes = recv(ClientSocket, recvBuf, spec->maxMessageBufferLength, 0);
        if (receivedBytes > 0) {
            // Echo the buffer back to the sender
            // std::string response = "client["+std::to_string(clientIndex)+"]: ";
            // std::cout<<response;
            // std::cout.setf(std::ios::hex,std::ios::basefield);
            // for(int i = 0;i < receivedBytes;++i){
            //     std::cout<<((int)recvBuf[i]  & 0xFF)<< " ";
            // }
            // std::cout<<std::endl;

            int iSendResult = broadcastMessage(spec,recvBuf,receivedBytes,clientIndex);
            if (iSendResult == SOCKET_ERROR) {
#ifdef _WIN32
                printf("send failed: %x\n", WSAGetLastError());
                 closesocket(ClientSocket);
                WSACleanup();
#else
                std::cerr << "send failed: " << strerror(errno) << std::endl;
                close(ClientSocket);
#endif
                exit(1);
            }
        }else{
            std::string response = "Closing connection with client " +std::to_string(clientIndex)+"\n";
            std::cout << response;
#ifdef _WIN32
            closesocket(Server::s_clients[clientIndex]);
#else
            close(Server::s_clients[clientIndex]);
#endif
            Server::s_clients[clientIndex] = 0;
            spec->currentClientCount--;
        }

    } while (receivedBytes > 0);
}

void Server::Run() {
    if ( listen( m_socket, SOMAXCONN ) == SOCKET_ERROR ) {

#ifdef _WIN32
        printf("Listen failed with error: %x\n", WSAGetLastError());
        closesocket(m_socket);
        DestroySocketContext();
#else
        std::cerr << "Listen failed with error: " << strerror(errno) << std::endl;
        close(m_socket);
#endif
        exit(1);
    }else{
        std::cout<<"Listening..."<<std::endl;
    }

    bool shouldExit = false;
    while (!shouldExit) {
        sockaddr_in clientAddr;
        int clientAddrLen = sizeof(clientAddr);
        Socket client = accept(m_socket, (struct sockaddr*)&clientAddr, reinterpret_cast<socklen_t *>(&clientAddrLen));
        if (client != INVALID_SOCKET) {
            std::cout << "Accepted new client" << std::endl;
            if (m_spec.currentClientCount < m_spec.maxClients) {
                int clientIndex;
                for (clientIndex = 0; clientIndex < m_spec.maxClients; clientIndex++) {
                    if (s_clients[clientIndex] == 0) {
                        s_clients[clientIndex] = client;
                        break;
                    }
                }
                m_spec.currentClientCount++;
                m_clientHandlers.push_back(std::thread(handleClient,&m_spec, clientIndex));
            } else {
                std::cout << "Rejected new client: maximum number of clients already reached" << std::endl;
#ifdef _WIN32
                closesocket(client);
#else
                close(client);
#endif
            }
        }else{

#ifdef _WIN32
            printf("accept failed with error: %x\n", WSAGetLastError());
            closesocket(m_socket);
            DestroySocketContext();
#else
            std::cerr << "accept failed with error: " << strerror(errno) << std::endl;
            close(m_socket);
#endif

            exit(1);
        }
    }
}

void Server::Stop() {
    for (std::thread& clientHandler : m_clientHandlers) {
        clientHandler.join();
    }
    DestroySocketContext();
}
