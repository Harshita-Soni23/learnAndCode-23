#include <iostream>
#include <csignal>
#include "connection.h"
#include "clientHandler.h"

Connection * connectionInstance = nullptr;

void clientSignalHandler(int signal) {
    if (connectionInstance) {
        connectionInstance->disconnect();
    }
    exit(signal);
}

int main()
{
    try
    {
        int portNumber = 8083;
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
