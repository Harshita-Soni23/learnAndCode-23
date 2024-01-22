#ifndef CARBON_FOOTPRINT_CALCULATOR_H
#define CARBON_FOOTPRINT_CALCULATOR_H

#include <iostream>
#include <memory>
#include <string>
#include <emailValidator.h>
#include <emailSourceRetriever.h>
#include <mailCredentials.h>
#include <emailsCounter.h>
#include <ConnectionAPI.h>
#include <curl/curl.h>
#include <vector>

class CarbonFootprintCalculator {
public:
    void getCarbonFootPrint(const std::string &entityType, const std::string &entity, const std::string &password);
private:
    EmailsCounter emailsCounter;
    EmailSourceRetriever emailSourceRetriever;
    EmailValidator emailValidator;
};

#endif // CARBON_FOOTPRINT_CALCULATOR_H
