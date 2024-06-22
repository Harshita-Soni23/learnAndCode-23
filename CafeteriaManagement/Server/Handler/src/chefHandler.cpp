#include "chefHandler.h"

ChefHandler::ChefHandler() {}

std::vector<std::string> ChefHandler::handleRequest( std::vector<std::string> request) {
    std::vector<std::string> response;
    response.push_back("Chef Handler");
    return response;
}
