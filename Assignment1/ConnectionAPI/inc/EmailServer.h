// EmailServer.h
#pragma once

#include <string>
#include <curl/curl.h>
#include "EmailConnection.h"

class EmailServer {
public:
    EmailServer(EmailConnection& connection);
    ~EmailServer();

    CURLcode getStatus(const std::string& folder, size_t& count);

private:
    CURL* curl;
};
