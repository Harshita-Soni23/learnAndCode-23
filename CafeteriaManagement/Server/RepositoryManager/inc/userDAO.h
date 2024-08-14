#ifndef USERDAO_H
#define USERDAO_H
 
#include <vector> 
#include "databaseConnection.h"

class UserDAO{
public:
    UserDAO();

    int addUser(const User& user);
    User getUserByID(const int& userId);
    std::vector<User> getAllUsers();

private:
    std::shared_ptr<DatabaseConnection> databaseConnection;
};

#endif 