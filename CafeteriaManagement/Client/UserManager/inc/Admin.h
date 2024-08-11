#pragme once

#include "server.h"
#include <vector>
#include <string>

class AdminHandler {
public:
    AdminHandler(int sessionId);

    void loginAdmin();
    void performAdminAction();
    void addMenuItem(std::vector<std::string> adminChoice);
    void updateMenuItem(std::vector<std::string> adminChoice);
    void deleteItemFromMenu(std::vector<std::string> adminChoice);
    void viewMenuItems();

private:
    int sessionId;
};
