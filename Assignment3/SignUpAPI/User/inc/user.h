#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string id;
    std::string name;
    std::string email;
    std::string directoryPath;

public:
    User(const std::string& id, const std::string& name, const std::string& email);

    // Getter methods
    std::string getId() const;
    std::string getName() const;
    std::string getEmail() const;
    std::string getDirectoryPath() const;

    // Setter methods
    void setId(const std::string& newId);
    void setName(const std::string& newName);
    void setEmail(const std::string& newEmail);
    void setDirectoryPath(const std::string& newPath);
};

#endif // USER_H
