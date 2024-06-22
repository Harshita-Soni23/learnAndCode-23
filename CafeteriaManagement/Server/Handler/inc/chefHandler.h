#include "IUserHandler.h"

class ChefHandler : public IUserHandler {
    
public:
    ChefHandler();
    std::vector<std::string> handleRequest(std::vector<std::string> request) override;

};
