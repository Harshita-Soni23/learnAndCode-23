#include "digitsOperator.h"
#include "digitsConverter.h"

int DigitsOperator::calculateDifference(
    const std::vector<int> &ascendingDigits, const std::vector<int> &descendingDigits)
{
    int smallerNumber = DigitConverter::digitsToNumber(ascendingDigits);
    int largerNumber = DigitConverter::digitsToNumber(descendingDigits);
    return largerNumber - smallerNumber;
}
