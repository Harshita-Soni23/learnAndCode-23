#ifndef ENTITY_INPUT_H
#define ENTITY_INPUT_H

#include <string>

struct EntityInput {
    std::string entityType;
    std::string entity;
    std::string password;
};

EntityInput getInput();

#endif
