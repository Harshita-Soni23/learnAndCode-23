#ifndef DIRECTORYMANAGER_H
#define DIRECTORYMANAGER_H

#include "user.h"

class DirectoryManager {
public:
    virtual void createUserDirectory(User *user) = 0;
};

#endif // DIRECTORYMANAGER_H
