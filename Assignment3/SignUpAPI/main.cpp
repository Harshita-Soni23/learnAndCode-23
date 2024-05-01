#include <iostream>
#include "signUpService.h"
#include "ConsoleUserInput.h"
#include "adminuser.h"
#include "normalUser.h"
#include "viewerUser.h"

int main() {

    std::string userName, userEmail, userType;
    std::string newUserName, newUserEmail, newUserType;
    int inputChoice, userChoice;
    SignUpService signUpService;
    ConsoleUserInput consoleUserInput;
    UserInput *userInput = &consoleUserInput;;
    User *user;

    std::cout<<"////////// Welcome to Sign Up Page ////////// ";

    std::cout<<"Which User you are- Give your username, email and userType"<<std::endl;
    userInput->getUserInput(userName, userEmail, userType);

    if (userType == "admin")
    {
        AdminUser admin(userName, userEmail, userType);
        user = &admin;
        std::cout<<"Enter choice to take input- \n Press 1 to take Input from Console. "<<std::endl;
        std::cin>>inputChoice;
        std::cin.ignore();
        if (inputChoice == 1)
        {
            userInput = &consoleUserInput;
        }
        else
        {
            userInput = nullptr;
        }

        if (userInput)
        {
            userInput->getUserInput(newUserName, newUserEmail, newUserType);
            admin.addUser(newUserName, newUserEmail, newUserType);
        }
    }
    else if(userType == "viewer")
    {

    }
    else if(userType == "normal")
    {

    }
    else
    {
        std::cout<<"We don't have permissions for" << userType << "User" <<std::endl;
    }

    return 0;
}
