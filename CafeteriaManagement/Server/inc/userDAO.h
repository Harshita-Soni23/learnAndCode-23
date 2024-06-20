#pragma once

#include <string>
#include <vector>

class UserDAO {
public:
    UserDAO();
    ~UserDAO();

    void addUser(const std::string& userName, const std::string& password);
    void changePassword(int userId, const std::string& newPassword);
    void deleteUser(int userId);
    std::vector<std::string> getAllUsers();
    std::string getUserById(int userId);
    void updateUser(int userId, const std::string& updatedUserName, const std::string& updatedPassword);

private:
    void* dbConnection;
};
