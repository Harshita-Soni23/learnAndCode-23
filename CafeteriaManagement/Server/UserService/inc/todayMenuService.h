#pragma once

#include "todayMenuDAO.h"
#include <vector>
#include <memory>

class TodayMenuService {
public:
    TodayMenuService(std::unique_ptr<TodayMenuDAO> todayMenuDAO);

    bool addTodayMenu(const std::vector<int>& todayDayMenuItemId);
    std::vector<MenuItem> getAllTodayMenuItem();
    bool deleteTodayMenu();

private:
    std::unique_ptr<TodayMenuDAO> todayMenuDAO;
};
