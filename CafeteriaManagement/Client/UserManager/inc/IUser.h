#pragma once

#include "requestHandler.h"

class User{
public:
    virtual void showUserOperations() = 0;
    bool loginUser();
private:
    
};
