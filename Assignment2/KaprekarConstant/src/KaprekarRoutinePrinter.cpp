#include "KaprekarRoutinePrinter.h"
#include "digitsConverter.h"
#include <vector>

void KaprekarRoutinePrinter::printIteration(const std::vector<int> &descendingDigits, const std::vector<int> &ascendingDigits, int difference)
{
    std::cout << DigitConverter::digitsToNumber(descendingDigits) << " - " << DigitConverter::digitsToNumber(ascendingDigits) << " = " << difference << std::endl; 
}
