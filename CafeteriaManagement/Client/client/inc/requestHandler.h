#pragma once

#include <string>
#include <vector>
#include "socketException.h"
#include <netinet/in.h>

class RequestHandler {
public:
    RequestHandler(int clientSocket, struct sockaddr_in serv_addr);
    void sendRequest(const std::string& request);
    std::string receiveResponse();
private:
    int clientSocket;
    struct sockaddr_in serv_addr;
};
