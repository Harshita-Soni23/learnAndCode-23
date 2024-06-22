#include "IUserHandler.h"
#include "menuItemService.h"
#include "userService.h" 

class AdminHandler : public IUserHandler {
    private :
        MenuItemService* menuItemService;
        UserService* userService;

    public:
        AdminHandler(MenuItemService* menuItemService, UserService* userService);
        std::vector<std::string> handleRequest( std::vector<std::string> request) override;
};
