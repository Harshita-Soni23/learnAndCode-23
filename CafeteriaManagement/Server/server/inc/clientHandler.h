
#pragma once

#include <string>
#include <vector>
#include "requestProcessor.h"

class ClientHandler {
public:
    ClientHandler(int clientSocket);
    void handle();

private:
    int clientSocket;
    bool running;
    RequestProcessor requestProcessor;
    
    bool sendRequest(std::vector<std::string> request);
    std::vector<unsigned char> processRequest( std::vector<unsigned char> requestBuffer);
    std::vector<std::string> receiveRequest();

};
