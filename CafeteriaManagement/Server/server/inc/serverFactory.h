#pragma once

#include <string>
#include <memory>
#include <iostream>
#include "authenticationController.h"
#include "IUserController.h"

class ServerFactory {
public:
    std::unique_ptr<IUserController> initializeAdminController();
    std::unique_ptr<IUserController> initializeEmployeeController();
    std::unique_ptr<IUserController> initializeChefController();
    ServerFactory();

    std::unique_ptr<AuthenticationController> authenticationController;
    std::unique_ptr<IUserController> userController;

};

#endif
