#ifndef AUTHENTICATION_CONTROLLER_H
#define AUTHENTICATION_CONTROLLER_H

#include "userService.h"
#include "authenticationService.h"
#include "dataSerializer.h"
#include "login.h"
#include <memory>

class AuthenticationtHandler {
public:
    explicit AuthenticationHandler(std::unique_ptr<UserService> userService, std::unique_ptr<AuthenticationService> authenticationService);
    ~AuthenticationtHandler() = default;

private:
    std::unique_ptr<UserService> userService;
    std::unique_ptr<AuthenticationService> authenticationService;
};
