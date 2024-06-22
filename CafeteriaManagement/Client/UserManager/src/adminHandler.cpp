#include "adminHandler.h"
#include "server.h"
#include "adminService.h"
#include "menuService.h"
#include <iostream>
#include <vector>

AdminHandler::AdminHandler(int sessionId)
{
    this->sessionId = sessionId;
}

void AdminHandler::login()
{
    std::vector<std::string> user;
    user.push_back("1");
    Server::sendMessage(user, sessionId);

    performAdminAction();
}

void AdminHandler::performAdminAction()
{
    bool flag = true;
    while (flag)
    {
        std::vector<std::string> adminChoice = Server::receiveMessage(sessionId);
        if (adminChoice[0] == "1")
        {
            addMenuItem(adminChoice);
        }
        else if (adminChoice[0] == "2")
        {
            updateMenuItem(adminChoice);
        }
        else if (adminChoice[0] == "3")
        {
            deleteItemFromMenu(adminChoice);
        }
        else if (adminChoice[0]=="4")
        {
               viewMenuItems();
        }
    }
}

void AdminHandler::addMenuItem(std::vector<std::string> adminChoice)
{

    MenuService menuService = MenuService();
    std::string name = adminChoice[1];
    std::string price = adminChoice[2];
    std::string availablity = adminChoice[3];
    std::string mealType = adminChoice[4];
    menuService.addItem(name, price, availablity, mealType);
}

void AdminHandler::updateMenuItem(std::vector<std::string> adminChoice)
{
    // MenuService menuService = MenuService();
    // std::string name = adminChoice[1];
    // menuService.removeItem(name);
}

void AdminHandler::deleteItemFromMenu(std::vector<std::string> adminChoice)
{
    MenuService menuService = MenuService();
    std::string name = adminChoice[1];
    menuService.removeItem(name);
}

void AdminHandler::viewMenuItems()
{
    std::cout<<"viewMenu"<<std::endl;
    MenuService menuService = MenuService();
    std::vector<std::string> menu=menuService.getMenuItem();
    for (std::string num : menu) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    Server::sendMessage(menu, sessionId);
}