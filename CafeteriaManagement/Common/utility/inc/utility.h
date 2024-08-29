#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <unordered_set>
#include <vector>
#include "menuItem.h"

namespace Utility {
    std::string getMenuItemType(MenuItemType menuItemType);
    std::string getVegetarianPreference(VegetarianPreference vegetarianPreference);
    std::string getSpiceLevelOption(SpiceLevelOption spiceLevelOption);
    std::string getFoodPreference(FoodPreference foodPreference);
    std::string getSweetToothPreference(SweetToothPreference sweetToothPreference);
    int getValidatedChoice(int min, int max);
    std::string toLower(const std::string &str);
    std::vector<std::string> splitWords(const std::string &str);
    std::string getCurrentTimestamp();
    void diplayMenuDetailsColumnNames();
}
