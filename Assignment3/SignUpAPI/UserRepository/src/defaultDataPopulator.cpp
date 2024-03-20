#include "defaultDataPopulator.h"
#include <iostream>

void DefaultDataPopulator::populateDefaultData(User& user) {
    user.setGender("FeMale");
    std::cout << "Default data populated for the user.\n";
}
