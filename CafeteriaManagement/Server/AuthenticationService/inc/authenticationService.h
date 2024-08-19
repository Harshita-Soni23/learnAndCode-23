#pragma once

#include "userService.h"
#include "Login.h"

class AuthenticationService
{
public:
    AuthenticationService(UserService* userService);
    int authenticateUser(Login loginCredentials);
    ~AuthenticationService() = default;
private:
    UserService* userService;
    bool isValidLogin(const Login& loginCredentials, const User& user)const
    
};
