#pragma once

#include "ISerializer.h"
#include "userRoleType.h"

struct User : public ISerializer {
    int userId = 0;
    std::string name;
    std::string password;
    Role role;

    User(int userId = 0, std::string name = "", int role = 0, std::string password = "")
        : userId(userId), name(name), password(password), role(static_cast<Role>(role)) {}

    std::string serialize() const override {
        return std::to_string(userId) + ";" + name + ";" + std::to_string(static_cast<int>(role)) + ";" + password;
    }

    void deserialize(const std::string& serializedData) override {
        std::istringstream dataStream(serializedData);
        std::string parsedToken;
        std::getline(dataStream, parsedToken, ';');
        userId = std::stoi(parsedToken);
        std::getline(dataStream, parsedToken, ';');
        name = parsedToken;
        std::getline(dataStream, parsedToken, ';');
        role = static_cast<Role>(std::stoi(parsedToken));
        std::getline(dataStream, parsedToken, ';');
        password = parsedToken;
    }
};
