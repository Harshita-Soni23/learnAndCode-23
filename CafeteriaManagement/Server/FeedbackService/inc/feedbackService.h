#include"IFeedbackDAO.h"

class FeedbackService {
public:
    FeedbackService(IFeedbackDAO* feedbackDAO);
    bool addFeedback(const Feedback& feedback);
    std::vector<Feedback> getAllFeedbacks();
    std::vector<Feedback> getFeedbacksForMenuType(MenuItemType menuItemType);
private:
    IFeedbackDAO* feedbackDAO;
};