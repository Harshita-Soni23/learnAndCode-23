#include "consoleNotificationAgent.h"

void  ConsoleNotificationAgent::notifySuccess(const User *user) {
    std::cout << "User notified: Signup successful.\n";
}

void ConsoleNotificationAgent::notifyError(const User *user, const std::string& error_message) {
    std::cout << "User notified: Signup error - " << error_message << "\n";
}
