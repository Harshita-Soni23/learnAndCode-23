#include "authenticationHandler.h"
#include <iostream>

AuthenticationHandler::AuthenticationHandler(std::unique_ptr<UserService> userService, std::unique_ptr<AuthenticationService> authenticationService)
    : userService(std::move(userService)), authenticationService(std::move(authenticationService)){}

int AuthenticationHandler::authenticateUser(const std::string& requestData) {
    Login loginCredentials = DataSerializer::deserialize<Login>(requestData);
    int userRole = authenticationService->authenticateUser(loginCredentials);
    return userRole;
}
