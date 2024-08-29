#pragma once

#include "userProfileDAO.h"
#include <vector>
#include <memory>

class UserProfileService {
public:
    UserProfileService(std::unique_ptr<UserProfileDAO> userProfileDAO);

    bool addUserProfile(const UserProfile& userProfile) ;
    UserProfile getUserProfileByID(const int& userId) ;
    std::vector<UserProfile> getAllUserProfiles() ;
    bool updateUserProfile(const UserProfile& userProfile) ;

private:
    std::unique_ptr<UserProfileDAO> userProfileDAO;
};
