// EmailStatus.cpp
#include "EmailStatus.h"

size_t EmailStatus::parseMessageCount(const std::string& response) {
    // Assuming the provided code for parsing the message count is as follows:
    // (This part should match your original code for parsing the response)

    size_t pos = response.find("MESSAGES");
    if (pos != std::string::npos) {
        try {
            return std::stoul(response.substr(pos + 9));
        } catch (...) {
            // Handle the exception (e.g., log an error)
            // Return a default value or rethrow the exception if appropriate
        }
    }

    // Default value in case parsing fails
    return 0;
}
