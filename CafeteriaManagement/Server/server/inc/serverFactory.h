#pragma once

#include <string>
#include <memory>
#include <iostream>
#include "authenticationHandler.h"
#include "IUserHandler.h"

class ServerFactory {
public:
    std::unique_ptr<IUserHandler> initializeAdminHandler();
    std::unique_ptr<IUserHandler> initializeEmployeeHandler();
    std::unique_ptr<IUserHandler> initializeChefHandler();
    ServerFactory();

    std::unique_ptr<AuthenticationHandler> authenticationHandler;
    std::unique_ptr<IUserHandler> userHandler;

};
