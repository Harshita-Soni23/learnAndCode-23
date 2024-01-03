#ifndef EMAILVALIDATOR_H
#define EMAILVALIDATOR_H

#include <iostream>
#include <regex>

class EmailValidator {
public:
    bool isValidEmail(const std::string &email);
};

#endif