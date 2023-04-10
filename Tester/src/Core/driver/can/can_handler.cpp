#include "can_handler.h"
#include <cstdlib>
#include <mutex>

Can_Handler Can_Handler::s_handler;

void Can_Handler::Init() {
    Can_Handler::s_handler.client.Init("127.0.0.1", 55554);
    Can_Handler::s_handler.client.Connect();
    Can_Handler::s_handler.client.suppressLog = true;

}

static inline std::mutex a;

CAN_Message &Can_Handler::WaitForMessage() {
    Can_Handler::s_CanCommBuffer.Clear();
    auto &client = Can_Handler::s_handler.client;

    std::unique_lock<std::mutex> lock(client.messageMutex);
    client.cv.wait(lock, [&client]() { return client.data.received; });
    client.data.received = false;

    s_CanCommBuffer.AddByteArray((char*)client.data.buffer.data(),client.data.size);
    client.data.buffer.clear();

    return s_CanCommBuffer;
}

void Can_Handler::SendMessage(CAN_Message &message) {
    Can_Handler::s_handler.client.Send((char*)message.data(), message.size());
}

void Can_Handler::Destroy() {
    Can_Handler::s_handler.client.Close();
}
