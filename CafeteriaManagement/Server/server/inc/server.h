#pragma once

#include <vector>
#include <thread>
#include <memory>
#include <netinet/in.h>
#include <mutex>
#include <atomic>
#include "requestHandler.h"
#include "socketException.h"

class Server {
public:
    explicit Server(int port);
    ~Server();
    void start();
    void stop();

private:
    int port;
    int server_fd;
    struct sockaddr_in ipAddress;
    std::vector<int> clientSockets;
    std::vector<std::thread> clientThreads;
    std::mutex clientsMutex;
    std::atomic<bool> isRunning;

    void acceptClients();
};
