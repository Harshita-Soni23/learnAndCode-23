#include "authenticationService.h"
#include <iostream>

AuthenticationService::AuthenticationService(std::unique_ptr<UserService> userService)
    : userService(std::move(userService)){}

int AuthenticationService::authenticateUser(Login loginCredentials) {
    int userRole = -1;
    User user = userService->getUserById(loginCredentials.userId);

    if (isValidLogin(loginCredentials, user))
    {
        std::cout << "[AuthenticationService] User authenticated successfully. UserID: " << loginCredentials.userId << "\n";
        userRole = user.role;
    }
    else
    {
        std::cout << "[AuthenticationService] Authentication failed for UserID: " << loginCredentials.userId << "\n";
    }
    return userRole;
}

bool AuthenticationService::isValidLogin(const Login& loginCredentials, const User& user) const {
    return user.userId == loginCredentials.userId && user.password == loginCredentials.password;
}