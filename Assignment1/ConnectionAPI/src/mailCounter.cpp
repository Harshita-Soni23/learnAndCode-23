#include "mailCounter.h"
#include <iostream>

size_t MailCounter::getMailCount(const UserCredentials &userCredentials, const std::string &folder)
{
    auto emailSource = emailSourceRetriever.getEmailSource(userCredentials.getEmailId());
    auto curl = connection.getConnection(userCredentials, emailSource);
    CURLcode res;
    size_t count = 0;
    if (curl)
    {
        std::string command = "STATUS \"" + folder + "\" (MESSAGES)";
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, command.c_str());

        std::string response;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
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
    return count;
}

size_t MailCounter::writeCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t total_size = size * nmemb;
    output->append(static_cast<char*>(contents), total_size);
    return total_size;
}