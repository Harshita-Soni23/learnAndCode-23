#include <iostream>
#include "emailInfo.h"
#include "emailCarbonFootPrint.h"
#include <regex>
#include <string>
#include "carbonFootPrintCalculator.h"

void CarbonFootprintCalculator::getCarbonFootPrint(const std::string &entityType, const std::string &entity)
{
    std::shared_ptr<CarbonFootPrint> carbonFootprint;

    if (entityType == "email")
    {
        if (isValidEmail(entity))
        {
            try
            {
                auto emailInfo = getEmailInfo();
                carbonFootprint = std::make_shared<EmailCarbonFootPrint>(emailInfo);
                auto totalCarbonFootPrint = carbonFootprint->calculateCarbonFootPrint(entity);
                std::shared_ptr<EmailCarbonFootPrint> cf = std::dynamic_pointer_cast<EmailCarbonFootPrint>(carbonFootprint);
                cf->displayCarbonFootPrint(entity, totalCarbonFootPrint);
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

std::vector<EmailInfo> CarbonFootprintCalculator::getEmailInfo()
{
    std::vector<EmailInfo> emailInfo = {
        {"abc@gmail.com", "gmail", 100.0, 50.0, 10.0},
        {"axe@gmail.com", "gmail", 150.0, 75.0, 5.0},
        {"fox@outlook.com", "outlook", 120.0, 60.0, 15.0},
    };
    return emailInfo;
}