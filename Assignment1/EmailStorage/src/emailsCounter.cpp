#include<emailsCounter.h>

EmailsCount EmailsCounter::getEmailsCount(const std::string &entity, const std::string &password)
{
    MailCredentials userCredentials(entity, password);
    auto emailSource = emailSourceRetriever.getEmailSource(entity);
    CURLcode result = connection.getConnection(userCredentials, emailSource);

    EmailsCount emailsCount;

    if (result == CURLE_OK) {
        std::cout << "Connection successful!" << std::endl;

        result = mailCounter.getMailCount(userCredentials, "INBOX", emailsCount.inbox);
        if (result != CURLE_OK) {
            std::cerr << "Failed to get inbox mail count. Error: " << curl_easy_strerror(result) << std::endl;
        }

        result = mailCounter.getMailCount(userCredentials, "[Gmail]/Sent Mail", emailsCount.sent);
        if (result != CURLE_OK) {
            std::cerr << "Failed to get Sent Mail count. Error: " << curl_easy_strerror(result) << std::endl;
        }

        result = mailCounter.getMailCount(userCredentials, "[Gmail]/Spam", emailsCount.spam);
        if (result != CURLE_OK) {
            std::cerr << "Failed to get Spam count. Error: " << curl_easy_strerror(result) << std::endl;
        }
    } else {
        std::cerr << "Connection failed with error: " << curl_easy_strerror(result) << std::endl;
    }

    return emailsCount;
}

