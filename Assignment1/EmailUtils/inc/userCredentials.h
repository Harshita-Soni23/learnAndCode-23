#ifndef USERCREDENTIALS_H
#define USERCREDENTIALS_H

#include <string>

class UserCredentials {
public:
    UserCredentials(const std::string& emailId, const std::string& password);

    const std::string& getEmailId() const;
    const std::string& getPassword() const;

private:
    std::string emailId;
    std::string password;
};

#endif