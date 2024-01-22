#include "emailSourceRetriever.h"

std::string EmailSourceRetriever::getEmailSource(const std::string &emailId) const
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