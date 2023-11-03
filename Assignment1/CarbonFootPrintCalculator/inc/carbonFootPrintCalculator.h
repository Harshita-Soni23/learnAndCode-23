#ifndef CARBON_FOOTPRINT_CALCULATOR_H
#define CARBON_FOOTPRINT_CALCULATOR_H

#include <iostream>
#include <memory>
#include <string>

class CarbonFootprintCalculator {
public:
    void getCarbonFootPrint(const std::string &entityType, const std::string &entity);

private:
    bool isValidEmail(const std::string &email);
    std::vector<EmailInfo> getEmailInfo();
};

#endif // CARBON_FOOTPRINT_CALCULATOR_H
