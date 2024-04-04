#ifndef FILE_USERREPOSITORY_H
#define FILE_USERREPOSITORY_H

#include "UserRepository.h"
#include "iostream"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

class FileUserRepository : public UserRepository {
private:
    std::string filename = "users.txt";

public:
    void createUser(const User& user);
    bool userExists(const User& user);
    std::vector<User> getAllUsers();
};

#endif
