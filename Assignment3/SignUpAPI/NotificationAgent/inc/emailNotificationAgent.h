#pragma once

#include <string>
#include "notificationAgent.h"
#include "User.h"

class EmailNotificationAgent : public NotificationAgent {
public:
    void notifySuccess(const User *user) override;
    void notifyError(const User *user, const std::string& errorMessage) override;

private:
    void sendEmail(const std::string& to, const std::string& subject, const std::string& body);
};
