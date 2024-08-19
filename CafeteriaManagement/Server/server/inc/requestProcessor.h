#ifndef REQUESTPROCESSOR_H
#define REQUESTPROCESSOR_H

#include <string>
#include <memory>
#include <iostream>
#include "authenticationHandler.h"
#include "IUserHandler.h"

class RequestProcessor {
private:
    std::unique_ptr<AuthenticationController> authenticationHandler;
    std::unique_ptr<IUserHandler> userHandler;
    std::string handleLoginRequest(const std::string& requestData);
    std::string handleUserRequest(Operation operation, const std::string& requestData);

public:
    RequestProcessor();
    std::string processRequest(const std::string& request);
};

#endif
