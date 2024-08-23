#pragma once

#include "IUserHandler.h"
#include "recommendationEngineService.h"
#include "rolloutMenu.h"

class ChefHandler : public IUserHandler {
public:
    ChefHandler(std::unique_ptr<MenuItemService> menuItemService,
                   std::unique_ptr<NextDayMenuVotingService> nextDayMenuVotingService,
                   std::unique_ptr<FeedbackService> feedbackService,
                   std::unique_ptr<RecommendationEngineService> recommendationEngine,
                   std::unique_ptr<TodayMenuService> todayMenuService,
                   std::unique_ptr<NotificationService> notificationService);
    
    std::string handleRequest(Operation operation, const std::string& request) override;

private:
    std::vector<NextDayMenuVoting> nextDayMenuRecommendation;
    std::unique_ptr<MenuItemService> menuItemService;
    std::unique_ptr<NextDayMenuVotingService> nextDayMenuVotingService;
    std::unique_ptr<FeedbackService> feedbackService;
    std::unique_ptr<TodayMenuService> todayMenuService;
    std::unique_ptr<NotificationService> notificationService;

    std::unique_ptr<RecommendationEngineService> recommendationEngine;

    std::string handleViewMenu();
    std::string handleRollOutMenuForNextDay(const std::string& requestData);
    std::string handleGetRecommendationFromEngine(const std::string& requestData);
    std::string handlePublishMenuForToday();
    std::string handleGetDiscardMenuList();
    std::string handleGetNextDayMenuVoting();
    std::string handleRemoveMenuItemFromList(const std::string& requestData);
    std::string handleGetMenuItemIdForDetailFeedbackFromChef(const std::string& requestData);
    std::vector<RollOutMenu> getTopMenuRecommendationFromEngine(MenuItemType menuItemType);
    std::vector<RollOutMenu> getNextDayMenuItemsToRollOut(const std::vector<NextDayMenuVoting>& nextDayMenuToRollOut);
    bool rollOutFinalMenuByChefForNextDay(const std::vector<int>& menuItemIds);
    std::vector<int> publishMostVotedMenuItems();
    bool pushNotification(Operation operation, const std::string& message);
};
