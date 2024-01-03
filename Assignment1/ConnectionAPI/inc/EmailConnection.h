// EmailConnection.h
#pragma once

#include <string>
#include <curl/curl.h>

class EmailConnection {
public:
    EmailConnection(const std::string& emailSource);
    ~EmailConnection();

    CURLcode establishConnection(const std::string& emailSource, const std::string& url, const std::string& username, const std::string& password);

private:
    CURL* curl;
};
