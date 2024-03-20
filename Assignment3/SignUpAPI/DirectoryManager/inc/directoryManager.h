#ifndef DIRECTORYMANAGER_H
#define DIRECTORYMANAGER_H

#include "user.h"
#include <filesystem>
#include <fstream>
#include <string>
#include <iostream>

class DirectoryManager {
public:
    void createUserDirectory(User& user);
};

#endif // DIRECTORYMANAGER_H
