#pragma once

#include "databaseConnection.h"
#include "discardMenuItemDetailedFeedback.h"
#include <vector>

class DiscardMenuItemDetailedFeedbackDAO{
public:
    DiscardMenuItemDetailedFeedbackDAO();

    int addFeedback(const DiscardMenuItemDetailedFeedback& feedback);
    DiscardMenuItemDetailedFeedback getFeedbackById(const int& id);
    std::vector<DiscardMenuItemDetailedFeedback> getAllFeedbacks();

private:
    std::shared_ptr<DatabaseConnection> databaseConnection;
};
