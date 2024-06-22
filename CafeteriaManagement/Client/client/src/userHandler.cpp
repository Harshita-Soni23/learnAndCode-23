#include "userHandler.h"
#include "client.h"
#include <vector>
#include <iostream>
#include <string>
#include <limits>

UserHandler::UserHandler(Client& client)
    : client(client), requestHandler(nullptr) {}

void UserHandler::handleRequest() {
    if (!client.connectToServer()) {
        std::cerr << "Failed to connect to server" << std::endl;
        return;
    }

    requestHandler = new RequestHandler(client.getSocket(), client.getAddress());
    handleUserInput();

    delete requestHandler;
    client.disconnect();
}

void UserHandler::loginPrompt()
{
    std::string userId;
    std::string password;
    std::cout << "Enter Login Credantials: \n";
    std::cout<<"UserId : ";
    std::cin>>userId;
    std::cout<<"Password : ";
    std::cin>>password;
    int operation = Operation::login;
    std::string message = "LOGIN;" + userId+ ";" + password;
    // std::vector<std::string> loginVector;
    // loginVector.push_back("LOGIN;");
    // loginVector.push_back(userId);
    // loginVector.push_back(";");
    // loginVector.push_back(password);
    requestHandler->sendRequest(message) ;
}

void UserHandler::handleUserInput() {
    loginPrompt();
    std::string response = requestHandler->receiveResponse();
    std::cout<<response;
    if(response == "admin"){
        std::cout<<"Admin Logged In\n";
        showMenuPrompt("1");
    }else if(response == "chef"){
        std::cout<<"Chef Logged In\n";
    }else if(response== "employee"){
        std::cout<<"Employee Logged In\n";
    }else{
        std::cout<<"Invalid Login\n";
    }
}

void UserHandler::showMenuPrompt(std::string userRole)
{
    if (userRole == "1")
    {
        showAdminMenu();
    }
}
int UserHandler::showAdminMenu()
{
     std::cout << "Welcome Admin\n\n";
    bool flag = true;
    while (flag) {
        std::cout << "Select the operation which you like to perform\n"
                     "1. Add menu Item\n"
                     "2. Delete Menu Item\n"
                     "3. View Menu\n"
                     "4. Add User\n"
                     "5. Exit\n"
                     "Enter your choice: " << std::endl;

        int adminChoice;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        while (!(std::cin >> adminChoice)) {
            std::cin.clear();  // clear the error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // discard invalid input
            std::cout << "Invalid input. Please enter a number between 1 and 5: " << std::endl;
        }

        switch (adminChoice) {
            case 1:
                showAddItemPrompt();
                break;
            // case 2:
            //     showDeleteItemPrompt();
            //     break;
            // case 3:
            //     showMenu();
            //     break;
            // case 4:
            //     addUserPrompt();
            //     break;
            case 5:
                client.disconnect();
                flag = false;
                break;
            default:
                std::cout << "Invalid Choice" << std::endl;
                break;
        }
    }
    return 0;
}

// void UserHandler::addUserPrompt() {
//     std::vector<std::string> userResponse;
//     userResponse.push_back(std::to_string(Operation::AddUser));
    
//     std::string userName, userRole, userPassword;

//     std::cout << "Enter User name: " << std::endl;
//     std::getline(std::cin >> std::ws, userName);
//     userResponse.push_back(userName);

//     std::cout << "Enter User password: " << std::endl;
//     std::getline(std::cin >> std::ws, userPassword);
//     userResponse.push_back(userPassword);

//      std::cout << "Enter User role: " << std::endl;
//     std::getline(std::cin >> std::ws, userRole);
//     userResponse.push_back(userRole);


//     std::cout << "Sending addUser request to server\n";
//     requestHandler->sendRequest(userResponse);
// }

void UserHandler::showAddItemPrompt() {
    // std::vector<std::string> userResponse;
    // userResponse.push_back(std::to_string(Operation::AddMenuItem));
    
    std::string itemName, itemPrice, itemAvailability, mealType;

    std::cout << "Enter Item name: " << std::endl;
    std::getline(std::cin >> std::ws, itemName);
    //userResponse.push_back(itemName);

    std::cout << "Enter Item price: " << std::endl;
    std::getline(std::cin >> std::ws, itemPrice);
    //userResponse.push_back(itemPrice);

    std::cout << "Enter Item availability: " << std::endl;
    std::getline(std::cin >> std::ws, itemAvailability);
    //userResponse.push_back(itemAvailability);

    std::cout << "Enter meal type (breakfast/lunch/dinner): " << std::endl;
    std::getline(std::cin >> std::ws, mealType);
    //userResponse.push_back(mealType);

    std::string menuData = "admin_addMenuItem;" + itemName + ";" + itemPrice + ";" + itemAvailability + ";" + mealType;

    std::cout << "Sending addItem request to server\n";
    requestHandler->sendRequest(menuData);
    std::string response = requestHandler->receiveResponse();
}


// void UserHandler::showDeleteItemPrompt() {
//     std::string itemName;
//     std::vector<std::string> userResponse{std::to_string(Operation::DeleteMenuItem)};

//     std::cout << "Enter the name of item to delete: " << std::endl;
//     std::getline(std::cin >> std::ws, itemName);
//     userResponse.push_back(itemName);

//     requestHandler->sendRequest(userResponse);
// }


// void UserHandler::showMenu() {
//     std::vector<std::string> userResponse{std::to_string(Operation::ViewMenu)};
//     requestHandler->sendRequest(userResponse);

//     VectorSerializer vectorSerializer;
//     std::vector<std::string> menu = requestHandler->receiveResponse();

//     for (const auto& item : menu) {
//         auto menuItemData = vectorSerializer.deserialize(item);
//         for (const auto& field : menuItemData) {
//             std::cout << field << " , ";
//         }
//         std::cout << std::endl;
//     }
// }
