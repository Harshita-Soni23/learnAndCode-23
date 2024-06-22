#include "authenticationHandler.h"
#include<iostream>

AuthenticationHandler::AuthenticationHandler(UserService* userService)
    : userService(userService) {}

int AuthenticationHandler::authenticateUser(const int& userId, const std::string& password) {
    std::cout<<"Authenticating User : 8\n";
    return userService->authenticateUser(userId, password);
}
