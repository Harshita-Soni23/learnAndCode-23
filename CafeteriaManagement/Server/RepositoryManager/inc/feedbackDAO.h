#pragma once

#include <vector>
#include "feedback.h"
#include "menuItem.h"
#include "databaseConnection.h"

class FeedbackDAO{
public:
    FeedbackDAO();

    bool addFeedback(const Feedback& feedback) ;
    bool deleteFeedbackByID(const int& feedbackId) ;
    Feedback getFeedbackById(const int& feedbackId) ;
    std::vector<Feedback> getFeedbacksByMenuItemId(const int& menuItemId) ;
    std::vector<Feedback> getAllFeedbacks() ;
    std::vector<Feedback> getFeedbacksForMenuType(MenuItemType menuItemType) ;

private:
    std::shared_ptr<DatabaseConnection> databaseConnection;
};
