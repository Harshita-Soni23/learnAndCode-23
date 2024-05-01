#ifndef FILE_USERREPOSITORY_H
#define FILE_USERREPOSITORY_H

#include "userRepository.h"
#include "iostream"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <fstream>
#include <vector>

class FileUserRepository : public UserRepository {
private:
    std::string filename;

public:
    FileUserRepository(const std::string& _filename = "users.txt");
    void createUser(const User *user) override;
    bool userExists(const User *user) override;
    std::vector<User *> getAllUsers();
};


#endif
