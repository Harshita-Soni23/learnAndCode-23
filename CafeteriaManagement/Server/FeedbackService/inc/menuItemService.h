#pragma once

#include "menuItemDAO.h"
#include <memory>

class MenuItemService
{
public:
    MenuItemService(std::unique_ptr<MenuItemDAO> menuItemDAO);
    bool addMenuItem(const MenuItem& menuItem);
    bool updateMenuItem(const MenuItem& menuItem);
    MenuItem deleteMenuItemById(int menuItemId);
    MenuItem getMenuItemById(int menuItemId);
    std::vector<MenuItem> getAllMenuItems();
private:
    std::unique_ptr<MenuItemDAO> menuItemDAO;
};
