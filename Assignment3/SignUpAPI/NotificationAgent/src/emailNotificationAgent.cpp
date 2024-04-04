#include "emailNotificationAgent.h"
#include <iostream>
#include <curl/curl.h>

void EmailNotificationAgent::notifySuccess(const User& user) {
    sendEmail(user.getEmail(), "Sign-up successful", "Dear " + user.getName() + ",\n\nYour sign-up was successful.");
}

void EmailNotificationAgent::notifyError(const User& user, const std::string& errorMessage) {
    sendEmail("admin@example.com", "Sign-up error", "Error occurred during sign-up: " + errorMessage);
}

void EmailNotificationAgent::sendEmail(const std::string& to, const std::string& subject, const std::string& body) {
    curl_global_init(CURL_GLOBAL_ALL);
    CURL* curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "smtp://smtp.gmail.com:587");
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, "harshitasoni469@gmail.com");
        struct curl_slist* recipients = nullptr;
        recipients = curl_slist_append(recipients, to.c_str());
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

        struct curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, "Content-Type: text/plain; charset=\"UTF-8\"");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        curl_easy_setopt(curl, CURLOPT_READDATA, nullptr);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, nullptr);
        curl_easy_setopt(curl, CURLOPT_READDATA, nullptr);
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, nullptr);
        curl_easy_setopt(curl, CURLOPT_READDATA, nullptr);

        std::string emailContent = "Subject: " + subject + "\n\n" + body;
        curl_easy_setopt(curl, CURLOPT_READDATA, emailContent.c_str());
        curl_easy_setopt(curl, CURLOPT_INFILESIZE_LARGE, (curl_off_t)emailContent.length());

        curl_easy_perform(curl);

        curl_easy_cleanup(curl);
        curl_slist_free_all(recipients);
        curl_slist_free_all(headers);
    }
    curl_global_cleanup();
}
