#include "normalUser.h"
#include <iostream>

NormalUser::NormalUser(const std::string& name, const std::string& email, const std::string& userType)
    : User(name, email, userType) {}

void NormalUser::viewData() const {
    
}

void NormalUser::editData() {
    
}
