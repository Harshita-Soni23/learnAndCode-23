#include "employeeHandler.h"

EmployeeHandler::EmployeeHandler(FeedbackService* feedbackService, RecommendationSelectionService* recommandationSelectionService) : feedbackService(feedbackService), recommandationSelectionService(recommandationSelectionService)  {}


std::vector<std::string> EmployeeHandler::handleRequest(std::vector<std::string> request) {
    std::vector<std::string> response;

    switch (std::stoi(request[0])) {
        case Operation::GetMenuAndProvideFeedback:
           
            break;
        case Operation::SelectItemFromTomorrowMenu:
            
            break;
        default:
            response.push_back("Invalid operation");
            break;
    }
    return response;
}

