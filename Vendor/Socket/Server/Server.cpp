//
// Created by Krusto on 31-Jan-23.
//

#include <iostream>
#include <vector>
#include "Server.h"

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

    struct addrinfo  hints;
    ZeroMemory(&hints, sizeof (hints));
    struct sockaddr_in saServer;

    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    switch(m_spec.protocolType){
        case ProtocolType::TCP:
            hints.ai_protocol = IPPROTO_TCP;
            break;
        case ProtocolType::UDP:
            hints.ai_protocol = IPPROTO_UDP;
            break;
        case ProtocolType::NONE:
            break;
    }
    hints.ai_flags = AI_PASSIVE;

    m_socket = socket(hints.ai_family, hints.ai_socktype, hints.ai_protocol);
    if (m_socket == INVALID_SOCKET) {
        std::cerr << "Failed to create server socket" << std::endl;
        DestroySocketContext();
        exit(1);
    }else{
        std::cout<<"Server started on "<<m_spec.address<<":"<<m_spec.port<<std::endl;
    }

    saServer.sin_family = hints.ai_family;
    saServer.sin_addr.s_addr = inet_addr(m_spec.address.c_str());
    saServer.sin_port = htons(m_spec.port);

    // Setup the TCP listening socket
    result = bind( m_socket, (SOCKADDR*)&saServer,sizeof(saServer));
    if (result == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        closesocket(m_socket);
        DestroySocketContext();
        exit(1);
    }
}
int Server::broadcastMessage(ServerSpec* spec,char* message,int length) {
    int result;
    for (int i = 0; i < spec->maxClients; i++) {
        if (Server::s_clients[i] != 0) {
            result = send(Server::s_clients[i], message, length, 0);
        }
    }
    return result;
}
void Server::handleClient(ServerSpec* spec,int clientIndex) {
    char recvBuf[spec->maxMessageBufferLength];
    auto ClientSocket = Server::s_clients[clientIndex];
    int receivedBytes;
    do {
        receivedBytes = recv(ClientSocket, recvBuf, spec->maxMessageBufferLength, 0);
        if (receivedBytes > 0) {
            // Echo the buffer back to the sender
            std::string response = "client["+std::to_string(clientIndex)+"]: ";
            std::cout<<response;
            std::cout.setf(std::ios::hex,std::ios::basefield);
            for(int i = 0;i < receivedBytes;++i){
                std::cout<<((int)recvBuf[i]  & 0xFF)<< " ";
            }
            std::cout<<std::endl;

            int iSendResult = broadcastMessage(spec,recvBuf,receivedBytes);
            if (iSendResult == SOCKET_ERROR) {
                printf("send failed: %d\n", WSAGetLastError());
                closesocket(ClientSocket);
                WSACleanup();
                exit(1);
            }
        }else{
            std::string response = "Closing connection with client " +std::to_string(clientIndex)+"\n";
            std::cout << response;
            closesocket(Server::s_clients[clientIndex]);
            Server::s_clients[clientIndex] = 0;
            spec->currentClientCount--;

            int iSendResult = broadcastMessage(spec,recvBuf,receivedBytes);
            if (iSendResult == SOCKET_ERROR) {
                printf("send failed: %d\n", WSAGetLastError());
                closesocket(ClientSocket);
                WSACleanup();
                exit(1);
            }
        }

    } while (receivedBytes > 0);
}

void Server::Run() {
    if ( listen( m_socket, SOMAXCONN ) == SOCKET_ERROR ) {
        printf( "Listen failed with error: %ld\n", WSAGetLastError() );
        closesocket(m_socket);
        DestroySocketContext();
        exit(1);
    }else{
        std::cout<<"Listening...\n";
    }

    bool shouldExit = false;
    while (!shouldExit) {
        SOCKADDR_IN clientAddr;
        int clientAddrLen = sizeof(clientAddr);
        SOCKET client = accept(m_socket, (SOCKADDR*)&clientAddr, &clientAddrLen);
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
                closesocket(client);
            }
        }else{
            printf("accept failed: %d\n", WSAGetLastError());
            closesocket(m_socket);
            DestroySocketContext();
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
