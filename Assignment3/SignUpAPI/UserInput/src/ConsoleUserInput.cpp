#include <iostream>
#include "ConsoleUserInput.h"

void ConsoleUserInput::getUserInput(std::string& name, std::string& email) {
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    std::cout << "Enter your email: ";
    std::getline(std::cin, email);
}
