#include <iostream>
#include "signUpService.h"
#include "ConsoleUserInput.h"

int main() {

    std::string userName, userEmail;

    SignUpService signUpService;
    UserInput *userInput;
    ConsoleUserInput consoleUserInput;

    userInput = &consoleUserInput;

    userInput->getUserInput(userName, userEmail);
    signUpService.signup(userName, userEmail);
    return 0;
}
