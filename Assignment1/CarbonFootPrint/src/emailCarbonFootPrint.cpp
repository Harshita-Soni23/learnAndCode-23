#include "emailCarbonFootPrint.h"
#include <iostream>

EmailCarbonFootPrint::EmailCarbonFootPrint(const std::vector<EmailInfo>& emails) : emails(emails) {
    inboxCarbonFootPrint = 0.0;
    sentCarbonFootPrint = 0.0;
    spamCarbonFootPrint = 0.0;
}

EmailsCarbonFootPrint EmailCarbonFootPrint::calculateCarbonFootPrint(const std::string& emailId) {
    bool found = false;
    EmailsCarbonFootPrint emailCarbonFootPrint;
    for (const EmailInfo& email : emails) {
        if (email.emailId == emailId) {
            emailCarbonFootPrint.inboxCarbonFootPrint = email.emailsCount.inbox * 0.3;
            emailCarbonFootPrint.sentCarbonFootPrint = email.emailsCount.sent * 0.2;
            emailCarbonFootPrint.spamCarbonFootPrint = email.emailsCount.spam * 0.03 ;
            found = true;
            break;
        }
    }
    if (!found) {
        throw std::runtime_error("Email not found in the data.");
    }
    else
    {
        return emailCarbonFootPrint;
    }
}

void EmailCarbonFootPrint::displayCarbonFootPrint(const std::string &emailId, const EmailsCarbonFootPrint &emailsCarbonFootPrint) const{

    for (const EmailInfo& email : emails) {
        if (email.emailId == emailId) {
        std::cout << "email (entityType basis)" << std::endl;
        std::cout << "emailId : " << email.emailId << std::endl;
        std::cout << "source : " << email.source << std::endl;
        std::cout << "inbox : " << emailsCarbonFootPrint.inboxCarbonFootPrint << " KG" << std::endl;
        std::cout << "sent : " << emailsCarbonFootPrint.sentCarbonFootPrint << " KG" << std::endl;
        std::cout << "spam : " << emailsCarbonFootPrint.spamCarbonFootPrint << " KG" << std::endl;
        }
    }
}
