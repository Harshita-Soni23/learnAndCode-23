#include <iostream>
#include <csignal>
#include "client.h"
#include "userHandler.h"

Client * clientInstance = nullptr;
void clientHandlerWrapper(int signal) {
    clientInstance->disconnect();  
    exit(signal);
}


int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << stderr << "Missing argument\n";
    }
    int portNumber = atoi(argv[1]);
    Client client(portNumber);
    UserHandler userHandler(client);
    userHandler.handleRequest();
    clientInstance = &client;
    std::signal(SIGINT, clientHandlerWrapper);

    return 0;
}
