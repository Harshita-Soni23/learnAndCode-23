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
        if (emailValidator.isValidEmail(entity))
        {
            try
            {
                auto emailCount = emailsCounter.getEmailsCount(entity, password);
                carbonFootprint = std::make_shared<EmailCarbonFootPrint>(entity, emailCount);
                auto totalCarbonFootPrint = carbonFootprint->calculateCarbonFootPrint();
                std::shared_ptr<EmailCarbonFootPrint> emailCarbonFootPrint = std::dynamic_pointer_cast<EmailCarbonFootPrint>(carbonFootprint);
                auto emailSource = emailSourceRetriever.getEmailSource(entity);
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
