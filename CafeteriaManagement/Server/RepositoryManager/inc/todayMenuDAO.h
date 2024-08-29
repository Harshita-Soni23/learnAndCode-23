#pragma once

#include "databaseConnection.h"
#include <vector>
#include "menuItem.h"

class TodayMenuDAO {
public:
    TodayMenuDAO();

    bool addTodayMenu(const std::vector<int>& todayDayMenuItemId) ;
    std::vector<MenuItem> getAllTodayMenuItem() ;
    bool deleteTodayMenu() ;

private:
    std::shared_ptr<DatabaseConnection> databaseConnection;
};
