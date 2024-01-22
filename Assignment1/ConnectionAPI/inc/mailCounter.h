#ifndef MAILCOUNTER_H
#define MAILCOUNTER_H 

#include "mailCredentials.h"
#include "ConnectionAPI.h"
#include "emailSourceRetriever.h"
#include <string>

class MailCounter {
public:
    size_t getMailCount(const MailCredentials& mailCredential, const std::string& folder);
private:
    ConnectionAPI connection;
    EmailSourceRetriever emailSourceRetriever;
    size_t static writeCallback(void* contents, size_t size, size_t nmemb, std::string* output);
};

#endif
