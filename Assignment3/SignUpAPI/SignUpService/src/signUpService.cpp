#include "signUpService.h"

void SignUpService::signup(const std::string& name, const std::string& email) {
    static int next_id = 1;
    std::string user_id = std::to_string(next_id++);

    User new_user(user_id, name, email);

    try {
        userRepository.createUser(new_user);

        // Populate default data
        //data_populator.populate_default_data(new_user);

        directoryManager.createUserDirectory(new_user);
        notificationAgent.notifySuccess(new_user);
    } catch (const std::exception& e) {
        notificationAgent.notifyError(new_user, e.what());
    }
}
