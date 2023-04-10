//
// Created by Krusto on 31-Jan-23.
//

#pragma once


#ifdef _WIN32
    #include <windows.h>
    #include <winsock2.h>
    #include <ws2tcpip.h>
#else
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
