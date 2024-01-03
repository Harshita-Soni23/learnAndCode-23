// EmailServer.cpp
#include "EmailServer.h"
#include "EmailStatus.h"

EmailServer::EmailServer(EmailConnection& connection) {
    curl = connection.getCurlHandle();
}

EmailServer::~EmailServer() {
    // No need to clean up curl handle here, as it's done in EmailConnection
}

CURLcode EmailServer::getStatus(const std::string& folder, size_t& count) {
    if (!curl) {
        return CURLE_FAILED_INIT;
    }

    std::string command = "STATUS \"" + folder + "\" (MESSAGES)";
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, command.c_str());

    std::string response;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    CURLcode res = curl_easy_perform(curl);

    if (res == CURLE_OK) {
        count = EmailStatus::parseMessageCount(response);
    }

    return res;
}
