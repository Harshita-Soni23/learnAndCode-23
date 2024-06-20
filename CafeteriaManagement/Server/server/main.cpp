#include <iostream>
#include <csignal>
#include <thread>
#include "server.h"

Server* serverInstance = nullptr;

void signalHandlerWrapper(int signal) {
    if (serverInstance) {
        std::cout << "Signal " << signal << " received. Shutting down the server..." << std::endl;
        serverInstance->stop();
        std::cout << "Server stopped." << std::endl;
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
    Server server(portNumber);
    serverInstance = &server;
    server.start();
    std::cout<<"Please Enter Ctrl+C to exit." << std::endl;
    std::signal(SIGINT, signalHandlerWrapper);

    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
