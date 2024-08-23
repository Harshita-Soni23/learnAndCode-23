// #include "connection.h"
// #include "databaseException.h"
// #include "socketException.h"
// #include <iostream>
// #include <unistd.h>
// #include <arpa/inet.h>
// #include <cstring>

// Connection::Connection(const int&  server_port)
//     : server_port(server_port), clientSocket(-1) {
    
//     clientSocket = socket(AF_INET, SOCK_STREAM, 0);
//     if (clientSocket < 0) {
//         throw SocketException("Socket creation error");
//     }

//     memset(&serv_addr, '0', sizeof(serv_addr));
//     serv_addr.sin_family = AF_INET;
//     serv_addr.sin_addr.s_addr = INADDR_ANY;
//     serv_addr.sin_port = htons(server_port);

//     if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
//         throw SocketException("Invalid address/ Address not supported");
//     }
// }

// Connection::~Connection() {
//     disconnect();
// }

// void Connection::connectToServer() {
//     int retryCount = 3;
//     while (retryCount--) {
//         if (connect(clientSocket, reinterpret_cast<struct sockaddr*>(&serv_addr), sizeof(serv_addr)) < 0) {
//             if (retryCount == 0) {
//                 throw ConnectionException("Connection to server failed");
//             }
//             std::cerr << "Retrying connection..." << std::endl;
//             sleep(1);
//         } else {
//             std::cout << "Connected to server" << std::endl;
//         }
//     }
// }

// void Connection::disconnect() {
//     if (clientSocket >= 0) {
//         if (close(clientSocket) < 0) {
//             throw DisconnectionException("Disconnection failed");
//         }
//         clientSocket = -1;
//     }
// }

// int Connection::getSocket() const {
//     return clientSocket;
// }

// struct sockaddr_in Connection::getAddress() const {
//     return serv_addr;
// }

#include "connection.h"
#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>

Connection::Connection(int server_port)
    : server_port(server_port), clientSocket(-1) {
    createSocket();
    setupAddress();
}

Connection::~Connection() {
    try {
        disconnect();
    } catch (const DisconnectionException& e) {
        std::cerr << "Error during disconnection: " << e.what() << std::endl;
    }
}

void Connection::createSocket() {
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        throw SocketException("Socket creation error");
    }
}

void Connection::setupAddress() {
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(server_port);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        throw SocketException("Invalid address/ Address not supported");
    }
}

void Connection::connectToServer() {
    int retryCount = 3;
    while (retryCount--) {
        if (connect(clientSocket, reinterpret_cast<struct sockaddr*>(&serv_addr), sizeof(serv_addr)) < 0) {
            if (retryCount == 0) {
                throw ConnectionException("Connection to server failed");
            }
            std::cerr << "Retrying connection..." << std::endl;
            sleep(1); // wait before retrying
        } else {
            std::cout << "Connected to server" << std::endl;
            return;
        }
    }
}

void Connection::disconnect() {
    if (clientSocket >= 0) {
        if (close(clientSocket) < 0) {
            throw DisconnectionException("Disconnection failed");
        }
        clientSocket = -1;
    }
}

int Connection::getSocket() const {
    return clientSocket;
}

struct sockaddr_in Connection::getAddress() const {
    return serv_addr;
}
