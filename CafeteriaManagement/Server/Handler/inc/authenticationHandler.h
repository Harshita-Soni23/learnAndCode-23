#pragma once

#include "userService.h"
#include "authenticationService.h"
#include "dataSerializer.h"
#include "login.h"
#include <memory>

class AuthenticationHandler {
public:
    explicit AuthenticationHandler(std::unique_ptr<UserService> userService, std::unique_ptr<AuthenticationService> authenticationService);
    int authenticateUser(const std::string& requestData);
    ~AuthenticationHandler() = default;

private:
    std::unique_ptr<UserService> userService;
    std::unique_ptr<AuthenticationService> authenticationService;
};
