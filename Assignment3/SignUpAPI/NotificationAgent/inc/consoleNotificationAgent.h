#ifndef CONSOLENOTIFICATIONAGENT_H
#define CONSOLENOTIFICATIONAGENT_H

#include "notificationAgent.h"
#include <iostream>
#include <string>

class ConsoleNotificationAgent : public NotificationAgent {
public:
    void notifySuccess(const User *user);
    void notifyError(const User *user, const std::string& error_message);
};

#endif // CONSOLENOTIFICATIONAGENT_H
