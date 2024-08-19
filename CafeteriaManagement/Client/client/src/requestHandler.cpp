#include "../inc/requestHandler.h"
#include <sys/socket.h> 
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <netinet/in.h>

#define BUFFER_SIZE 4096

RequestHandler::RequestHandler(int clientSocket, struct sockaddr_in serv_addr)
    : clientSocket(clientSocket), serv_addr(serv_addr) {}

void RequestHandler::sendRequest(const std::string& request) {
    std::vector<unsigned char> requestBuffer(request.begin(), request.end());
    send(clientSocket, requestBuffer.data(), requestBuffer.size(), 0);
    std::cout<<"Request sent"<<std::endl;
}

std::string RequestHandler::receiveResponse() {
    char buffer[1024] = {0};
    int bytesRead = read(clientSocket, buffer, 1024);
    if (bytesRead <= 0) {
        return "";
    }
    std::cout<<"Response received"<<std::endl;
    std::vector<unsigned char> request(buffer, buffer + bytesRead);
    std::string requestData(request.begin(), request.end());
    return std::string(requestData);
}
