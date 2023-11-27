#pragma once

#include <string>

class MailCredentials {
public:
    MailCredentials(const std::string& emailId, const std::string& password);

    const std::string& getEmailId() const;
    const std::string& getPassword() const;

private:
    std::string emailId;
    std::string password;
};
