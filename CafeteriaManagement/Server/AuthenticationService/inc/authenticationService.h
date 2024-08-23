#pragma once

#include "userService.h"
#include "Login.h"

class AuthenticationService
{
public:
    AuthenticationService(std::unique_ptr<UserService> userService);
    int authenticateUser(Login loginCredentials);
    ~AuthenticationService() = default;
private:
    std::unique_ptr<UserService> userService;
    bool isValidLogin(const Login& loginCredentials, const User& user)const;
    
};
