#pragma once

#include"nextDayMenuVotingDAO.h"
#include <vector>
#include<memory>

class NextDayMenuVotingService
{
public:
    NextDayMenuVotingService(std::unique_ptr<NextDayMenuVotingDAO> nextDayMenuVotingDAO);
    bool addRollOutMenu(const std::vector<NextDayMenuVoting>& nextDayMenu);
    std::vector<NextDayMenuVoting> getAllRollOutMenuItem();
    bool increaseVoteCountForMenuItemId(const int& menuItemId);
    bool deleteMenuRolledOut();
    std::vector<int> getMostVotedMenuItemIds();
    ~NextDayMenuVotingService() = default;
private:
    std::unique_ptr<NextDayMenuVotingDAO> nextDayMenuVotingDAO;
};
