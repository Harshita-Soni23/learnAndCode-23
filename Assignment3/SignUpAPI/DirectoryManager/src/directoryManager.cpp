#include "directoryManager.h"

void DirectoryManager::createUserDirectory(User &user)
{
    std::filesystem::path parentDirectory = std::filesystem::absolute("UserDirectories");

    try
    {
        if (!std::filesystem::exists(parentDirectory))
        {
            std::filesystem::create_directories(parentDirectory);
            std::cout << "Parent directory created: " << parentDirectory << std::endl;
        }

        std::filesystem::path userDirectory = parentDirectory / user.getId();

        std::filesystem::create_directory(userDirectory);
        std::cout << "User directory created: " << userDirectory << std::endl;

        user.setDirectoryPath(userDirectory);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error creating user directory: " << e.what() << std::endl;
    }
}
