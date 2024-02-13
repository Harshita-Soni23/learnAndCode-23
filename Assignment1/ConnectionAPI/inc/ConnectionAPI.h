#ifndef CONNECTION_API_H
#define CONNECTION_API_H 

#include "userCredentials.h"
#include <curl/curl.h>
#include <string>

class ConnectionAPI {
public:
    CURL* getConnection(const UserCredentials& userCredential, const std::string &emailSource);
};

#endif