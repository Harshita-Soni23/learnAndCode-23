#include "authenticationService.h"
#include<iostream>

AuthenticationService::AuthenticationService(UserService* userService)
    : userService(userService) {}

int AuthenticationService::authenticateUser(const int& userId, const std::string& password) {
    std::cout<<"Authenticating User : 8\n";
    return userService->authenticateUser(userId, password);
}
