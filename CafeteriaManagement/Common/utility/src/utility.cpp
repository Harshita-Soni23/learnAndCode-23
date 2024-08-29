#include "utility.h"
#include <limits>
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include "databaseconstants.h"
#include <sstream>

namespace Utility
{
    std::string getMenuItemType(MenuItemType menuItemType)
    {
        return menuItemType == MenuItemType::Breakfast ? "Breakfast" : menuItemType == MenuItemType::Lunch ? "Lunch"
                                                                   : menuItemType == MenuItemType::Dinner  ? "Dinner"
                                                                                                           : "Unknown";
    }

    std::string getVegetarianPreference(VegetarianPreference vegetarianPreference)
    {
        return vegetarianPreference == VegetarianPreference::Vegetarian ? "Vegetarian" : vegetarianPreference == VegetarianPreference::NonVegetarian ? "Non Vegetarian"
                                                                                     : vegetarianPreference == VegetarianPreference::Eggetarian      ? "Eggetarian"
                                                                                                                                                     : "Unknown";
    }

    std::string getSpiceLevelOption(SpiceLevelOption spiceLevelOption)
    {
        return spiceLevelOption == SpiceLevelOption::High ? "High" : spiceLevelOption == SpiceLevelOption::Medium ? "Medium"
                                                                 : spiceLevelOption == SpiceLevelOption::Low      ? "Low"
                                                                                                                  : "Unknown";
    }

    std::string getFoodPreference(FoodPreference foodPreference)
    {
        return foodPreference == FoodPreference::NorthIndian ? "North Indian" : foodPreference == FoodPreference::SouthIndian ? "South Indian"
                                                                            : foodPreference == FoodPreference::Other         ? "Other"
                                                                                                                              : "Unknown";
    }

    std::string getSweetToothPreference(SweetToothPreference sweetToothPreference)
    {
        return sweetToothPreference == SweetToothPreference::Yes ? "Yes" : "No";
    }

    int getValidatedChoice(int min, int max)
    {
        int choice;
        while (true)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter your choice (" << min << " to " << max << "): ";
            if (std::cin >> choice && choice >= min && choice <= max)
            {
                return choice;
            }
            std::cout << "Invalid input. Please enter a number between " << min << " and " << max << ": " << std::endl;
        }
    }

    std::string toLower(const std::string &str)
    {
        std::string lowerStr = str;
        std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
        return lowerStr;
    }

    std::vector<std::string> splitWords(const std::string &str)
    {
        std::vector<std::string> words;
        std::string word;
        for (char c : str)
        {
            if (std::isspace(c))
            {
                if (!word.empty())
                {
                    words.push_back(word);
                    word.clear();
                }
            }
            else
            {
                word += c;
            }
        }
        if (!word.empty())
        {
            words.push_back(word);
        }
        return words;
    }

    std::string getCurrentTimestamp()
    {
        auto now = std::chrono::system_clock::now();
        std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);

        std::tm now_tm = *std::localtime(&now_time_t);
        std::stringstream ss;
        ss << std::put_time(&now_tm, "%Y-%m-%d"); // Format as YYYY-MM-DD
        return ss.str();
    }

    void diplayMenuDetailsColumnNames()
    {
        std::cout << "***************Menu Item Details***************" << "\n"
                  << std::endl;
        std::cout << std::left
                  << std::setw(idWidth) << "ID"
                  << std::setw(nameWidth) << "Name"
                  << std::setw(typeWidth) << "Type"
                  << std::setw(availabilityWidth) << "Availability"
                  << std::setw(priceWidth) << "Price"
                  << std::setw(vegetarianWidth) << "Vegetarian Pref."
                  << std::setw(spiceLevelWidth) << "Spice Level"
                  << std::setw(cuisineWidth) << "Cuisine Pref."
                  << std::setw(sweetToothWidth) << "Sweet Tooth Pref."
                  << std::endl;
    }
}