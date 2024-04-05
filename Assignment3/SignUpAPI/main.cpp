#include <iostream>
#include "signUpService.h"
#include "ConsoleUserInput.h"

int main() {

    std::string userName, userEmail;
    int inputChoice, userChoice;
    SignUpService signUpService;
    UserInput *userInput;
    ConsoleUserInput consoleUserInput;

    std::cout<<"////////// Welcome to Sign Up Page ////////// ";

    std::cout<<"Which User you are- \nPress 1 for Admin \nPress 2 for normal User \nPress 3 for viewer "<<std::endl;
    std::cin>>userChoice;

    if (userChoice == 1)
    {
        std::cout<<"Enter choice to take input- \n Press 1 to take Input from Console "<<std::endl;
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
            userInput->getUserInput(userName, userEmail);
            signUpService.signup(userName, userEmail);
        }
    }

    return 0;
}
