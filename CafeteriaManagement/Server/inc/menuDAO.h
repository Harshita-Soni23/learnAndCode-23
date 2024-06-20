#pragma once

#include <string>
#include <vector>

class MenuDAO {
public:
    MenuDAO();
    ~MenuDAO();

    void addMenu(const std::string& menuName);
    void deleteMenu(int menuId);
    std::vector<std::string> getAllFoodItems();
    std::vector<std::string> getAllMenus();
    std::string getMenu(int menuId);
    std::vector<std::string> getMenusByDate(const std::string& date);
    std::vector<std::string> getMenusByType(const std::string& type);
    void updateMenu(int menuId, const std::string& updatedMenuName);

private:
    void* dbConnection;
};
