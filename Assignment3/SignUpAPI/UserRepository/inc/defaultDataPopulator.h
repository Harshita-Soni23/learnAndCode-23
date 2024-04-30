#ifndef DEFAULTDATAPOPULATOR_H
#define DEFAULTDATAPOPULATOR_H

#include "dataPopulator.h"

class DefaultDataPopulator : public DataPopulator
{
public:
    void populateDefaultData(User *user) override;

private:
    std::string filename = "users.txt";
};

#endif // DEFAULTDATAPOPULATOR_H
