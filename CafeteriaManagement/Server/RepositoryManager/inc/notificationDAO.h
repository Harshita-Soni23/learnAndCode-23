#pragma once

#include "notification.h"
#include "databaseConnection.h"
#include <memory>
#include <vector>

class NotificationDAO{
public:
    NotificationDAO();
    std::vector<Notification> getAllNotifications();
    Notification getNotificationById(const int& notificationId);
    bool addNotification(const Notification& notification);
    bool deleteNotification(const int& notificationId);
    std::vector<Notification> getAllNotificationsFromId(const int& notificationId);

private:
    std::shared_ptr<DatabaseConnection> databaseConnection;
};