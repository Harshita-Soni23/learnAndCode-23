#include "userRepository.h"

void UserRepository::createUser(const User& user) {

    if (userExists(user)) {
        std::cout << "User already exists. Cannot sign up again." << std::endl;
        return;
    }

    std::ofstream userInfoFile(filename, std::ios::app);

    userInfoFile << user.getId() << ',' << user.getName() << ',' << user.getEmail() << ',' << user.getDirectoryPath() << ',' << user.getGender() << '\n';
    userInfoFile.close();
}

bool UserRepository::userExists(const User& user) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for reading.");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string id, name, email;
        std::getline(iss, id, ',');

        if (id == user.getId()) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

std::vector<User> UserRepository::getAllUsers() {
    std::vector<User> users;
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

        users.emplace_back(id, name, email);
    }

    file.close();
    return users;
}
