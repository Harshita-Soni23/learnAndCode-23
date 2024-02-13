#include "entityInput.h"
#include "emailInfo.h"
#include "emailCarbonFootPrint.h"
#include "carbonFootPrintCalculator.h"
#include <vector>
#include <memory>
#include <iostream>

int main() {
    EntityInput input = getInput();

    CarbonFootprintCalculator carbonFootprintCalculator;
    carbonFootprintCalculator.getCarbonFootPrint(input);

    return 0;
}
