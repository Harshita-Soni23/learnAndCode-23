#pragma once

#include "discardMenuItemDetailedFeedbackDAO.h"
#include <memory>
#include <vector>

class DiscardMenuItemDetailedFeedbackService {
public:
    DiscardMenuItemDetailedFeedbackService(std::unique_ptr<DiscardMenuItemDetailedFeedbackDAO> dao);

    int addFeedback(const DiscardMenuItemDetailedFeedback& feedback);
    DiscardMenuItemDetailedFeedback getFeedbackById(const int& id);
    std::vector<DiscardMenuItemDetailedFeedback> getAllFeedbacks();

private:
    std::unique_ptr<DiscardMenuItemDetailedFeedbackDAO> discardMenuItemDetailedFeedbackDAO;
};
