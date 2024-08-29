#pragma once

#include "notificationDAO.h"

#include<memory>

class NotificationService
{
public:
    NotificationService(std::unique_ptr<NotificationDAO> notificationDAO);
    bool addNotification(const Notification& notification);
    bool deleteNotificationByID(int notificationId);
    Notification getNotificationById(int notificationId);
    std::vector<Notification> getNotificationsFromId(const int& notificationId);
    std::vector<Notification> getAllNotifications();
    ~NotificationService() = default;
private:
    std::unique_ptr<NotificationDAO> notificationDAO;
};
