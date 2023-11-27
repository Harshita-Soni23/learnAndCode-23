#include "mailCredentials.h"

MailCredentials::MailCredentials(const std::string& emailId, const std::string& password)
    : emailId(emailId), password(password) {}

const std::string& MailCredentials::getEmailId() const {
    return emailId;
}

const std::string& MailCredentials::getPassword() const {
    return password;
}
