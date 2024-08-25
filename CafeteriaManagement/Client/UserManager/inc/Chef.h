#pragma once

#include "IUser.h"

class Chef : public IUser {
private:
    RequestHandler* requestHandler;

    void showRecommendedMenuAndRolloutForTomorrow();
    void rollOutMenuForTomorrow(std::vector<std::pair<MenuItemType, int>> recommendedMenuItem);
    void showMenuItemList();
    void publishMenuForToday();
    void showDiscardMenuList();
    void showNextDayMenuVoting();
    void showDiscardMenuItemActionPrompt(const std::vector<int>& discardMenuItemIdList);
    void removeMenuItemFromList(const std::vector<int>& discardMenuItemIdList);
    void getMenuItemIdForDetailedFeedback(const std::vector<int>& discardMenuItemIdList);
    std::vector<std::pair<MenuItemType, int>> showRecommendedMenu(MenuItemType menuItemType);
    std::string getValidMenuItemIdsForMealType(const std::vector<std::pair<MenuItemType, int>>& recommendedMenuItem, MenuItemType menuItemType);
    std::string validateMenuItemsAgainstRecommendedItems(const std::vector<std::pair<MenuItemType, int>>& recommendedMenuItem,
                            const std::string& menuItemString,
                            MenuItemType menuItemType);
    void displayMenuItemDetails(const MenuItem& menuItem);

public:
    Chef(RequestHandler* requestHandler);

    void handleUserOperations() override;
};
