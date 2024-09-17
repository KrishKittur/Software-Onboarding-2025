#include <iostream>
#include "udp_socket.hpp"
#include "message.pb.h"

int main() {
    UDPSocket clientSocket;
    proto3::SimpleMessage message;

    message.set_text("Hello, Server!");

    std::string serializedMessage;
    if (!message.SerializeToString(&serializedMessage)) {
        std::cerr << "Failed to serialize message" << std::endl;
        return 1;
    }

    if (!clientSocket.sendTo(serializedMessage, "127.0.0.1", 8080)) {
        std::cerr << "Failed to send message" << std::endl;
        return 1;
    }

    std::string receivedMessage;
    std::string serverAddress;
    int serverPort;

    if (!clientSocket.receiveFrom(receivedMessage, serverAddress, serverPort)) {
        std::cerr << "Failed to receive message from server" << std::endl;
        return 1;
    }

    proto3::SimpleMessage receivedProto;
    if (!receivedProto.ParseFromString(receivedMessage)) {
        std::cerr << "Failed to parse received message" << std::endl;
        return 1;
    }

    std::cout << "Received from server: " << receivedProto.text() << std::endl;

    clientSocket.closeSocket();
    return 0;
}