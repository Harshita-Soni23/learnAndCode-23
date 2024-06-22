#pragma once

#include "userService.h"

class AuthenticationService
{
public:
    AuthenticationService(UserService* userService);
    int authenticateUser(const int& userId, const std::string& password);
    ~AuthenticationService() = default;
private:
    UserService* userService;
};
