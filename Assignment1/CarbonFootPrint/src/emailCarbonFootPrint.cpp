#include "emailCarbonFootPrint.h"
#include <iostream>

#define INBOX_CARBONFOOTPRINT 0.3;
#define SENT_CARBONFOOTPRINT 0.2;
#define SPAM_CARBONFOOTPRINT 0.03;

EmailCarbonFootPrint::EmailCarbonFootPrint(const std::vector<EmailInfo>& emails) : emails(emails) {
    inboxCarbonFootPrint = 0.0;
    sentCarbonFootPrint = 0.0;
    spamCarbonFootPrint = 0.0;
}

EmailsCarbonFootPrint EmailCarbonFootPrint::calculateCarbonFootPrint(const std::string& emailId) {
    bool isFound = false;
    EmailsCarbonFootPrint emailCarbonFootPrint;
    for (const EmailInfo& email : emails) {
        if (email.emailId == emailId) {
            emailCarbonFootPrint.inboxCarbonFootPrint = email.emailsCount.inbox * INBOX_CARBONFOOTPRINT;
            emailCarbonFootPrint.sentCarbonFootPrint = email.emailsCount.sent * SENT_CARBONFOOTPRINT;
            emailCarbonFootPrint.spamCarbonFootPrint = email.emailsCount.spam * SPAM_CARBONFOOTPRINT;
            isFound = true;
            break;
        }
    }
    if (!isFound) {
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
