#ifndef USERINPUT_H
#define USERINPUT_H

#include <string>

class UserInput {
public:
    virtual void getUserInput(std::string& name, std::string& email, std::string& userType) = 0;
};

#endif
