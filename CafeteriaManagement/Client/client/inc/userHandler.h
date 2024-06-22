#pragma once

#include "client.h"
#include "requestHandler.h"
#include <vector>
#include <string>

class UserHandler {
public:
    UserHandler(Client& client);
    void handleRequest();

private:
    Client& client;
    RequestHandler* requestHandler;

    void handleUserInput();
    void showMenuPrompt(std::string userRole);
    int showAdminMenu();
    void showAddItemPrompt();
    // void showUpdateMenuPrompt();
    // void showDeleteItemPrompt();
    // void showMenu();
    // void addUserPrompt();

    void loginPrompt();
    std::vector<std::string> getDataToUpdate();
};
