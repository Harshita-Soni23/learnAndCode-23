#pragma once
#include "ISerializer.h"
#include "userProfileType.h"
#include <sstream>

struct UserProfile : public ISerializer {
    int userId = 0;
    VegetarianPreference vegetarianPreference = VegetarianPreference::Vegetarian;
    SpiceLevelOption spiceLevelOption = SpiceLevelOption::High;
    FoodPreference FoodPreference = FoodPreference::NorthIndian;
    SweetToothPreference sweetToothPreference = SweetToothPreference::Yes;

    UserProfile(int userId, VegetarianPreference vegetarianPreference, SpiceLevelOption spiceLevelOption, 
                FoodPreference FoodPreference, SweetToothPreference sweetToothPreference)
        : userId(userId), vegetarianPreference(vegetarianPreference), spiceLevelOption(spiceLevelOption), 
          FoodPreference(FoodPreference), sweetToothPreference(sweetToothPreference) {}

    UserProfile() {}

    std::string serialize() const override {
        return std::to_string(userId) + ";" + std::to_string(static_cast<int>(vegetarianPreference)) + ";" + 
               std::to_string(static_cast<int>(spiceLevelOption)) + ";" + std::to_string(static_cast<int>(FoodPreference)) + ";" + 
               std::to_string(static_cast<int>(sweetToothPreference));
    }

    void deserialize(const std::string& data) override {
        std::istringstream iss(data);
        std::string token;
        std::getline(iss, token, ';');
        userId = std::stoi(token);
        std::getline(iss, token, ';');
        vegetarianPreference = static_cast<VegetarianPreference>(std::stoi(token));
        std::getline(iss, token, ';');
        spiceLevelOption = static_cast<SpiceLevelOption>(std::stoi(token));
        std::getline(iss, token, ';');
        FoodPreference = static_cast<FoodPreference>(std::stoi(token));
        std::getline(iss, token, ';');
        sweetToothPreference = static_cast<SweetToothPreference>(std::stoi(token));
    }
};
