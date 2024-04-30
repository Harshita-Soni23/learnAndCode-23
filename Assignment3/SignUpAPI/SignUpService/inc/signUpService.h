#ifndef SIGNUPSERVICE_H
#define SIGNUPSERVICE_H

#include "FileUserRepository.h"
#include "defaultDataPopulator.h"
#include "localDirectoryManager.h"
#include "consoleNotificationAgent.h"
#include "userIdGenerator.h"
#include "user.h"
#include <string>

class SignUpService {
private:
    UserRepository *userRepository;
    DefaultDataPopulator dataPopulator;
    DirectoryManager *directoryManager;
    NotificationAgent *notificationAgent;
    UserIdGenerator userIdGenerator;
    User *user;

public:
    void signup(const std::string& name, const std::string& email, const std::string &userType = "viewer");
};

#endif // SIGNUPSERVICE_H
