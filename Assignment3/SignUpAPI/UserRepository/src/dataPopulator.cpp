#include "dataPopulator.h"
#include <iostream>

void DataPopulator::populateDefaultData(User *user) {
    user->setGender("FeMale");
    std::cout << "Default data populated for the user.\n";
}
