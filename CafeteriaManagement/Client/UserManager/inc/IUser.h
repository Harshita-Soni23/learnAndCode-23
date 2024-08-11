#pragma once

#include <vector>
#include <string>

class IUser{
public:
    virtual void showUserOperations() = 0;
    bool loginUser();
private:
    
};
