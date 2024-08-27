#include "adminHandler.h"
#include <iostream>

AdminHandler::AdminHandler(std::unique_ptr<MenuItemService> menuItemService, std::unique_ptr<UserService> userService, std::unique_ptr<NotificationService> notificationService)
    : menuItemService(std::move(menuItemService)), userService(std::move(userService)), notificationService(std::move(notificationService)) {}

std::string AdminHandler::handleRequest(Operation operation, const std::string& requestData) {
    std::cout << "[AdminHandler] Handling request: " << static_cast<int>(operation) << "\n";
    std::string response;

    if (operation == Operation::AddUser) {
        response = handleAddUser(requestData);
    } else if (operation == Operation::AddMenuItem) {
        response = handleAddMenuItem(requestData);
    } else if (operation == Operation::DeleteMenuItem) {
        response = handleDeleteMenuItem(requestData);
    } else if (operation == Operation::ViewMenu) {
        response = handleViewMenu(requestData);
    } else if (operation == Operation::UpdateMenuItem) {
        response = handleUpdateMenuItem(requestData);
    } else if (operation == Operation::GetMenuItemById) {
        response = handleGetMenuItemById(requestData);
    } else {
        std::cerr << "[AdminHandler] Invalid operation: " << static_cast<int>(operation) << "\n";
        response = "Invalid operation";
    }
    return response;
}

std::string AdminHandler::handleGetMenuItemById(const std::string& requestData) {
    std::string response;
    int menuItemId;
    try {
        menuItemId = std::stoi(requestData);
    } catch (const std::invalid_argument&) {
        std::cerr << "[AdminHandler] Invalid menu item ID\n";
        response = "Invalid menu item ID";
    }
    MenuItem menuItem = menuItemService->getMenuItemById(menuItemId);
    std::cout << "[AdminHandler] Get Menu Item By ID operation completed\n";
    if (menuItem.menuItemId != 0) {
        response = DataSerializer::serialize(menuItem);
    } else {
        response = "Menu Item Not Found";
    }
    return response;
}

std::string AdminHandler::handleUpdateMenuItem(const std::string& requestData) {
    std::string response;
    std::cout<<"a"<<std::endl;
    std::cout << "[AdminHandler] Update Menu Item called\n";
    std::cout<<"b"<<std::endl;
    MenuItem menuItem = DataSerializer::deserialize<MenuItem>(requestData);
    std::cout<<"c"<<std::endl;
    bool operationDone = menuItemService->updateMenuItem(menuItem);
    std::cout<<"d"<<std::endl;
    std::cout << "[AdminHandler] Update Menu Item operation completed with result: " << operationDone << "\n";
    if (operationDone) {
        pushNotification(menuItem, Operation::UpdateMenuItem);
        response = "Menu Item Updated Successfully";
    } else {
        response = "Menu Item Not Updated";
    }
    return response;
}

std::string AdminHandler::handleAddUser(const std::string& requestData) {
    std::string response = "";
    std::cout << "[AdminHandler] Add User called\n";
    User user = DataSerializer::deserialize<User>(requestData);
    int operationDone = userService->addUser(user);
    std::cout << "[AdminHandler] Add User operation completed with result: " << operationDone << "\n";
    if (operationDone) {
        response =  "User Added Successfully";
    } else {
        response =  "User Not Added";
    }
    return response;
}

std::string AdminHandler::handleAddMenuItem(const std::string& requestData) {
    std::string response;
    std::cout << "[AdminHandler] Add Menu Item called\n";
    MenuItem menuItem = DataSerializer::deserialize<MenuItem>(requestData);
    bool operationDone = menuItemService->addMenuItem(menuItem);
    std::cout << "[AdminHandler] Add Menu Item operation completed with result: " << operationDone << "\n";
    if (operationDone) {
        pushNotification(menuItem, Operation::AddMenuItem);
        response = "Menu Item Added Successfully";
    } else {
        response = "Menu Item Not Added";
    }
    return response;
}

std::string AdminHandler::handleDeleteMenuItem(const std::string& requestData) {
    std::string response;
    int menuItemId;
    try {
        menuItemId = std::stoi(requestData);
    } catch (const std::invalid_argument&) {
        std::cerr << "[AdminHandler] Invalid menu item ID\n";
        response = "Invalid menu item ID";
    }
    std::cout << "[AdminHandler] Delete Menu Item called\n";
    MenuItem menuItem = menuItemService->deleteMenuItemById(menuItemId);
    std::cout << "[AdminHandler] Delete Menu Item operation completed\n";
    if (menuItem.menuItemId == 0) {
        pushNotification(menuItem, Operation::DeleteMenuItem);
        response = "Menu Item Deleted Successfully";
    } else {
        response = "Menu Item Not Deleted";
    }
    return response;
}

std::string AdminHandler::handleViewMenu(const std::string& requestData) {
    std::cout << "[AdminHandler] View Menu called\n";
    std::vector<MenuItem> menuDetails = menuItemService->getAllMenuItems();
    std::vector<std::string> menuSerializedData;
    for (const auto& menu : menuDetails) {
        menuSerializedData.push_back(DataSerializer::serialize(menu));
    }
    std::cout << "[AdminHandler] View Menu operation completed\n";
    return DataSerializer::serializeStringVector(menuSerializedData);
}

bool AdminHandler::pushNotification(const MenuItem& menuItem, Operation operation) {
    Notification notification;
    std::string menuType = menuItem.menuItemType == 1 ? "Breakfast" :
                            menuItem.menuItemType == 2 ? "Lunch" : "Dinner";

    if (Operation::AddMenuItem == operation) {
        notification.notificationTitle = "New Menu Item Added";
        notification.message = "Menu Item: " + menuItem.menuItemName + " (ID: " + std::to_string(menuItem.menuItemId) + ") has been added to the menu. Price: " + std::to_string(menuItem.price) + ", Type: " + menuType;
    } else {
        notification.notificationTitle = "Menu Item Deleted";
        notification.message = "Menu Item: " + menuItem.menuItemName + " (ID: " + std::to_string(menuItem.menuItemId) + ") has been deleted from the menu.";
    }

    std::cout << "[AdminHandler] Pushing notification: " << notification.notificationTitle << " - " << notification.message << "\n";
    return notificationService->addNotification(notification);
}
