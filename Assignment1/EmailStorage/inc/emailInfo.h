#ifndef EMAILINFO_H
#define EMAILINFO_H

#include <string>

struct EmailsCount {
    double inbox;
    double sent;
    double spam;
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

#endif // EMAILINFO_H