#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <memory>

#include "sentimentEvaluator.h"
#include "nextDayMenuVoting.h"
#include "rollOutMenu.h"

class RecommendationEngineService {
public:
    RecommendationEngineService();
    
    std::vector<NextDayMenuVoting> recommendTopFoodItems(
        MenuItemType menuType,
        const std::unordered_map<int, std::vector<Feedback>>& feedbackMap,
        const std::vector<MenuItem>& menuItems);
    std::vector<NextDayMenuVoting> generateDiscardMenuList(
        const std::unordered_map<int, std::vector<Feedback>>& feedbackMap,
        const std::vector<MenuItem>& menuItems);
    std::vector<RollOutMenu> sortRecommendedMenuItemsBasedOnProfile(
        const UserProfile& userProfile, 
        const std::vector<RollOutMenu>& chefRolloutMenuForNextDay, 
        const std::vector<MenuItem>& menuItems);

private:
    std::unique_ptr<SentimentEvaluator> sentimentEvaluator_;

    std::vector<MenuItem> filterAvailableMenuItems(MenuItemType menuType, const std::vector<MenuItem>& menuItems);
    std::vector<std::pair<double, NextDayMenuVoting>> scoreMenuItems(
        const std::unordered_map<int, std::vector<Feedback>>& feedbackMap,
        const std::vector<MenuItem>& availableMenuItems);
    int calculateMatchPreferenceScore(const UserProfile& userProfile, const MenuItem& menuItem);
};
