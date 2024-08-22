#include <iostream>
#include <csignal>
#include "connection.h"
#include "clientHandler.h"

Client * clientInstance = nullptr;

void clientSignalHandler(int signal) {
    if (clientInstance) {
        clientInstance->disconnect();
    }
    exit(signal);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << stderr << "Missing argument\n";
    }
    
    int portNumber = atoi(argv[1]);

    try
    {
        Connection connection(portNumber);
        ClientHandler clientHandler(&connection);
        clientHandler.handleRequest();
       
        std::signal(SIGINT, clientSignalHandler);

        delete clientHandler;
    }
    catch(const SocketException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
