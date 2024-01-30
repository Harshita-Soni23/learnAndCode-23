#include "kaprekar.h"
#include <iostream>

int main()
{
    try
    {
        int inputNumber;
        std::cout << "Enter a four-digit number: ";
        std::cin >> inputNumber;
        Kaprekar kap(inputNumber);
        kap.calculateKaprekarRoutine();
        std::cout << "Kaprekar's constant reached " << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
