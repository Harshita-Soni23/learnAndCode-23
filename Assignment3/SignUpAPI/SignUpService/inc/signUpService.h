#ifndef SIGNUPSERVICE_H
#define SIGNUPSERVICE_H

#include "userRepository.h"
//#include "efaultDataPopulator.h"
#include "directoryManager.h"
#include "notificationAgent.h"
#include <string>

class SignUpService {
private:
    UserRepository userRepository;
    //DefaultDataPopulator dataPopulator;
    DirectoryManager directoryManager;
    NotificationAgent notificationAgent;

public:
    void signup(const std::string& name, const std::string& email);
};

#endif // SIGNUPSERVICE_H
