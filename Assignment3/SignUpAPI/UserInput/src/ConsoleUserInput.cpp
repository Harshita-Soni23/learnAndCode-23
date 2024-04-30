#include <iostream>
#include "ConsoleUserInput.h"

void ConsoleUserInput::getUserInput(std::string& name, std::string& email, std::string& userType) {
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    std::cout << "Enter your email: ";
    std::getline(std::cin, email);
    std::cout << "Enter user Type: ";
    std::getline(std::cin, userType);
}

