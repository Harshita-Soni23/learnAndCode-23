#pragma once

#include <vector>
#include <string>

class IUserHandler
{
public:
    virtual std::vector<std::string> handleRequest(std::vector<std::string> request) = 0;

};
