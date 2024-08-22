#pragma once

#include "requestHandler.h"
#include "menuItemType.h"
#include "userRoleType.h"
#include "utility.h"

class IUser{
public:
    virtual void handleUserOperations() = 0;
private:
    
};
