#include <iostream>
#include "emailInfo.h"
#include "emailCarbonFootPrint.h"
#include <regex>
#include <string>
#include "carbonFootPrintCalculator.h"

void CarbonFootprintCalculator::getCarbonFootPrint(const EntityInput& input)
{
    std::shared_ptr<CarbonFootPrint> carbonFootprint;

    if (input.entityType == "email")
    {
        if (emailValidator.isValidEmail(input.entity))
        {
            try
            {
                auto emailCount = emailsCounter.getEmailsCount(input.entity, input.password);
                carbonFootprint = std::make_shared<EmailCarbonFootPrint>(input.entity, emailCount);
                auto totalCarbonFootPrint = carbonFootprint->calculateCarbonFootPrint();
                std::shared_ptr<EmailCarbonFootPrint> emailCarbonFootPrint = std::dynamic_pointer_cast<EmailCarbonFootPrint>(carbonFootprint);
                auto emailSource = emailSourceRetriever.getEmailSource(input.entity);
                emailCarbonFootPrint->displayCarbonFootPrint(input.entity, emailSource, totalCarbonFootPrint);
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
