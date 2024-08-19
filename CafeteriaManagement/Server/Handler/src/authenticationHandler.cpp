#include "authenticationHandller.h"
#include <iostream>

AuthenticationtHandler::AuthenticationtHandler(std::unique_ptr<UserService> userService, std::unique_ptr<AuthenticationService> authenticationService)
    : userService(std::move(userService)), authenticationService(std::move(authenticationService)) {}

int AuthenticationtHandler::authenticateUser(const std::string& requestData) {
    int userRole = -1;
    Login loginCredentials = SerializationUtility::deserialize<Login>(requestData);
    User user = authenticationService->authenticateUser(loginCredentials);

    if(userRole != -1)
    {
        std::cout << "[AuthenticationtHandler] Authentication successful for UserID: " << loginCredentials.userId << "\n";
    }
    else
    {
        std::cout << "[AuthenticationtHandler] Authentication failed for UserID: " << loginCredentials.userId << "\n";
    }
    return userRole;
}

bool AuthenticationtHandler::isValidLogin(const Login& loginCredentials, const User& user) const {
    return user.userId == loginCredentials.userId && user.password == loginCredentials.password;
}
