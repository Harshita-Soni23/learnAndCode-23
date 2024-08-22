#pragma once

#include "IUser.h"
#include "menuItemType.h"
#include "userProfileType.h"
#include "dataSerializer.h"

class Admin : public IUser {
private:
    RequestHandler* requestHandler;

    void showAddItemPrompt();
    void showDeleteItemPrompt();
    void showMenuItemList();
    void addUserPrompt();
    void showUpdateMenuItemPrompt();
    void displayMenuItemDetails(const MenuItem& menuItem);
    MenuItem updateMenuItemFromUserInput(MenuItem menuItem);

public:
    Admin(RequestHandler* requestHandler);

    void handleUserOperations() override;
};
