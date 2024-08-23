#pragma once

#include "requestHandler.h"
#include "menuItemType.h"
#include "userRoleType.h"
#include "utility.h"
#include "dataSerializer.h"

class IUser{
public:
    virtual void handleUserOperations() = 0;
private:
    
};

// g++ -I ../Common/exception/inc -I ./client/inc -I ../Common/utility/inc -I ../Common/DTO -I ../Common/constants -I ../Common/DTO/ClientDataEnums -I ./UserManager/inc ../Common/exception/src/* ./client/src/* ../Common/utility/src/* ./UserManager/src/* main.cpp -o myclient