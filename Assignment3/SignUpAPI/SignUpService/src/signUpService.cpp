#include "signUpService.h"
#include "normalUser.h"
#include "adminUser.h"
#include "viewerUser.h"

void SignUpService::signup(const std::string &name, const std::string &email, const std::string &userType)
{
    std::string userId = userIdGenerator.generateUserId();
    if(userType == "viewer")
    {
        ViewerUser newUser(name, email, userType);
        user = &newUser;
    }
    else if(userType == "normal")
    {
        NormalUser newUser(name, email, userType);
        user = &newUser;
    }
    else if(userType == "admin")
    {
        AdminUser newUser(name, email, userType);
        user = &newUser;
    }
    user->setId(userId);
    try
    {
        FileUserRepository fileUserRepository;
        userRepository = &fileUserRepository;
        ConsoleNotificationAgent consoleNotificationAgent;
        notificationAgent = &consoleNotificationAgent;
        LocalDirectoryManager localDirectoryManager;
        directoryManager = &localDirectoryManager;
        userRepository->createUser(user);
        dataPopulator.populateDefaultData(user);
        directoryManager->createUserDirectory(user);
        notificationAgent->notifySuccess(user);
    }
    catch (const std::exception &e)
    {
        notificationAgent->notifyError(user, e.what());
    }
}
