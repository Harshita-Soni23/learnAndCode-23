#pragma once

#include <string>
#include <memory>
#include <iostream>
#include "authenticationHandler.h"
#include "serverFactory.h"
#include "IUserHandler.h"

class RequestProcessor {
private:
    std::unique_ptr<AuthenticationHandler> authenticationHandler;
    std::unique_ptr<IUserHandler> userHandler;
    std::string handleLoginRequest(const std::string& requestData);
    std::string handleUserRequest(Operation operation, const std::string& requestData);
    ServerFactory serverFactory;

public:
    RequestProcessor();
    std::string processRequest(const std::string& request);
};
