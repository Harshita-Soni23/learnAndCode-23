#ifndef DIGIT_CONVERTER_H
#define DIGIT_CONVERTER_H

#include <vector>

class DigitConverter
{
  public:
    static std::vector<int> numberToDigits(int number);
    static int digitsToNumber(const std::vector<int> &digits);
};

#endif
