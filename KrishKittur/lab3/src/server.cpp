#include <iostream>
#include "udp_socket.hpp"
#include "message.pb.h"

int main() {
    UDPSocket serverSocket;

    if (!serverSocket.bindSocket(8080)) {
        std::cerr << "Failed to bind socket" << std::endl;
        return 1;
    }

    std::string receivedMessage;
    std::string clientAddress;
    int clientPort;

    if (!serverSocket.receiveFrom(receivedMessage, clientAddress, clientPort)) {
        std::cerr << "Failed to receive message from client" << std::endl;
        return 1;
    }

    proto3::SimpleMessage receivedProto;
    if (!receivedProto.ParseFromString(receivedMessage)) {
        std::cerr << "Failed to parse received message" << std::endl;
        return 1;
    }

    std::cout << "Received from client: " << receivedProto.text() << std::endl;

    proto3::SimpleMessage responseProto;
    responseProto.set_text("Hello, Client!");

    std::string serializedResponse;
    if (!responseProto.SerializeToString(&serializedResponse)) {
        std::cerr << "Failed to serialize response message" << std::endl;
        return 1;
    }

    if (!serverSocket.sendTo(serializedResponse, clientAddress, clientPort)) {
        std::cerr << "Failed to send response to client" << std::endl;
        return 1;
    }

    serverSocket.closeSocket();
    return 0;
}