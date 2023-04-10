//
// Created by Krusto on 02-Feb-23.
//

#include "Client.h"

std::vector<unsigned char> hexStringToByteArray(const std::string &hexString) {
    std::vector<unsigned char> byteArray;
    std::stringstream ss(hexString);
    std::string hexByte;
    while (ss >> hexByte) {
        unsigned int byteValue;
        std::stringstream hexStream(hexByte);
        hexStream >> std::hex >> byteValue;
        byteArray.push_back((unsigned char) byteValue);
    }
    return byteArray;
}


int main() {
    Client client("127.0.0.1", 55554);
    client.suppressLog = false;
    if (client.Connect() == 0) {
        std::string input;

        while (input != "exit") {
            auto buffer = hexStringToByteArray(input);
            if(buffer.size() > 0) {
                auto dataSentLength = client.Send((char *) buffer.data(), buffer.size());
            }
            std::cout << ">";
            std::getline(std::cin, input);
        }
    }

    client.Close();
    return 0;
}
