#include <iostream>
#include "Server.h"

int main() {
    Server server(ServerSpec{.address="127.0.0.1",.port=55555,.protocolType=ProtocolType::TCP});

    server.Init();
    server.Run();
    server.Stop();

    return 0;
}