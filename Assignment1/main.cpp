#include "emailInfo.h"
#include "emailCarbonFootPrint.h"
#include "carbonFootPrintCalculator.h"
#include <vector>
#include <memory>
#include <iostream>

int main() {
    std::string entityType;
    std::string entity;
    std::string password;
    
    std::cout<<"Please enter the entityType entityType i.e ['email','server','something']: ";
    std::cin>>entityType;
    std::cout<<"Please enter the entity: ";
    std::cin>>entity;
    std::cout<<"Please enter password: ";
    std::cin>>password;

    CarbonFootprintCalculator carbonFootprintCalculator;
    carbonFootprintCalculator.getCarbonFootPrint(entityType, entity, password);

    return 0;
}
