#include "user.h"

User::User(const std::string& name, const std::string& email, const std::string& userType)
    : name(name), email(email), userType(userType) {}

std::string User::getId() const {
    return id;
}

std::string User::getName() const {
    return name;
}

std::string User::getEmail() const {
    return email;
}

std::string User::getDirectoryPath() const {
    return directoryPath;
}

void User::setId(const std::string& newId) {
    id = newId;
}

void User::setName(const std::string& newName) {
    name = newName;
}

void User::setEmail(const std::string& newEmail) {
    email = newEmail;
}

void User::setDirectoryPath(const std::string& newPath) {
    directoryPath = newPath;
}

std::string User::getGender() const
{
    return gender;
}

void User::setGender(const std::string &gender)
{
    this->gender = gender;
}

std::string User::getUserType() const
{
    return userType;
}

void User::setUserType(const std::string &gender)
{
    this->userType = userType;
}

void User::viewData() const
{
    
}