#include "entityInput.h"
#include <iostream>

EntityInput getInput() {
    EntityInput input;

    std::cout << "Please enter the entityType entityType i.e ['email','server','something']: ";
    std::cin >> input.entityType;
    std::cout << "Please enter the entity: ";
    std::cin >> input.entity;
    std::cout << "Please enter password: ";
    std::cin >> input.password;

    return input;
}
