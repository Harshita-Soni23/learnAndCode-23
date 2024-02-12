#include "emailSourceRetriever.h"

std::string EmailSourceRetriever::getEmailSource(const std::string &emailId) const
{
    std::string provider;
    size_t atPosition = emailId.find('@');
    if (atPosition != std::string::npos)
    {
        std::string domain = emailId.substr(atPosition + 1);
        size_t dotPosition = domain.find('.');
        if (dotPosition != std::string::npos)
        {
            provider = domain.substr(0, dotPosition);
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