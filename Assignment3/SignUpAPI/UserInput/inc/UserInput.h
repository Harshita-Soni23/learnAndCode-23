#ifndef USERINPUT_H
#define USERINPUT_H

#include <string>

class UserInput {
public:
    virtual void getUserInput(std::string& name, std::string& email) = 0;
};

#endif
