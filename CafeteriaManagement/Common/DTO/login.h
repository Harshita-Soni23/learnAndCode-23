#pragma once

#include "ISerializer.h"
#include <sstream>

struct Login : public ISerializer {
    int userId;
    std::string password;

    Login() : userId(0), password("") {}

    Login(int userId, std::string password)
       : userId(userId), password(password){}

    std::string serialize() const override {
        return std::to_string(userId)+ ";" + password;
    }

    void deserialize(const std::string& serializedData) override {
        std::istringstream dataStream(serializedData);
        std::string parsedToken;
        std::getline(dataStream, parsedToken, ';');
        userId = std::stoi(parsedToken);
        std::getline(dataStream, parsedToken, ';');
        password = parsedToken;
    }
};
