#ifndef LOCALDIRECTORYMANAGER_H
#define LOCALDIRECTORYMANAGER_H

#include "directoryManager.h"
#include <filesystem>
#include <fstream>
#include <string>
#include <iostream>

class LocalDirectoryManager : public DirectoryManager {
public:
    void createUserDirectory(User *user) override;
};

#endif // LOCALDIRECTORYMANAGER_H
