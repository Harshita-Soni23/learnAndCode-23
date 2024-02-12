#include "digitsConverter.h"

std::vector<int> DigitConverter::numberToDigits(int number)
{
    std::vector<int> digits;
    while (number != 0)
    {
        digits.push_back(number % 10);
        number /= 10;
    }
    // Add leading zeros if necessary
    while (digits.size() < 4)
        digits.push_back(0);
    return digits;
}

int DigitConverter::digitsToNumber(const std::vector<int> &digits)
{
    int number = 0;
    for (int digit : digits)
        number = number * 10 + digit;
    return number;
}
