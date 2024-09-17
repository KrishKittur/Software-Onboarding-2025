#ifndef UDP_SOCKET_HPP
#define UDP_SOCKET_HPP

#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h> 
#include <arpa/inet.h>  
#include <unistd.h>  

class UDPSocket {
public:
    UDPSocket();
    ~UDPSocket();

    bool bindSocket(int port);
    bool sendTo(const std::string &message, const std::string &address, int port);
    bool receiveFrom(std::string &message, std::string &senderAddress, int &senderPort);
    void closeSocket();

private:
    int sockfd;
    sockaddr_in serverAddr, clientAddr;
    socklen_t addrLen;
};

#endif