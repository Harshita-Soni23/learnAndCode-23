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
    void voteForTomorrowMenu();
    void viewTodayMenu();
    void provideFeedbackForTodayMenu();
    std::string getCurrentTimestamp();
    void getDetailedFeedbackForDiscardedMenuItem();

public:
    Employee(RequestHandler *requestHandler, int userIdLoggedIn);

    void handleUserOperations() override;
};
