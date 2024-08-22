#pragma once

#include "IUser.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <string>

class Employee : public IUser {
private:
    RequestHandler *requestHandler;
    int userIdLoggedIn;

    void viewNotification();
    void showChefRollOutMenu();
    void voteForTomorrowMenu(std::vector<int>& recommendedMenuItemIdsFromChef);
    void viewTodayMenu();
    void updateProfile();
    void provideFeedbackForTodayMenu(std::vector<int>& menuItemIdsFromTodayMenu);
    void getDetailedFeedbackForDiscardedMenuItem();

public:
    Employee(RequestHandler *requestHandler, int userIdLoggedIn);

    void handleUserOperations() override;
};
