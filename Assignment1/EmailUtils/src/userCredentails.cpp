#include "userCredentials.h"

UserCredentials::UserCredentials(const std::string& emailId, const std::string& password)
    : emailId(emailId), password(password) {}

const std::string& UserCredentials::getEmailId() const {
    return emailId;
}

const std::string& UserCredentials::getPassword() const {
    return password;
}

