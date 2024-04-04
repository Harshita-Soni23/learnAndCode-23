#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include "user.h"

class UserRepository {
public:
    virtual void createUser(const User& user) = 0;
    virtual bool userExists(const User& user) = 0;
    virtual ~UserRepository() {}
};

#endif
