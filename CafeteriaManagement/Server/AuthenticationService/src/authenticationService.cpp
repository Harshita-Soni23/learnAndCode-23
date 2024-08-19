#include "authenticationService.h"
#include <iostream>

AuthenticationService::AuthenticationService(UserService* userService)
    : userService(userService){}

int AuthenticationService::authenticateUser(Login loginCredentials) {
    
    User user = userService->getUserById(loginCredentials.userId);

    if (isValidLogin(loginCredentials, user)) {
        std::cout << "[AuthenticationController] User authenticated successfully. UserID: " << loginCredentials.userId << "\n";
        userRole = user.role;
    }

    std::cout << "[AuthenticationController] Authentication failed for UserID: " << loginCredentials.userId << "\n";
    return userRole;
}

bool AuthenticationController::isValidLogin(const Login& loginCredentials, const User& user) const {
    return user.userId == loginCredentials.userId && user.password == loginCredentials.password;
}