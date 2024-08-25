#include <iostream>
#include <csignal>
#include <cstdlib> // For std::atoi
#include "connection.h"
#include "clientHandler.h"

Connection *connectionInstance = nullptr;

void clientSignalHandler(int signal) {
    if (connectionInstance) {
        connectionInstance->disconnect();
    }
    exit(signal);
}

int main(int argc, char *argv[])
{
    try
    {
        int portNumber = 8083; // Default port number

        if (argc > 1) {
            portNumber = std::atoi(argv[1]);
            if (portNumber <= 0 || portNumber > 65535) {
                std::cerr << "Invalid port number. Please enter a number between 1 and 65535." << std::endl;
                return 1;
            }
        }

        Connection connection(portNumber);
        connectionInstance = &connection;
        ClientHandler *clientHandler = new ClientHandler(connection);
        clientHandler->handleRequest();

        std::signal(SIGINT, clientSignalHandler);

        delete clientHandler;
    }
    catch (const SocketException &error)
    {
        std::cerr << "Error: " << error.what() << std::endl;
        return 1;
    }

    return 0;
}
