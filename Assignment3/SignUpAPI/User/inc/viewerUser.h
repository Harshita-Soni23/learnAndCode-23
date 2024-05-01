#ifndef VIEWER_USER_H
#define VIEWER_USER_H

#include "User.h"

class ViewerUser : public User {
public:
    ViewerUser(const std::string& name, const std::string& email, const std::string& userType);

    // Override viewData method for viewer user
    void viewData() const override;
};

#endif // VIEWER_USER_H
