#ifndef NOTIFICATIONAGENT_H
#define NOTIFICATIONAGENT_H

#include "user.h"

class NotificationAgent {
public:
    virtual void notifySuccess(const User& user) = 0;
    virtual void notifyError(const User& user, const std::string& error_message) = 0;
};

#endif // NOTIFICATIONAGENT_H
