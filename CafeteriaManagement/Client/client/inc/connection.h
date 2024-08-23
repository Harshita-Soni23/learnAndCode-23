#pragma once

#include <string>
#include <netinet/in.h>
#include "socketException.h"

class Connection {
public:
    explicit Connection(int server_port);
    ~Connection();
    void connectToServer();
    void disconnect();
    int getSocket() const;
    struct sockaddr_in getAddress() const;

private:
    int server_port;
    int clientSocket;
    struct sockaddr_in serv_addr;
    void createSocket();
    void setupAddress();
};
