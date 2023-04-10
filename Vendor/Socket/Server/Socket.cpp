//
// Created by Krusto on 31-Jan-23.
//
#include "Socket.h"

int InitSocket(){
#ifdef _WIN32
    WSADATA wsaData;
    return WSAStartup(MAKEWORD(2, 2), &wsaData);
#else
    return 0;
#endif
}

void DestroySocketContext(){
#ifdef _WIN32
    WSACleanup();
#endif
}