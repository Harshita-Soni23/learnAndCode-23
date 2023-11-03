#ifndef CARBONFOOTPRINT_H
#define CARBONFOOTPRINT_H

#include <iostream>

class CarbonFootPrint {
public:
    virtual EmailsCarbonFootPrint calculateCarbonFootPrint(const std::string& emailId) = 0;
};

#endif // CARBONFOOTPRINT_H