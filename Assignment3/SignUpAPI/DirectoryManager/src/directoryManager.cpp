#include "directoryManager.h"

void DirectoryManager::createUserDirectory(User& user) {
            // Construct absolute path for the parent directory
std::filesystem::path parentDirectory = std::filesystem::absolute("UserDirectories");

try {
    if (!std::filesystem::exists(parentDirectory)) {
        std::filesystem::create_directories(parentDirectory);
        std::cout << "Parent directory created: " << parentDirectory << std::endl;
    }
    
    std::filesystem::path userDirectory = parentDirectory / user.getId();

    std::filesystem::create_directory(userDirectory);
    std::cout << "User directory created: " << userDirectory << std::endl;

    // Use setter method to set directory path in the User object
    user.setDirectoryPath(userDirectory);

} catch (const std::exception& e) {
    std::cerr << "Error creating user directory: " << e.what() << std::endl;
}
}