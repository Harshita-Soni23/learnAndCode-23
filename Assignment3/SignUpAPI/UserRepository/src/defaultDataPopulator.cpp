#include "defaultDataPopulator.h"
#include <iostream>
#include <fstream>
#include <sstream>

void DefaultDataPopulator::populateDefaultData(User *user) {
    user->setGender("FeMale");
    user->setUserType("Viewer");
    std::ofstream userInfoFile(filename, std::ios::app);

    userInfoFile << user->getId() << ',' << user->getName() << ',' << user->getEmail() << ',' << user->getDirectoryPath() << ',' << user->getGender() << '\n';
    userInfoFile.close();
    std::cout << "Default data populated for the user.\n";
}
