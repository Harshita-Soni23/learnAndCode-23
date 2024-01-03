#ifndef MAILCOUNTER_H
#define MAILCOUNTER_H 

#include "mailCredentials.h"
#include "ConnectionAPI.h"
#include "emailSourceRetriever.h"
#include <string>

class MailCounter {
public:
    CURLcode getMailCount(const MailCredentials& mailCredential, const std::string& folder, size_t& count);
private:
    ConnectionAPI connection;
    EmailSourceRetriever emailSourceRetriever;
};

#endif
