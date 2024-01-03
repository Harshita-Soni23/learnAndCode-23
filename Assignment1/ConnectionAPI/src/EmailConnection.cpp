// EmailConnection.cpp
#include "EmailConnection.h"

EmailConnection::EmailConnection(const std::string& emailSource) {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
}

EmailConnection::~EmailConnection() {
    if (curl) {
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

CURLcode EmailConnection::establishConnection(const std::string& emailSource, const std::string& url, const std::string& username, const std::string& password) {
    CURLcode res = CURLE_OK;

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_SSLVERSION, CURL_SSLVERSION_TLSv1_2);
        curl_easy_setopt(curl, CURLOPT_USERNAME, username.c_str());
        curl_easy_setopt(curl, CURLOPT_PASSWORD, password.c_str());

        res = curl_easy_perform(curl);
    } else {
        res = CURLE_FAILED_INIT;
    }

    return res;
}
