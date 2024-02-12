#ifndef CARBON_FOOTPRINT_CALCULATOR_H
#define CARBON_FOOTPRINT_CALCULATOR_H

#include <iostream>
#include <memory>
#include <string>
#include <emailValidator.h>
#include <emailSourceRetriever.h>
#include <entityInput.h>
#include <userCredentials.h>
#include <emailsCounter.h>
#include <ConnectionAPI.h>
#include <curl/curl.h>
#include <vector>

class CarbonFootprintCalculator {
public:
    void getCarbonFootPrint(const EntityInput& input);
private:
    EmailsCounter emailsCounter;
    EmailSourceRetriever emailSourceRetriever;
    EmailValidator emailValidator;
};

#endif // CARBON_FOOTPRINT_CALCULATOR_H
