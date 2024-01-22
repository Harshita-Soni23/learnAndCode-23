#include "ConnectionAPI.h"
#include <iostream>

CURL* ConnectionAPI::getConnection(const MailCredentials &userCredentials, const std::string &emailSource) 
{
    CURL *curl = nullptr;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);

        if(emailSource == "gmail")
            curl_easy_setopt(curl, CURLOPT_URL, "imaps://imap.gmail.com:993");
        else if(emailSource == "outlook")
            curl_easy_setopt(curl, CURLOPT_URL, "imaps://outlook.office365.com:993");
        else if(emailSource == "yahoo")
            curl_easy_setopt(curl, CURLOPT_URL, "imaps://imap.mail.yahoo.com:993");

        curl_easy_setopt(curl, CURLOPT_SSLVERSION, CURL_SSLVERSION_TLSv1_2);

        curl_easy_setopt(curl, CURLOPT_USERNAME, userCredentials.getEmailId().c_str());
        curl_easy_setopt(curl, CURLOPT_PASSWORD, userCredentials.getPassword().c_str());
    }
    return curl;
}
