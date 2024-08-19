#include "serverFactory.h"
#include "userDAO.h"
#include "menuItemDAO.h"
#include "feedbackDAO.h"
#include "nextDayMenuVotingDAO.h"
#include "adminHandler.h"
#include "chefHandler.h"
#include "employeeHandler.h"
#include "todayMenuDAO.h"
#include "notificationDAO.h"
#include "userProfileDAO.h"

ServerFactory::ServerFactory() {}

std::unique_ptr<IUserHandler> ServerFactory::initializeAdminHandler() {
    auto menuItemService = std::make_unique<MenuItemService>(std::make_unique<MenuItemDAO>());
    auto userService = std::make_unique<UserService>(std::make_unique<UserDAO>());
    auto notificationService = std::make_unique<NotificationService>(std::make_unique<NotificationDAO>());
    return std::make_unique<AdminHandler>(std::move(menuItemService), std::move(userService), std::move(notificationService));
}

std::unique_ptr<IUserHandler> ServerFactory::initializeEmployeeHandler() {
    auto feedbackService = std::make_unique<FeedbackService>(std::make_unique<FeedbackDAO>());
    auto nextDayMenuVotingService = std::make_unique<NextDayMenuVotingService>(std::make_unique<NextDayMenuVotingDAO>());
    auto menuItemService = std::make_unique<MenuItemService>(std::make_unique<MenuItemDAO>());
    auto todayMenuService = std::make_unique<TodayMenuService>(std::make_unique<TodayMenuDAO>());
    auto notificationService = std::make_unique<NotificationService>(std::make_unique<NotificationDAO>());
    auto discardMenuItemDetailedFeedbackService = std::make_unique<DiscardMenuItemDetailedFeedbackService>(std::make_unique<DiscardMenuItemDetailedFeedbackDAO>());
    auto userProfileService = std::make_unique<UserProfileService>(std::make_unique<UserProfileDAO>());
    auto recommendationEngine = std::make_unique<RecommendationEngine>();
    return std::make_unique<EmployeeHandler>(
        std::move(menuItemService),
        std::move(nextDayMenuVotingService),
        std::move(feedbackService),
        std::move(recommendationEngine),
        std::move(todayMenuService),
        std::move(notificationService),
        std::move(userProfileService),
        std::move(discardMenuItemDetailedFeedbackService)
    );
}

std::unique_ptr<IUserHandler> ServerFactory::initializeChefHandler() {
    auto menuItemService = std::make_unique<MenuItemService>(std::make_unique<MenuItemDAO>());
    auto nextDayMenuVotingService = std::make_unique<NextDayMenuVotingService>(std::make_unique<NextDayMenuVotingDAO>());
    auto feedbackService = std::make_unique<FeedbackService>(std::make_unique<FeedbackDAO>());
    auto recommendationEngine = std::make_unique<RecommendationEngine>();
    auto todayMenuService = std::make_unique<TodayMenuService>(std::make_unique<TodayMenuDAO>());
    auto notificationService = std::make_unique<NotificationService>(std::make_unique<NotificationDAO>());
    return std::make_unique<ChefHandler>(
        std::move(menuItemService),
        std::move(nextDayMenuVotingService),
        std::move(feedbackService),
        std::move(recommendationEngine),
        std::move(todayMenuService),
        std::move(notificationService)
    );
}
