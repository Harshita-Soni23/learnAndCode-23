#pragma once

#include <curl/curl.h>
#include "mailCredentials.h"
#include <string>

class ConnectionAPI {
public:
    static CURLcode getConnection(const MailCredentials& mailCredential, const std::string &emailSource);
    static CURLcode getMailCount(const MailCredentials& mailCredential, const std::string& folder, size_t& count);

private:
    static CURLcode setupConnection(CURL *curl, const MailCredentials &userCredentials);
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output);
};
