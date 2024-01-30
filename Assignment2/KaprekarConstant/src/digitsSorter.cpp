#include "digitsSorter.h"
#include <algorithm>

std::vector<int> DigitsSorter::sortDigitsAscending(const std::vector<int> &digits)
{
    std::vector<int> sortedDigits = digits;
    std::sort(sortedDigits.begin(), sortedDigits.end());
    return sortedDigits;
}

std::vector<int> DigitsSorter::sortDigitsDescending(const std::vector<int> &digits)
{
    std::vector<int> sortedDigits = digits;
    std::sort(sortedDigits.begin(), sortedDigits.end(), std::greater<int>());
    return sortedDigits;
}
