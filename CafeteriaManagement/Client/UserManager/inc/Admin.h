#pragma once

#include "IUser.h"

class Admin : public IUser {
private:
    RequestHandler* requestHandler;

    void showAddItemPrompt();
    void showDeleteItemPrompt();
    void showMenuItemList();
    void addUserPrompt();

public:
    Admin(RequestHandler* requestHandler);

    void handleUserOperations() override;
};
