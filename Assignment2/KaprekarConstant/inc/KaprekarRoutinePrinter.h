#ifndef KAPREKAR_ROUTINE_PRINTER_H
#define KAPREKAR_ROUTINE_PRINTER_H

#include <iostream>
#include <vector>

class KaprekarRoutinePrinter
{
  public:
    static void printIteration(const std::vector<int> &descendingDigits, const std::vector<int> &ascendingDigits, int difference);
};

#endif
