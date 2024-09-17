#include "udp_socket.hpp"

UDPSocket::UDPSocket() {
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        std::cerr << "Couldn't create socket." << std::endl;
        exit(1);
    }
    addrLen = sizeof(sockaddr_in);
}

UDPSocket::~UDPSocket() {
    closeSocket();
}

bool UDPSocket::bindSocket(int port) {
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);    

    if (bind(sockfd, (sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Couldnt bind socket" << std::endl;
        return false;
    }
    return true;
}

bool UDPSocket::sendTo(const std::string &message, const std::string &address, int port) {
    clientAddr.sin_family = AF_INET;
    clientAddr.sin_port = htons(port);
    clientAddr.sin_addr.s_addr = inet_addr(address.c_str());

    if (sendto(sockfd, message.c_str(), message.size(), 0, (sockaddr *)&clientAddr, addrLen) < 0) {
        std::cerr << "Failed to send message" << std::endl;
        return false;
    }
    return true;
}

bool UDPSocket::receiveFrom(std::string &message, std::string &senderAddress, int &senderPort) {
    char buffer[1024];
    int msgSize = recvfrom(sockfd, buffer, sizeof(buffer), 0, (sockaddr *)&clientAddr, &addrLen);
    if (msgSize < 0) {
        std::cerr << "Couldnt recieve message" << std::endl;
        return false;
    }
    buffer[msgSize] = '\0'; 

    message = std::string(buffer);
    senderAddress = inet_ntoa(clientAddr.sin_addr);
    senderPort = ntohs(clientAddr.sin_port);
    return true;
}

void UDPSocket::closeSocket() {
    close(sockfd);
}