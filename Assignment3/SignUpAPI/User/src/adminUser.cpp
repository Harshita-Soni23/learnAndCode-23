#include "adminUser.h"
#include <iostream>

AdminUser::AdminUser(const std::string& name, const std::string& email, const std::string& userType)
    : User(name, email, userType) {}

void AdminUser::viewData() const {
}

void AdminUser::addUser(const std::string& newUserName, const std::string& newUserEmail, const std::string& newUserType) {
        signUpService.signup(newUserName, newUserEmail, newUserType);
}

void AdminUser::editData() {
}
