#ifndef CONNECTION_API_H
#define CONNECTION_API_H 

#include "mailCredentials.h"
#include <curl/curl.h>
#include <string>

class ConnectionAPI {
public:
    CURL* getConnection(const MailCredentials& mailCredential, const std::string &emailSource);
};

#endif