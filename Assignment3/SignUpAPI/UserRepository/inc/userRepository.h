#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include "user.h"
#include "iostream"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

class UserRepository {
private:
    std::string filename = "users.txt";

public:
    void createUser(const User& user);
    bool userExists(const User& user);
    std::vector<User> getAllUsers();
};

#endif // USERREPOSITORY_H
