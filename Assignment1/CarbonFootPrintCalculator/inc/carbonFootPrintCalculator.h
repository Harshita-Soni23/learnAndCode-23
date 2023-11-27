#ifndef CARBON_FOOTPRINT_CALCULATOR_H
#define CARBON_FOOTPRINT_CALCULATOR_H

#include <iostream>
#include <memory>
#include <string>
#include <mailCredentials.h>
#include <ConnectionAPI.h>
#include <curl/curl.h>
#include <vector>

class CarbonFootprintCalculator {
public:
    void getCarbonFootPrint(const std::string &entityType, const std::string &entity, const std::string &password);

private:
    bool isValidEmail(const std::string &email);
    EmailsCount getEmailsCount(const std::string &entity, const std::string &password);
    std::string getEmailSource(const std::string &email) const;
};

#endif // CARBON_FOOTPRINT_CALCULATOR_H
