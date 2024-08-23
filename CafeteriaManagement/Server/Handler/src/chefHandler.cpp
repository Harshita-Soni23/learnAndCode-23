#include "chefHandler.h"

ChefHandler::ChefHandler(std::unique_ptr<MenuItemService> menuItemService,
                               std::unique_ptr<NextDayMenuVotingService> nextDayMenuVotingService,
                               std::unique_ptr<FeedbackService> feedbackService,
                               std::unique_ptr<RecommendationEngineService> recommendationEngine,
                               std::unique_ptr<TodayMenuService> todayMenuService,
                               std::unique_ptr<NotificationService> notificationService)
    : menuItemService(std::move(menuItemService)), nextDayMenuVotingService(std::move(nextDayMenuVotingService)),
      feedbackService(std::move(feedbackService)), recommendationEngine(std::move(recommendationEngine)),
      todayMenuService(std::move(todayMenuService)), notificationService(std::move(notificationService)) {}

std::string ChefHandler::handleRequest(Operation operation, const std::string& requestData) {
    std::cout << "[ChefHandler] Handling request: " << static_cast<int>(operation) << "\n";
    std::string response;

    if (operation == Operation::ViewMenu) {
        response = handleViewMenu();
    } else if (operation == Operation::RollOutMenuForNextDay) {
        response = handleRollOutMenuForNextDay(requestData);
    } else if (operation == Operation::GetRecommandationFromEngine) {
        response = handleGetRecommendationFromEngine(requestData);
    } else if (operation == Operation::PublishMenuForToday) {
        response = handlePublishMenuForToday();
    } else if (operation == Operation::GetDiscardMenuList) {
        response = handleGetDiscardMenuList();
    } else if (operation == Operation::RemoveMenuItemFromList) {
        response = handleRemoveMenuItemFromList(requestData);
    } else if (operation == Operation::GetMenuItemIdForDetailFeedbackFromChef) {
        response = handleGetMenuItemIdForDetailFeedbackFromChef(requestData);
    } else if (operation == Operation::GetNextDayMenuVoting) {
        response = handleGetNextDayMenuVoting();
    } else {
        std::cerr << "[ChefHandler] Invalid operation: " << static_cast<int>(operation) << "\n";
        response = "Invalid operation";
    }

    return response;
}

std::string ChefHandler::handleGetNextDayMenuVoting() {
    std::vector<NextDayMenuVoting> nextDayMenuVotingList = nextDayMenuVotingService->getAllRollOutMenuItem();
    std::vector<RollOutMenu> nextDayMenuRollOutItems = {};
    if(nextDayMenuVotingList.empty()) {
        std::cout << "[ChefHandler] Menu is not yet rolled out\n";
        return "0";
    }
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

    std::vector<std::string> nextDayMenuVotingSerializedData;
    for (const auto& menu : nextDayMenuRollOutItems) {
        nextDayMenuVotingSerializedData.push_back(DataSerializer::serialize(menu));
    }
    std::cout << "[ChefHandler] Next Day Menu Voting operation completed\n";
    return DataSerializer::serializeStringVector(nextDayMenuVotingSerializedData);
}

std::string ChefHandler::handleViewMenu() {
    std::vector<MenuItem> menuDetails = menuItemService->getAllMenuItems();
    std::vector<std::string> menuSerializedData;
    for (const auto& menu : menuDetails) {
        menuSerializedData.push_back(DataSerializer::serialize(menu));
    }
    std::cout << "[ChefHandler] View Menu operation completed\n";
    return DataSerializer::serializeStringVector(menuSerializedData);
}

std::string ChefHandler::handleRollOutMenuForNextDay(const std::string& requestData) {
    std::string response;
    std::cout << "[ChefHandler] RollOutMenuForNextDay called\n";
    std::vector<std::string> menuItemIdToRollOutMenu = DataSerializer::deserializeStringToVector(requestData);
    std::vector<int> menuItemIdsForNextDayMenu;
    for (const auto& menuItemForMenuType : menuItemIdToRollOutMenu) {
        std::vector<std::string> menuItemIds = DataSerializer::deserializeStringToVector(menuItemForMenuType, ',');
        for (const auto& menuItemId : menuItemIds) {
            menuItemIdsForNextDayMenu.push_back(std::stoi(menuItemId));
        }
    }
    bool operationDone = rollOutFinalMenuByChefForNextDay(menuItemIdsForNextDayMenu);
    if (operationDone) {
        pushNotification(Operation::RollOutMenuForNextDay, "Menu rolled out successfully for next day");
        response = "Menu rolled out successfully for next day";
    } else {
        response = "Failed to roll out menu for next day";
    }

    return response;
}

std::string ChefHandler::handleGetRecommendationFromEngine(const std::string& requestData) {
    std::vector<RollOutMenu> recommendedMenuItem = getTopMenuRecommendationFromEngine(static_cast<MenuItemType>(std::stoi(requestData)));
    std::vector<std::string> recommendedMenuItemSerializedData;
    for (const auto& menu : recommendedMenuItem) {
        recommendedMenuItemSerializedData.push_back(DataSerializer::serialize(menu));
    }
    std::cout << "[ChefHandler] Recommended Menu from Engine operation completed\n";
    return DataSerializer::serializeStringVector(recommendedMenuItemSerializedData);
}

std::string ChefHandler::handlePublishMenuForToday() {
    std::string response;
    std::vector<int> publishedMenuItemIds = publishMostVotedMenuItems();
    if (publishedMenuItemIds.size() > 0){
        std::vector<MenuItem> todaysMenuPublished = {};
        for(const auto& menuItemId : publishedMenuItemIds) {
            todaysMenuPublished.push_back(menuItemService->getMenuItemById(menuItemId));
        }

        std::vector<std::string> todaysMenuSerializedData;
        for (const auto& menu : todaysMenuPublished) {
            todaysMenuSerializedData.push_back(DataSerializer::serialize(menu));
        }

        std::string serializedTodaysMenu = DataSerializer::serializeStringVector(todaysMenuSerializedData);
        
        pushNotification(Operation::PublishMenuForToday, "Today's menu has been published");
        response = serializedTodaysMenu;
    } else {
        response = "Failed to publish today's menu";
    }

    return response;
}

std::string ChefHandler::handleGetDiscardMenuList() {
    std::unordered_map<int, std::vector<Feedback>> feedbackMap = feedbackService->getAllFeedbacks();
    std::vector<MenuItem> menuItems = menuItemService->getAllMenuItems();
    std::vector<NextDayMenuVoting> discardMenuList = recommendationEngine->generateDiscardMenuList(feedbackMap, menuItems);
    std::vector<RollOutMenu> discardedMenuItemList = getNextDayMenuItemsToRollOut(discardMenuList);
    std::vector<std::string> discardMenuSerializedData;
    for (const auto& menu : discardedMenuItemList) {
        discardMenuSerializedData.push_back(DataSerializer::serialize(menu));
    }
    std::cout << "[ChefHandler] Discard Menu List operation completed\n";
    return DataSerializer::serializeStringVector(discardMenuSerializedData);
}

std::string ChefHandler::handleRemoveMenuItemFromList(const std::string& requestData) {
    std::string response;
    MenuItem menuItem = menuItemService->deleteMenuItemById(std::stoi(requestData));
    if (menuItem.menuItemId != 0) {
        pushNotification(Operation::DeleteMenuItem, menuItem.menuItemName);
        response = "Menu Item Deleted Successfully";
    } else {
        response = "Menu Item Not Deleted";
    }
    return response;
}

std::string ChefHandler::handleGetMenuItemIdForDetailFeedbackFromChef(const std::string& requestData) {
    pushNotification(Operation::GetMenuItemIdForDetailFeedbackFromChef, requestData);
    return "Notification Sent to User for Detailed Feedback";
}

std::vector<RollOutMenu> ChefHandler::getTopMenuRecommendationFromEngine(MenuItemType menuItemType) {
    std::cout << "[ChefHandler] Inside getTopMenuRecommendationFromEngine\n";
    std::unordered_map<int, std::vector<Feedback>> feedbackMap = feedbackService->getAllFeedbacks();
    std::vector<MenuItem> menuItems = menuItemService->getAllMenuItems();
    std::vector<NextDayMenuVoting> nextDayMenuRecommendationForMenuType = recommendationEngine->recommendTopFoodItems(menuItemType, feedbackMap, menuItems);
    nextDayMenuRecommendation.insert(nextDayMenuRecommendation.end(),
                                     nextDayMenuRecommendationForMenuType.begin(),
                                     nextDayMenuRecommendationForMenuType.end());
    return getNextDayMenuItemsToRollOut(nextDayMenuRecommendationForMenuType);
}

std::vector<RollOutMenu> ChefHandler::getNextDayMenuItemsToRollOut(const std::vector<NextDayMenuVoting>& nextDayMenuToRollOut) {
    std::vector<RollOutMenu> nextDayMenuRollOutItems;

    for (const auto& nextDayMenuItemId : nextDayMenuToRollOut) {
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

bool ChefHandler::rollOutFinalMenuByChefForNextDay(const std::vector<int>& menuItemIds) {
    std::cout << "[ChefHandler] rollOutFinalMenuByChefForNextDay: entry\n";
    std::vector<NextDayMenuVoting> finalChefMenuForNextDay;

    for (const auto& menuId : menuItemIds) {
        auto it = std::find_if(nextDayMenuRecommendation.begin(), nextDayMenuRecommendation.end(),
                               [&menuId](const NextDayMenuVoting& voting) {
                                   return voting.menuItemId == menuId;
                               });

        if (it != nextDayMenuRecommendation.end()) {
            finalChefMenuForNextDay.push_back(*it);
        } else {
            std::cout << "[ChefHandler] Item not found in Recommendation Engine suggestion\n";
        }
    }

    std::cout << "[ChefHandler] Adding recommended menu data into table by chef\n";
    nextDayMenuVotingService->deleteMenuRolledOut();
    bool operationDone = nextDayMenuVotingService->addRollOutMenu(finalChefMenuForNextDay);
    nextDayMenuRecommendation.clear();
    return operationDone;
}

std::vector<int> ChefHandler::publishMostVotedMenuItems() {
    std::vector<int> mostVotedMenuItemIds = nextDayMenuVotingService->getMostVotedMenuItemIds();
    todayMenuService->deleteTodayMenu();
    bool publishedTodaysMenu =  todayMenuService->addTodayMenu(mostVotedMenuItemIds);
    if(publishedTodaysMenu) {
        nextDayMenuVotingService->deleteMenuRolledOut();
        return mostVotedMenuItemIds;
    }
    return {};
}

bool ChefHandler::pushNotification(Operation operation, const std::string& message) {
    Notification notification;
    if (operation == Operation::PublishMenuForToday) {
        notification.notificationTitle = "Today's Menu Published";
        notification.message = "Today's menu has been published.";
    } else if (operation == Operation::RollOutMenuForNextDay) {
        notification.notificationTitle = "Menu Rollout For Next Day";
        notification.message = "Chef has rolled out the menu items for the next day. Check it out in the User Menu.";
    } else if (operation == Operation::DeleteMenuItem) {
        notification.notificationTitle = "Menu Item Deleted";
        notification.message = message + " has been deleted from the menu.";
    } else if (operation == Operation::GetMenuItemIdForDetailFeedbackFromChef) {
        notification.notificationTitle = "Feedback for Discarded Menu Item";
        notification.message = "Menu Item ID: " + message + " has low ratings and bad comments. Please share detailed feedback on this menu item.";
    } else {
        return false;
    }
    return notificationService->addNotification(notification);
}
