#ifndef DATAPOPULATOR_H
#define DATAPOPULATOR_H

#include "user.h"

class DataPopulator {
public:
    virtual void populateDefaultData(User *user);
};

#endif // DATAPOPULATOR_H
