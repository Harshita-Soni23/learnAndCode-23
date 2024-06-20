#include "userHandler.h"
#include <iostream>

#include<vector>


UserHandler::UserHandler(Client& client)
    : client(client), requestHandler(nullptr) {}

void UserHandler::handleRequest() {
    if (!client.connectToServer()) {
        std::cerr << "Failed to connect to server" << std::endl;
        return;
    }

    requestHandler = new RequestHandler(client.getSocket(), client.getAddress());
    handleUserInput();

    delete requestHandler;
    client.disconnect();
}

void UserHandler::handleUserInput() {
    std::string userId;
    std::string password;
    std::cout << "Enter Login Credentials: \n";
    std::cout<<"Enter User Email : ";
    std::cin>>userId;
    std::cout<<"Enter Password : ";
    std::cin>>password;

    requestHandler->sendRequest({userId, password}) ;
    std::vector<std::string> response = requestHandler->receiveResponse();
    std::cout << "Server: " << response.data()<< std::endl;
}
