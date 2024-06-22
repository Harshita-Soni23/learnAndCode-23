#include"requestProcessor.h"
#include<iostream>
#include "UserDAO.h"
#include "user.h"
#include<vector>


std::vector<std::string> RequestProcessor::processLoginRequest(std::vector<std::string> request){
    std::vector<std::string> response = request;

    UserDAO userDAO;
    IUserDAO = &userDAO;
    User user = userDAO->getUserByID();
    std::string role = user.role;
    return role;
}

std::vector<std::string> response;

    if (request.empty()) {
        return response; 
    }

    std::string loginInfo = request[0];
    size_t separatorPos = loginInfo.find(':'); // Assuming ':' separates username and password

    if (separatorPos == std::string::npos) {
        return response; // Return empty response if separator not found
    }

    std::string username = loginInfo.substr(0, separatorPos);
    std::string password = loginInfo.substr(separatorPos + 1);

    UserDAO userDAO;
    User user = userDAO.getUserByUsername(username);

    if (user.password == password) { // Assuming User has a password field
        std::string role = user.role;
        response.push_back(role);
    } else {
        response.push_back("Invalid credentials");
    }

    return response;
}