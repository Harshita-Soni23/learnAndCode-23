#include "signUpService.h"
#include <chrono> // for std::chrono
#include <random> // for std::random_device and std::uniform_int_distribution

void SignUpService::signup(const std::string &name, const std::string &email)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dis(1000, 9999);

    auto now = std::chrono::system_clock::now();
    auto timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
    auto random_number = dis(gen);
    std::string user_id = "ID_" + std::to_string(timestamp) + "_" + std::to_string(random_number);

    User new_user(user_id, name, email);

    try
    {
        FileUserRepository fileUserRepository;
        userRepository = &fileUserRepository;
        ConsoleNotificationAgent consoleNotificationAgent;
        notificationAgent = &consoleNotificationAgent;
        userRepository->createUser(new_user);
        dataPopulator.populateDefaultData(new_user);
        directoryManager.createUserDirectory(new_user);
        notificationAgent->notifySuccess(new_user);
    }
    catch (const std::exception &e)
    {
        notificationAgent->notifyError(new_user, e.what());
    }
}
