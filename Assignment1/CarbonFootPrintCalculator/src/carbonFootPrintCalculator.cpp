#include <iostream>
#include "emailInfo.h"
#include "emailCarbonFootPrint.h"
#include <regex>
#include <string>
#include "carbonFootPrintCalculator.h"

void CarbonFootprintCalculator::getCarbonFootPrint(const std::string &entityType, const std::string &entity, const std::string &password)
{
    std::shared_ptr<CarbonFootPrint> carbonFootprint;

    if (entityType == "email")
    {
        if (isValidEmail(entity))
        {
            try
            {
                auto emailCount = getEmailsCount(entity, password);
                carbonFootprint = std::make_shared<EmailCarbonFootPrint>(entity, emailCount);
                auto totalCarbonFootPrint = carbonFootprint->calculateCarbonFootPrint();
                std::shared_ptr<EmailCarbonFootPrint> emailCarbonFootPrint = std::dynamic_pointer_cast<EmailCarbonFootPrint>(carbonFootprint);
                auto emailSource = getEmailSource(entity);
                emailCarbonFootPrint->displayCarbonFootPrint(entity, emailSource, totalCarbonFootPrint);
            }
            catch (const std::exception &e)
            {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
        else
        {
            std::cout<<"Invalid email"<<std::endl;
        }
    }
    else
    {
        std::cout<<"Implementation not done for this entity Type"<<std::endl;
    }
}

bool CarbonFootprintCalculator::isValidEmail(const std::string& email) {

    std::regex emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4})");

    if (!std::regex_match(email, emailRegex)) {
        return false; 
    }

    size_t atPos = email.find('@');
    std::string domain = email.substr(atPos + 1);

    if (domain.find("gmail.com") != std::string::npos ||
        domain.find("yahoo.com") != std::string::npos ||
        domain.find("outlook.com") != std::string::npos) {
        return true;
    }

    return false; 
}

EmailsCount CarbonFootprintCalculator::getEmailsCount(const std::string &entity, const std::string &password)
{
    MailCredentials userCredentials(entity, password);
    auto emailSource = getEmailSource(entity);
    CURLcode result = ConnectionAPI::getConnection(userCredentials, emailSource);

    EmailsCount emailsCount;

    if (result == CURLE_OK) {
        std::cout << "Connection successful!" << std::endl;

        result = ConnectionAPI::getMailCount(userCredentials, "INBOX", emailsCount.inbox);
        if (result != CURLE_OK) {
            std::cerr << "Failed to get inbox mail count. Error: " << curl_easy_strerror(result) << std::endl;
        }

        result = ConnectionAPI::getMailCount(userCredentials, "[Gmail]/Sent Mail", emailsCount.sent);
        if (result != CURLE_OK) {
            std::cerr << "Failed to get Sent Mail count. Error: " << curl_easy_strerror(result) << std::endl;
        }

        result = ConnectionAPI::getMailCount(userCredentials, "[Gmail]/Spam", emailsCount.spam);
        if (result != CURLE_OK) {
            std::cerr << "Failed to get Spam count. Error: " << curl_easy_strerror(result) << std::endl;
        }
    } else {
        std::cerr << "Connection failed with error: " << curl_easy_strerror(result) << std::endl;
    }

    return emailsCount;
}

std::string CarbonFootprintCalculator::getEmailSource(const std::string &emailId) const
{
    std::string provider;
    size_t atPos = emailId.find('@');
    if (atPos != std::string::npos)
    {
        std::string domain = emailId.substr(atPos + 1);
        size_t dotPos = domain.find('.');
        if (dotPos != std::string::npos)
        {
            provider = domain.substr(0, dotPos);
        }
        else
        {
            std::cerr << "Unable to determine provider: No dot in domain." << std::endl;
        }
    }
    else
    {
        std::cerr << "Unable to determine provider: No '@' in email ID." << std::endl;
    }
    return provider;
}
