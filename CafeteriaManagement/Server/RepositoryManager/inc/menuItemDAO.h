#pragma once

#include "databaseConnection.h"
#include <memory>
#include "menuItem.h"
#include <vector>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>

class MenuItemDAO{
public:
    MenuItemDAO();

    MenuItem getMenuItemById(const int& menuItemId);
    std::vector<MenuItem> getAllMenuItems();
    std::vector<MenuItem> getMenuItemByType(MenuItemType type);
    bool addMenuItem(const MenuItem& menuItem);
    bool updateMenuItem(const MenuItem& menuItem);
    MenuItem deleteMenuItem(const int& menuItemId);

private:
    std::shared_ptr<DatabaseConnection> databaseConnection;

    MenuItem createMenuItemFromResultSet(std::unique_ptr<sql::ResultSet>& res);
    void bindMenuItemToStatement(std::unique_ptr<sql::PreparedStatement>& pstmt, const MenuItem& menuItem);

};
