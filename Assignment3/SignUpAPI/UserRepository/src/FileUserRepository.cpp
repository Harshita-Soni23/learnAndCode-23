#include "FileUserRepository.h"

void FileUserRepository::createUser(const User *user) {

    if (userExists(user)) {
        throw std::runtime_error("User already exists.");
    }

    std::ofstream userInfoFile(filename, std::ios::app);

    userInfoFile << user->getId() << ',' << user->getName() << ',' << user->getEmail() << ',' << user->getDirectoryPath() << ',' << user->getGender() << ',' << user->getUserType() << '\n';
    userInfoFile.close();
}

bool FileUserRepository::userExists(const User *user) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for reading.");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string id, name, email;
        std::getline(iss, id, ',');
        std::getline(iss, name, ',');
        std::getline(iss, email, ',');

        if (email == user->getEmail()) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

// std::vector<User *> FileUserRepository::getAllUsers() {
//     std::vector<User *> users;
//     std::ifstream file(filename);
//     if (!file.is_open()) {
//         throw std::runtime_error("Failed to open file for reading.");
//     }

//     std::string line;
//     while (std::getline(file, line)) {
//         std::istringstream iss(line);
//         std::string id, name, email;
//         std::getline(iss, id, ',');
//         std::getline(iss, name, ',');
//         std::getline(iss, email, ',');

//         users.emplace_back(id, name, email);
//     }

//     file.close();
//     return users;
// }
