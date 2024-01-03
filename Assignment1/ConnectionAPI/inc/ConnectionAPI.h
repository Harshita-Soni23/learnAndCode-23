#ifndef CONNECTION_API_H
#define CONNECTION_API_H 

#include "mailCredentials.h"
#include <curl/curl.h>
#include <string>

class ConnectionAPI {
public:
    CURLcode getConnection(const MailCredentials& mailCredential, const std::string &emailSource);

private:
    size_t writeCallback(void* contents, size_t size, size_t nmemb, std::string* output);
};

#endif