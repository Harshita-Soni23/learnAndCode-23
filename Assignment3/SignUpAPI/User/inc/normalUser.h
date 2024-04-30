#ifndef NORMAL_USER_H
#define NORMAL_USER_H

#include "User.h"

class NormalUser : public User {
public:
    NormalUser(const std::string& name, const std::string& email, const std::string& userType);

    // Override viewData method for normal user
    void viewData() const override;

    // Method specific to normal user for editing data
    void editData();
};

#endif // NORMAL_USER_H
