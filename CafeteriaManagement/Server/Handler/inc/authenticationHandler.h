#pragma once

#include "userService.h"

class AuthenticationHandler
{
public:
    AuthenticationHandler(UserService* userService);
    int authenticateUser(const int& userId, const std::string& password);
    ~AuthenticationHandler() = default;
private:
    UserService* userService;
};
