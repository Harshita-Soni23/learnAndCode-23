#pragma once

#include <string>
#include <vector>
#include "IUserDAO.h"

class RequestProcessor {

public:
    std::vector<std::string> processRequest(std::vector<std::string> request);

private:
    IUserDAO *userDAO = nullptr;
};
