#include "MailCounter.h"
#include <iostream>

CURLcode MailCounter::getMailCount(const MailCredentials &userCredentials, const std::string &folder, size_t &count)
{
    // auto emailSource = emailSourceRetriever.getEmailSource(userCredentials.getEmailId());
    // auto res = connection.getConnection(userCredentials, emailSource);

    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);

        curl_easy_setopt(curl, CURLOPT_URL, "imaps://imap.gmail.com:993");

        curl_easy_setopt(curl, CURLOPT_SSLVERSION, CURL_SSLVERSION_TLSv1_2);

        curl_easy_setopt(curl, CURLOPT_USERNAME, userCredentials.getEmailId().c_str());
        curl_easy_setopt(curl, CURLOPT_PASSWORD, userCredentials.getPassword().c_str());

        std::string command = "STATUS \"" + folder + "\" (MESSAGES)";
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, command.c_str());

        std::string response;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);

        if (res == CURLE_OK)
        {
            size_t pos = response.find("MESSAGES");
            if (pos != std::string::npos)
            {
                count = std::stoi(response.substr(pos + 9));
            }
            else
            {
                std::cerr << "Unable to parse the response." << std::endl;
                res = CURLE_READ_ERROR;
            }
        }
    }
    curl_easy_cleanup(curl);
    curl_global_cleanup();
    return res;
}