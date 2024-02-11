#ifndef EMAILINFO_H
#define EMAILINFO_H

#include <string>

struct EmailsCount
{
    size_t inbox = 0 ;
    size_t sent = 0;
    size_t spam = 0;
};
struct EmailInfo {
    std::string emailId;
    std::string source;
    EmailsCount emailsCount;
};

struct EmailsCarbonFootPrint {
    double inboxCarbonFootPrint;
    double sentCarbonFootPrint;
    double spamCarbonFootPrint;
};

#endif
