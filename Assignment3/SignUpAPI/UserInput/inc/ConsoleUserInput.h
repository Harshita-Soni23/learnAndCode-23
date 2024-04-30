#ifndef CONSOLEUSERINPUT_H
#define CONSOLEUSERINPUT_H

#include "UserInput.h"

class ConsoleUserInput : public UserInput {
public:
    void getUserInput(std::string& name, std::string& email, std::string& userType) override;
};

#endif 
