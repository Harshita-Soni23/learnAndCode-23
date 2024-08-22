#pragma once

#include "databaseConnection.h"
#include "menuItem.h"
#include "nextDayMenuVoting.h"
#include <vector>

class NextDayMenuVotingDAO{
public:
    NextDayMenuVotingDAO();

    bool addRollOutMenu(const std::vector<NextDayMenuVoting>& nextDayMenu);
    std::vector<NextDayMenuVoting> getAllRollOutMenuItem();
    bool increaseVoteCountForMenuItemId(const int& menuItemId);
    bool deleteMenuRolledOut();
    int getMostVotedMenuItemIdForMenuType(MenuItemType menuItemType);

private:
    std::shared_ptr<DatabaseConnection> databaseConnection;
};
