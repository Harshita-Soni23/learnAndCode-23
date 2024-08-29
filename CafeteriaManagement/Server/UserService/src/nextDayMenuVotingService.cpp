#include "nextDayMenuVotingService.h"


NextDayMenuVotingService::NextDayMenuVotingService(std::unique_ptr<NextDayMenuVotingDAO> nextDayMenuVotingDAO)
    : nextDayMenuVotingDAO(std::move(nextDayMenuVotingDAO)) {}

bool NextDayMenuVotingService::addRollOutMenu(const std::vector<NextDayMenuVoting>& nextDayMenu) {
    return nextDayMenuVotingDAO->addRollOutMenu(nextDayMenu);
}

std::vector<NextDayMenuVoting> NextDayMenuVotingService::getAllRollOutMenuItem() {
    return nextDayMenuVotingDAO->getAllRollOutMenuItem();
}

bool NextDayMenuVotingService::increaseVoteCountForMenuItemId(const int& menuItemId) {
    return nextDayMenuVotingDAO->increaseVoteCountForMenuItemId(menuItemId);
}

bool NextDayMenuVotingService::deleteMenuRolledOut(){
    return nextDayMenuVotingDAO->deleteMenuRolledOut();
}

std::vector<int> NextDayMenuVotingService::getMostVotedMenuItemIds(){
    std::vector<int> mostVotedMenuItemIds;
    mostVotedMenuItemIds.push_back(nextDayMenuVotingDAO->getMostVotedMenuItemIdForMenuType(MenuItemType::Breakfast));
    mostVotedMenuItemIds.push_back(nextDayMenuVotingDAO->getMostVotedMenuItemIdForMenuType(MenuItemType::Lunch));
    mostVotedMenuItemIds.push_back(nextDayMenuVotingDAO->getMostVotedMenuItemIdForMenuType(MenuItemType::Dinner));

    return mostVotedMenuItemIds;
}