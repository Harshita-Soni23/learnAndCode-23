#include "server.h"

Server::Server(int port) : port(port), server_fd(-1), isRunning(false) {
    memset(&ipAddress, 0, sizeof(ipAddress));
}

Server::~Server() {
    stop();
}

void Server::start() {
    try {
        server_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_fd == -1) {
            throw ConnectionException("Failed to create socket");
        }

        ipAddress.sin_family = AF_INET;
        ipAddress.sin_addr.s_addr = INADDR_ANY;
        ipAddress.sin_port = htons(port);

        if (bind(server_fd, (struct sockaddr*)&ipAddress, sizeof(ipAddress)) == -1) {
            throw ConnectionException("Failed to bind socket");
        }

        if (listen(server_fd, 3) == -1) {
            throw ConnectionException("Failed to listen on socket");
        }

        isRunning.store(true);
        std::thread acceptThread(&Server::acceptClients, this);
        acceptThread.detach();

        std::cout << "Server started on port " << port << std::endl;
    } catch (const ConnectionException& e) {
        std::cerr << "Connection exception: " << e.what() << std::endl;
        stop();
        throw;
    }
}

void Server::stop() {
    isRunning.store(false);
    if (server_fd != -1) {
        close(server_fd);
    }

    std::lock_guard<std::mutex> lock(clientsMutex);
    for (int clientSocket : clientSockets) {
        close(clientSocket);
    }

    clientSockets.clear();
    clientThreads.clear();

    std::cout << "Server stopped" << std::endl;
}

void Server::acceptClients() {
    while (isRunning) {
        int clientSocket;
        int addrlen = sizeof(ipAddress);
        clientSocket = accept(server_fd, (struct sockaddr*)&ipAddress, (socklen_t *)&addrlen);

        if (clientSocket < 0) {
            if (isRunning) {
                std::cerr << "Accept failed: " << strerror(errno) << std::endl;
            }
            continue;
        }

        std::lock_guard<std::mutex> lock(clientsMutex);
        clientSockets.push_back(clientSocket);
        clientThreads.emplace_back(&RequestHandler::handle, RequestHandler(clientSocket));
    }
}
