#ifndef NOTIFICATIONAGENT_H
#define NOTIFICATIONAGENT_H

#include "user.h"
#include <iostream>
#include <string>

class NotificationAgent {
public:
    void notifySuccess(const User& user);
    void notifyError(const User& user, const std::string& error_message);
};

#endif // NOTIFICATIONAGENT_H
