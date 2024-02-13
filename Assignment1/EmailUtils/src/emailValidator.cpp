#include<emailValidator.h>

bool EmailValidator::isValidEmail(const std::string& email) {

    std::regex emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4})");
    bool isValidEmail;

    if (!std::regex_match(email, emailRegex)) {
        isValidEmail = false; 
    }

    size_t atPosition = email.find('@');
    std::string domain = email.substr(atPosition + 1);

    if (domain.find("gmail.com") != std::string::npos ||
        domain.find("yahoo.com") != std::string::npos ||
        domain.find("outlook.com") != std::string::npos) {
        isValidEmail = true;
    }

    return isValidEmail;
}