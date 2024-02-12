#ifndef EMAILCARBONFOOTPRINT_H
#define EMAILCARBONFOOTPRINT_H

#include <vector>
#include "emailInfo.h"
#include "carbonFootPrint.h"

class EmailCarbonFootPrint: public CarbonFootPrint {
public:
    EmailCarbonFootPrint(const std::string &entity, const EmailsCount& emailsCount);
    void displayCarbonFootPrint(const std::string &emailId, const std::string &emailSource, const EmailsCarbonFootPrint &emailsCarbonFootPrint);

private:
    EmailsCarbonFootPrint calculateCarbonFootPrint() override;

    EmailsCount emailsCount;
    std::string entity;
};

#endif
