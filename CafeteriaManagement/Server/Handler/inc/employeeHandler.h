#include "IUserHandler.h"
#include "feedbackService.h"
#include "recommandationSelectionService.h"

class EmployeeHandler : public IUserHandler {
    private :
    FeedbackService* feedbackService;
    RecommendationSelectionService* recommandationSelectionService;

public:
    EmployeeHandler(FeedbackService* feedbackService, RecommendationSelectionService* recommandationSelectionService);
    std::vector<std::string> handleRequest(std::vector<std::string> request) override;

};
