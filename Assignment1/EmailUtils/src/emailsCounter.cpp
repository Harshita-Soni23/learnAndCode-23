#include<emailsCounter.h>

EmailsCount EmailsCounter::getEmailsCount(const std::string &entity, const std::string &password)
{
    UserCredentials userCredentials(entity, password);
    auto emailSource = emailSourceRetriever.getEmailSource(entity);
    auto result = connection.getConnection(userCredentials, emailSource);
    EmailsCount emailsCount;

    if (result) {
        std::cout << "Connection successful!" << std::endl;
        emailsCount.inbox = mailCounter.getMailCount(userCredentials, "INBOX");
        emailsCount.sent = mailCounter.getMailCount(userCredentials, "[Gmail]/Sent Mail");
        emailsCount.spam = mailCounter.getMailCount(userCredentials, "[Gmail]/Spam");
    } else {
        std::cerr << "Connection failed " << std::endl;
    }
    return emailsCount;
}

