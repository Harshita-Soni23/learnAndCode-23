#pragma once

#include <string>
#include <vector>

class FeedbackDAO {
public:
    FeedbackDAO();
    ~FeedbackDAO();

    void addFeedback(const std::string& feedback);
    void deleteFeedback(int feedbackId);
    std::vector<std::string> getAllFeedbacks();
    std::string getFeedbackById(int feedbackId);
    std::vector<std::string> getFeedbacksByMenuId(int menuId);
    std::vector<std::string> getFeedbacksByUserId(int userId);
    void updateFeedback(int feedbackId, const std::string& updatedFeedback);

private:
    void* dbConnection;
};
