#pragma once

#include "client.h"
#include <vector>
#include <string>

class UserHandler {
public:
    UserHandler(Client *client);

    void LoginPrompt();
    void showMenuPrompt(std::string userRole);
    int showAdminMenu();
    void showAddItemPrompt();
    void showUpdateMenuPrompt();
    void showDeleteItemPrompt();
    void showMenu();

private:
    std::vector<std::string> getDataToUpdate();

    Client *client;
};
