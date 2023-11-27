#include "ConnectionAPI.h"
#include <iostream>

CURLcode ConnectionAPI::getConnection(const MailCredentials &userCredentials, const std::string &emailSource) 
{
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
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

        res = curl_easy_perform(curl);

        curl_easy_cleanup(curl);
    }
    else
    {
        std::cerr << "Error initializing curl." << std::endl;
        res = CURLE_FAILED_INIT;
    }

    curl_global_cleanup();
    return res;
}

CURLcode ConnectionAPI::getMailCount(const MailCredentials &userCredentials, const std::string &folder, size_t &count)
{
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
        curl_easy_cleanup(curl);
    }
    else
    {
        std::cerr << "Error initializing curl." << std::endl;
        res = CURLE_FAILED_INIT;
    }

    curl_global_cleanup();
    return res;
}

size_t ConnectionAPI::WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t total_size = size * nmemb;
    output->append(static_cast<char*>(contents), total_size);
    return total_size;
}
