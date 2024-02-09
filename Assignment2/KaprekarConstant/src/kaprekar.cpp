#include "kaprekar.h"
#include "KaprekarRoutinePrinter.h"
#include "constants.h"
#include "differenceCalculator.h"
#include "digitsConverter.h"
#include "digitsSorter.h"
#include <iostream>
#include <stdexcept>

Kaprekar::Kaprekar(int number) : number(number)
{
    if (number < 1000 || number > 9999)
        throw std::invalid_argument("Invalid input. Please enter a four-digit number.");
}

void Kaprekar::calculateKaprekarRoutine()
{
    std::vector<int> digits = DigitConverter::numberToDigits(number);
    int iterations = 0;
    while (true)
    {
        std::vector<int> ascendingDigits = DigitsSorter::sortDigitsAscending(digits);
        std::vector<int> descendingDigits = DigitsSorter::sortDigitsDescending(digits);

        int difference =
            DifferenceCalculator::calculateDifference(ascendingDigits, descendingDigits);
        KaprekarRoutinePrinter::printIteration(descendingDigits, ascendingDigits, difference);

        if (difference == Constants::KAPREKAR_CONST)
            break;

        number = difference;
        digits = DigitConverter::numberToDigits(number);

        if (++iterations >= Constants::MAX_ITERATIONS)
            throw std::runtime_error(
                "Maximum iterations reached without converging to Kaprekar's constant.");
    }
}
