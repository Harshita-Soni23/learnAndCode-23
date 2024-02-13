#include "emailCarbonFootPrint.h"
#include <iostream>

#define INBOX_CARBONFOOTPRINT 0.3;
#define SENT_CARBONFOOTPRINT 0.2;
#define SPAM_CARBONFOOTPRINT 0.03;

EmailCarbonFootPrint::EmailCarbonFootPrint(const std::string &entity, const EmailsCount &emailsCount) : entity(entity), emailsCount(emailsCount) {
}

EmailsCarbonFootPrint EmailCarbonFootPrint::calculateCarbonFootPrint()
{
    EmailsCarbonFootPrint emailCarbonFootPrint;
    emailCarbonFootPrint.inboxCarbonFootPrint = emailsCount.inbox * INBOX_CARBONFOOTPRINT;
    emailCarbonFootPrint.sentCarbonFootPrint = emailsCount.sent * SENT_CARBONFOOTPRINT;
    emailCarbonFootPrint.spamCarbonFootPrint = emailsCount.spam * SPAM_CARBONFOOTPRINT;

    return emailCarbonFootPrint;
}

void EmailCarbonFootPrint::displayCarbonFootPrint(const std::string &emailId, const std::string &emailSource, const EmailsCarbonFootPrint &emailsCarbonFootPrint){
        std::cout << "email (entityType basis)" << std::endl;
        std::cout << "  emailId : " << emailId << std::endl;
        std::cout << "  emailSource : " << emailSource << std::endl;
        std::cout << "  inbox : " << emailsCarbonFootPrint.inboxCarbonFootPrint << " KG" << std::endl;
        std::cout << "  sent : " << emailsCarbonFootPrint.sentCarbonFootPrint << " KG" << std::endl;
        std::cout << "  spam : " << emailsCarbonFootPrint.spamCarbonFootPrint << " KG" << std::endl;
}
