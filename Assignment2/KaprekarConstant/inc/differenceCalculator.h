#ifndef KAPREKAR_DIFFERENCE_CALCULATOR_H
#define KAPREKAR_DIFFERENCE_CALCULATOR_H

#include <vector>

class DifferenceCalculator
{
  public:
    static int calculateDifference(const std::vector<int> &ascendingDigits, const std::vector<int> &descendingDigits);
};

#endif
