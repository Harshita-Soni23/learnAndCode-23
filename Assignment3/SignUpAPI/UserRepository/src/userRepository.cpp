#include "userRepository.h"

void UserRepository::createUser(const User& user) {
    // Check if the user already exists in the database
    if (userExists(user)) {
        std::cout << "User already exists. Cannot sign up again." << std::endl;
        return;
    }

    // Proceed with creating the user
    std::ofstream file(filename, std::ios::app);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for writing.");
    }

    file << user.getId() << ',' << user.getName() << ',' << user.getEmail() << '\n';
    file.close();
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
            return true; // User with the same ID already exists
        }
    }

    file.close();
    return false; // User not found
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
