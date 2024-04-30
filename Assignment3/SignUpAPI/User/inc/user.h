#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string id;
    std::string name;
    std::string email;
    std::string directoryPath;
    std::string gender;
    std::string userType;

public:
    User(const std::string& name, const std::string& email, const std::string& userType = "viewer");

    // Getter methods
    std::string getId() const;
    std::string getName() const;
    std::string getEmail() const;
    std::string getDirectoryPath() const;
    std::string getGender() const;
    std::string getUserType() const;

    // Setter methods
    void setId(const std::string& newId);
    void setName(const std::string& newName);
    void setEmail(const std::string& newEmail);
    void setDirectoryPath(const std::string& newPath);
    void setGender(const std::string& gender);
    void setUserType(const std::string& userType);

    // Virtual method for viewing data
    virtual void viewData() const;
};

#endif // USER_H
