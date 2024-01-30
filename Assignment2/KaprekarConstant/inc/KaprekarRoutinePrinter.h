#ifndef KAPREKAR_ROUTINE_PRINTER_H
#define KAPREKAR_ROUTINE_PRINTER_H

#include <iostream>
#include <vector>

class KaprekarRoutinePrinter
{
  public:
    static void printIteration(const std::vector<int> &desc, const std::vector<int> &asc, int diff);
};

#endif