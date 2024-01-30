#include "kaprekar.h"
#include <iostream>

int main()
{
    try
    {
        int userInput;
        std::cout << "Enter a four-digit number: ";
        std::cin >> userInput;
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
