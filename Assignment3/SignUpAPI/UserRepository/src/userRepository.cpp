#include "userRepository.h"

void UserRepository::createUser(const User& user) {
    // Check if the user already exists in the database
    if (userExists(user)) {
        std::cout << "User already exists. Cannot sign up again." << std::endl;
        return;
    }

    // Proceed with creating the user
    std::ofstream userInfoFile(filename, std::ios::app);

    // // Write user information to a file in the user directory
    //         if (userInfoFile.is_open()) {
    //             userInfoFile << "ID: " << user.getId() << std::endl;
    //             userInfoFile << "Name: " << user.getName() << std::endl;
    //             userInfoFile << "Email: " << user.getEmail() << std::endl;
    //             // Write other user information as needed
    //             userInfoFile.close();

    //             // Append user information to the database file
    //             std::ofstream databaseFile(filename, std::ios_base::app);
    //             if (databaseFile.is_open()) {
    //                 databaseFile << "Directory Path: " << user.getDirectoryPath() << std::endl;
    //                 databaseFile << "ID: " << user.getId() << std::endl;
    //                 databaseFile << "Name: " << user.getName() << std::endl;
    //                 databaseFile << "Email: " << user.getEmail() << std::endl;
    //                 // Write other user information as needed
    //                 databaseFile << "------------------------------------" << std::endl;
    //                 databaseFile.close();
    //                 std::cout << "User information appended to database file." << std::endl;
    //             } else {
    //                 std::cerr << "Error opening database file." << std::endl;
    //             }
    //         } else {
    //             std::cerr << "Error creating user info file." << std::endl;
    //         }

    userInfoFile << user.getId() << ',' << user.getName() << ',' << user.getEmail() << ',' << user.getDirectoryPath() << '\n';
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
