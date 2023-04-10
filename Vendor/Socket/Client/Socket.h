//
// Created by Krusto on 31-Jan-23.
//

#pragma once


#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #include <windows.h>
#else
    #include<sys/socket.h>
    #include<arpa/inet.h>	//inet_addr
    #include<unistd.h>	//write
    #include <cerrno>

#define INVALID_SOCKET ~0
#define SOCKET_ERROR -1
#endif

int InitSocket();
void DestroySocketContext();

struct Socket{

#ifdef _WIN32
    Socket() = default;
    Socket(SOCKET s):socket(s){}
    SOCKET socket = 0;
    operator SOCKET&(){return socket;}
#else
    Socket() = default;
    Socket(int s):socket(s){}
    int socket = 0;
    operator int&(){return socket;}
#endif

};
