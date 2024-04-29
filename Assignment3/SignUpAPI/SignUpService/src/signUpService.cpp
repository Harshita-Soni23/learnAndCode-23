#include "signUpService.h"

void SignUpService::signup(const std::string &name, const std::string &email)
{
    std::string user_id = userIdGenerator.generateUserId();

    User new_user(user_id, name, email);

    try
    {
        FileUserRepository fileUserRepository;
        userRepository = &fileUserRepository;
        ConsoleNotificationAgent consoleNotificationAgent;
        notificationAgent = &consoleNotificationAgent;
        LocalDirectoryManager localDirectoryManager;
        directoryManager = &localDirectoryManager;
        userRepository->createUser(new_user);
        dataPopulator.populateDefaultData(new_user);
        directoryManager->createUserDirectory(new_user);
        notificationAgent->notifySuccess(new_user);
    }
    catch (const std::exception &e)
    {
        notificationAgent->notifyError(new_user, e.what());
    }
}
