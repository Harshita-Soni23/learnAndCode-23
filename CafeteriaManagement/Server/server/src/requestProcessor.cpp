#include "requestProcessor.h"
#include "clientOperationType.h"
#include "dataBaseConstants.h"

RequestProcessor::RequestProcessor() {
    DatabaseConnection::initDbConnection(DATABASE_HOST, DATABASE_USER, DATABASE_PASSWORD, DATABASE_NAME);
    auto userService = std::make_unique<UserService>(std::make_unique<UserDAO>());
    auto authenticationService = std::make_unique<AuthenticationService>(std::move(userService));
    authenticationHandler = std::make_unique<AuthenticationHandler>(std::move(userService), std::move(authenticationService));
}

std::string RequestProcessor::processRequest(const std::string& request) {
    std::pair<Operation, std::string> requestData = DataSerializer::deserializeOperation(request);
    std::string response;

    switch (requestData.first) {
        case Operation::LoginUser:
            response = handleLoginRequest(requestData.second);
            break;
        default:
            response = handleUserRequest(requestData.first, requestData.second);
            break;
    }

    return response;
}

std::string RequestProcessor::handleLoginRequest(const std::string& requestData) {
    int userAuthenticated = authenticationHandler->authenticateUser(requestData);
    std::string response = std::to_string(userAuthenticated);

    if (userAuthenticated == 1) {
        std::cout << "Admin LoggedIn" << std::endl;
        userHandler = serverFactory.initializeAdminHandler();
    } else if (userAuthenticated == 2) {
        std::cout << "Employee LoggedIn" << std::endl;
        userHandler = serverFactory.initializeEmployeeHandler();
    } else if (userAuthenticated == 3) {
        std::cout << "Chef LoggedIn" << std::endl;
        userHandler = serverFactory.initializeChefHandler();
    } else {
        std::cout << "Invalid Username Password" << std::endl;
    }
    return response;
}

std::string RequestProcessor::handleUserRequest(Operation operation, const std::string& requestData) {
    std::string response;

    switch (operation) {
        case Operation::AddUser:
        case Operation::AddMenuItem:
        case Operation::DeleteMenuItem:
        case Operation::UpdateMenuItem:
        case Operation::ViewMenu:
        case Operation::RollOutMenuForNextDay:
        case Operation::GenerateReport:
        case Operation::PublishMenuForToday:
        case Operation::ViewNotification:
        case Operation::ProvideFeedback:
        case Operation::VoteItemFromTomorrowMenu:
        case Operation::GetRecommandationFromEngine:
        case Operation::GetTodaysMenu:
        case Operation::GetChefRollOutMenuForTomorrow:
        case Operation::GetDiscardMenuList:
        case Operation::RemoveMenuItemFromList:
        case Operation::ProvideDiscardMenuItemDetailedFeedback:
        case Operation::GetMenuItemIdForDetailFeedbackFromChef:
            std::cout << "Handle Request called" << std::endl;
            if (userHandler) {
                response =  userHandler->handleRequest(operation, requestData);
            } else {
                response =  "User not authenticated.";
            }
            break;
        default:
            response =  "Invalid Operation";
            break;
    }
    return response;
}
