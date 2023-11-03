#ifndef EMAILCARBONFOOTPRINT_H
#define EMAILCARBONFOOTPRINT_H

#include <vector>
#include "emailInfo.h"
#include "carbonFootPrint.h"

class EmailCarbonFootPrint: public CarbonFootPrint {
public:
    EmailCarbonFootPrint(const std::vector<EmailInfo>& emails);
    
    EmailsCarbonFootPrint calculateCarbonFootPrint(const std::string& emailId) override;
    void displayCarbonFootPrint(const std::string &emailId, const EmailsCarbonFootPrint &emailsCarbonFootPrint) const;

private:
    std::vector<EmailInfo> emails;
    double inboxCarbonFootPrint;
    double sentCarbonFootPrint;
    double spamCarbonFootPrint;
};

#endif // EMAILCARBONFOOTPRINT_H
