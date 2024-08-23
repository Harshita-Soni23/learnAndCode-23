#pragma once

#include"userDAO.h"
#include<memory>

class UserService
{
public:
    UserService(std::unique_ptr<UserDAO> userDAO);
    bool addUser(const User& user);
    User getUserById(int userId);

    std::vector<User> getAllUsers();

    ~UserService() = default;
private:    
    std::unique_ptr<UserDAO> userDAO;
};
