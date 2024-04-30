#include "viewerUser.h"
#include <iostream>

ViewerUser::ViewerUser(const std::string& name, const std::string& email, const std::string& userType)
    : User(name, email, userType) {}

// Override viewData method for viewer user
void ViewerUser::viewData() const {
    
}
