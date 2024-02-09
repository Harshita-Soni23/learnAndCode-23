#include <iostream>
#include <stdexcept>
#include <limits>
#include "userInputHandler.h"

int UserInputHandler::getUserInput() 
{
    int userInput;
    std::cout << "Enter a four-digit number: ";
    std::cin >> userInput;
    if (std::cin.fail() || userInput < 1000 || userInput > 9999) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument("Invalid input. Please enter a four-digit number.");
    }
    return userInput;
}
