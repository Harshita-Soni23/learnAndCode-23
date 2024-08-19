#pragma once

#include "databaseConnection.h"
#include "userProfile.h"
#include <vector>

class UserProfileDAO{
public:
    UserProfileDAO();

    int addUserProfile(const UserProfile& userProfile);
    UserProfile getUserProfileByID(const int& userId);
    std::vector<UserProfile> getAllUserProfiles();

private:
    std::shared_ptr<DatabaseConnection> databaseConnection;
};
