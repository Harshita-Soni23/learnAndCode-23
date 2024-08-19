#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

#include <vector>
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>
#include "requestProcessor.h"

class RequestHandler {
public:
    explicit RequestHandler(int clientSocket);
    void handle();

private:
    int clientSocket;
    bool running;
    RequestProcessor requestProcessor;

    bool sendRequest(const std::string& request);
    std::string receiveRequest();
};

#endif
