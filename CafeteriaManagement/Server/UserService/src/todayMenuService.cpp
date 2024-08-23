#include "todayMenuService.h"

TodayMenuService::TodayMenuService(std::unique_ptr<TodayMenuDAO> todayMenuDAO) : todayMenuDAO(std::move(todayMenuDAO)) {}

bool TodayMenuService::addTodayMenu(const std::vector<int>& todayDayMenuItemId) {
    return todayMenuDAO->addTodayMenu(todayDayMenuItemId);
}

std::vector<MenuItem> TodayMenuService::getAllTodayMenuItem() {
    return todayMenuDAO->getAllTodayMenuItem();
}

bool TodayMenuService::deleteTodayMenu() {
    return todayMenuDAO->deleteTodayMenu();
}
