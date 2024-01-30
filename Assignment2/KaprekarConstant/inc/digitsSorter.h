#ifndef DIGIT_SORTER_H
#define DIGIT_SORTER_H
#include <vector>

class DigitsSorter
{
  public:
    static std::vector<int> sortDigitsAscending(const std::vector<int> &digits);
    static std::vector<int> sortDigitsDescending(const std::vector<int> &digits);
};

#endif
