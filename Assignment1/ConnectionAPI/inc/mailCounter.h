#ifndef MAILCOUNTER_H
#define MAILCOUNTER_H 

#include "userCredentials.h"
#include "ConnectionAPI.h"
#include "emailSourceRetriever.h"
#include <string>

class MailCounter {
public:
    size_t getMailCount(const UserCredentials& userCredential, const std::string& folder);
private:
    ConnectionAPI connection;
    EmailSourceRetriever emailSourceRetriever;
    size_t static writeCallback(void* contents, size_t size, size_t nmemb, std::string* output);
};

#endif
