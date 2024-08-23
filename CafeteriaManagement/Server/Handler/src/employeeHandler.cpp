#include "employeeHandler.h"

EmployeeHandler::EmployeeHandler(std::unique_ptr<MenuItemService> menuItemService,
                                       std::unique_ptr<NextDayMenuVotingService> nextDayMenuVotingService,
                                       std::unique_ptr<FeedbackService> feedbackService,
                                       std::unique_ptr<RecommendationEngineService> recommendationEngine,
                                       std::unique_ptr<TodayMenuService> todayMenuService,
                                       std::unique_ptr<NotificationService> notificationService,
                                       std::unique_ptr<UserProfileService> userProfileService,
                                       std::unique_ptr<DiscardMenuItemDetailedFeedbackService> discardMenuItemDetailedFeedbackService)
    : menuItemService(std::move(menuItemService)),
      nextDayMenuVotingService(std::move(nextDayMenuVotingService)),
      feedbackService(std::move(feedbackService)),
      recommendationEngine(std::move(recommendationEngine)),
      todayMenuService(std::move(todayMenuService)),
      notificationService(std::move(notificationService)),
      userProfileService(std::move(userProfileService)),
      discardMenuItemDetailedFeedbackService(std::move(discardMenuItemDetailedFeedbackService)) {}

std::string EmployeeHandler::handleRequest(Operation operation, const std::string& requestData) {
    std::cout << "[EmployeeHandler] Handling request: " << static_cast<int>(operation) << "\n";
    std::string response;
    if (operation == Operation::ViewNotification) {
        response = handleViewNotifications();
    } else if (operation == Operation::ProvideFeedback) {
        response = handleProvideFeedback(requestData);
    } else if (operation == Operation::GetTodaysMenu) {
        response = handleGetTodaysMenu();
    } else if (operation == Operation::VoteItemFromTomorrowMenu) {
        response = handleVoteItemFromTomorrowMenu(requestData);
    } else if (operation == Operation::GetChefRollOutMenuForTomorrow) {
        response = handleGetChefRollOutMenuForTomorrow(requestData);
    } else if (operation == Operation::ProvideDiscardMenuItemDetailedFeedback) {
        response = handleProvideDiscardMenuItemDetailedFeedback(requestData);
    }else if(operation == Operation::UpdateProfile){
        response = handleUpdateProfile(requestData);
    } else {
        std::cerr << "[EmployeeHandler] Invalid operation: " << static_cast<int>(operation) << "\n";
        response = "Invalid operation";
    }
    return response;
}

std::string EmployeeHandler::handleViewNotifications() {
    std::vector<Notification> notificationDetails = notificationService->getAllNotifications();
    std::vector<std::string> notificationSerializedData;
    for (const auto& notification : notificationDetails) {
        notificationSerializedData.push_back(DataSerializer::serialize(notification));
    }
    std::cout << "[EmployeeHandler] View Notifications operation completed\n";
    return DataSerializer::serializeStringVector(notificationSerializedData);
}

std::string EmployeeHandler::handleProvideFeedback(const std::string& requestData) {
    std::string response;
    Feedback feedback = DataSerializer::deserialize<Feedback>(requestData);
    bool operationDone = feedbackService->addFeedback(feedback);
    if (operationDone) {
        std::cout << "[EmployeeHandler] Feedback Added Successfully\n";
        response = "Feedback Added Successfully";
    } else {
        std::cerr << "[EmployeeHandler] Failed to Add Feedback\n";
        response = "Failed to Add Feedback";
    }

    return response;
}

std::string EmployeeHandler::handleGetTodaysMenu() {
    std::vector<MenuItem> todaysMenu = todayMenuService->getAllTodayMenuItem();
    std::vector<MenuItem> sortedTodayMenu;

    for(int index = 1; index < 4; index++){
        std::vector<MenuItem> mealTypeMenuItems = filterMenuItemsByType(static_cast<MenuItemType>(index), todaysMenu);
        sortedTodayMenu.insert(sortedTodayMenu.end(), mealTypeMenuItems.begin(), mealTypeMenuItems.end());
    }
    if(todaysMenu.empty()) {
        std::cerr << "[EmployeeHandler] No menu items for today\n";
        return "0";
    }
    std::vector<std::string> serializedMenuItems;
    for (const auto& menuItem : sortedTodayMenu) {
        serializedMenuItems.push_back(DataSerializer::serialize(menuItem));
    }
    std::cout << "[EmployeeHandler] Get Today's Menu operation completed\n";
    return DataSerializer::serializeStringVector(serializedMenuItems);
}

std::string EmployeeHandler::handleVoteItemFromTomorrowMenu(const std::string& requestData) {
    std::string response = "";
    int menuItemId;
    try {
        menuItemId = std::stoi(requestData);
    } catch (const std::invalid_argument&) {
        std::cerr << "[EmployeeHandler] Invalid menu item ID\n";
        response = "Invalid menu item ID";
    }
    bool operationDone = nextDayMenuVotingService->increaseVoteCountForMenuItemId(menuItemId);
    if (operationDone) {
        std::cout << "[EmployeeHandler] Increased vote count for menu item ID: " << menuItemId << "\n";
        response = "Vote counted successfully";
    } else {
        std::cerr << "[EmployeeHandler] Failed to increase vote count\n";
        response = "Failed to count vote";
    }

    return response;
}

std::string EmployeeHandler::handleGetChefRollOutMenuForTomorrow(const std::string& requestData) {
    std::string response;
    int userId;
    try {
        userId = std::stoi(requestData);
    } catch (const std::invalid_argument&) {
        std::cerr << "[EmployeeHandler] Invalid user ID\n";
        response = "Invalid user ID";
    }
    std::vector<RollOutMenu> preferenceBasedRollOutMenu;
    std::vector<RollOutMenu> chefRolloutMenuForNextDay = getNextDayMenuItemsToRollOut();
    UserProfile userProfile = userProfileService->getUserProfileByID(userId);
    if(userProfile.userId == 0) {
        std::cerr << "[EmployeeHandler] User profile not found\n";
        return "0";
    }
    if(chefRolloutMenuForNextDay.empty()) {
        std::cerr << "[EmployeeHandler] No menu items rolled out for the next day\n";
        return "0";
    }
    for (int i = 0; i < 3; ++i) {
        std::vector<RollOutMenu> chefRollOutMenuForMealType = filterMenuItemsByType(static_cast<MenuItemType>(i + 1), chefRolloutMenuForNextDay);
        chefRollOutMenuForMealType = recommendationEngine->sortRecommendedMenuItemsBasedOnProfile(userProfile, chefRollOutMenuForMealType, menuItemService->getAllMenuItems());
        preferenceBasedRollOutMenu.insert(preferenceBasedRollOutMenu.end(), chefRollOutMenuForMealType.begin(), chefRollOutMenuForMealType.end());
    }
    std::vector<std::string> recommendedMenuItemSerializedData;
    for (const auto& menu : preferenceBasedRollOutMenu) {
        recommendedMenuItemSerializedData.push_back(DataSerializer::serialize(menu));
    }
    std::cout << "[EmployeeHandler] Get Chef Rollout Menu for Tomorrow operation completed\n";
    response = DataSerializer::serializeStringVector(recommendedMenuItemSerializedData);

    return response;
}

std::string EmployeeHandler::handleProvideDiscardMenuItemDetailedFeedback(const std::string& requestData) {
    std::string response = "";
    DiscardMenuItemDetailedFeedback feedback = DataSerializer::deserialize<DiscardMenuItemDetailedFeedback>(requestData);
    bool operationDone = discardMenuItemDetailedFeedbackService->addFeedback(feedback);
    if (operationDone) {
        std::cout << "[EmployeeHandler] Discard Menu Item Detailed Feedback Added Successfully\n";
        response = "Discard Menu Item Detailed Feedback Added Successfully";
    } else {
        std::cerr << "[EmployeeHandler] Failed to Add Discard Menu Item Detailed Feedback\n";
        response = "Failed to Add Discard Menu Item Detailed Feedback";
    }
    return response;
}

std::vector<RollOutMenu> EmployeeHandler::getNextDayMenuItemsToRollOut() {
    std::vector<NextDayMenuVoting> nextDayMenuVotingList = nextDayMenuVotingService->getAllRollOutMenuItem();
    std::vector<RollOutMenu> nextDayMenuRollOutItems = {};

    for (const auto& nextDayMenuItemId : nextDayMenuVotingList) {
        MenuItem menuItem = menuItemService->getMenuItemById(nextDayMenuItemId.menuItemId);

        RollOutMenu rollOutItem(
            menuItem.menuItemId,
            menuItem.menuItemName,
            menuItem.menuItemType,
            menuItem.price,
            nextDayMenuItemId.voteCount,
            nextDayMenuItemId.rating,
            nextDayMenuItemId.sentiments
        );

        nextDayMenuRollOutItems.push_back(rollOutItem);
    }

    return nextDayMenuRollOutItems;
}

template <typename T>
std::vector<T> EmployeeHandler::filterMenuItemsByType(MenuItemType menuItemType, const std::vector<T>& menuItems) {
    std::vector<T> filteredMenuItems;
    for (const auto& menuItem : menuItems) {
        if (menuItem.menuItemType == menuItemType) {
            filteredMenuItems.push_back(menuItem);
        }
    }
    return filteredMenuItems;
}

std::string EmployeeHandler::handleUpdateProfile(const std::string& requestData) {
    std::string response;
    UserProfile userProfile = DataSerializer::deserialize<UserProfile>(requestData);
    bool operationDone = userProfileService->updateUserProfile(userProfile);
    if (operationDone) {
        std::cout << "[EmployeeHandler] Profile Updated Successfully\n";
        response = "Profile Updated Successfully";
    } else {
        std::cerr << "[EmployeeHandler] Failed to Update Profile\n";
        response = "Failed to Update Profile";
    }

    return response;
}