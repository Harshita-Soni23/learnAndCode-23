#ifndef ADMIN_USER_H
#define ADMIN_USER_H

#include "User.h"
#include "signUpService.h"

class AdminUser : public User {
public:
    AdminUser(const std::string& name, const std::string& email, const std::string& userType);

    void viewData() const override;
    void addUser(const std::string& newUserName, const std::string& newUserEmail, const std::string& newUserType);
    void editData();
private:
    SignUpService signUpService;
};

#endif // ADMIN_USER_H
