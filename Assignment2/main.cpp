#include "kaprekar.h"
#include <iostream>
#include "userInputHandler.h"

int main()
{
    try
    {
        UserInputHandler inputHandler;
        int userInput = inputHandler.getUserInput();
        Kaprekar kaprekar(userInput);
        kaprekar.calculateKaprekarRoutine();
        std::cout << "Kaprekar's constant reached " << std::endl;
    }
    catch (const std::exception &exception)
    {
        std::cerr << "Error: " << exception.what() << std::endl;
        return 1;
    }
    return 0;
}
