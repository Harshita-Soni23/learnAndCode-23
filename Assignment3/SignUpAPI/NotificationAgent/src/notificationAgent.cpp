#include "notificationAgent.h"

void NotificationAgent::notifySuccess(const User& user) {
    std::cout << "User notified: Signup successful.\n";
}

void NotificationAgent::notifyError(const User& user, const std::string& error_message) {
    std::cout << "User notified: Signup error - " << error_message << "\n";
}
