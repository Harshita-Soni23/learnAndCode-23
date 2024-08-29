#include "clientHandler.h"
#include "login.h"
#include <iostream>
#include "clientOperationType.h"


ClientHandler::ClientHandler(Connection &connection)
    : connection(connection), requestHandler(nullptr) {}

void ClientHandler::handleRequest() {
    connection.connectToServer();

    requestHandler = new RequestHandler(connection.getSocket(), connection.getAddress());
    handleUserLogin();

    delete requestHandler;
    connection.disconnect();
}

void ClientHandler::handleUserLogin() {
    int wrongLoginAttemptCount = 0;
    const int maxRetries = 5;
    std::string response;
    Role userRole;

    while (wrongLoginAttemptCount < maxRetries) {
        sendLoginCredentials();
        response = requestHandler->receiveResponse();
        std::cout << "User Role response: " << response << "\n";

        try {
            userRole = static_cast<Role>(std::stoi(response));

            if (userRole == Role::Admin_ || userRole == Role::Chef_ || userRole == Role::Employee_) {
                user = clientFactory.initializeClient(userRole, requestHandler, this->userIdLoggedIn);
                user->handleUserOperations();
                return; 
            } else {
                throw std::invalid_argument("Invalid login Credentials");
            }
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << ". Please try again.\n";
        }

        wrongLoginAttemptCount++;
        if (wrongLoginAttemptCount < maxRetries) {
            std::cout << "Attempt " << wrongLoginAttemptCount + 1 << " of " << maxRetries << "\n";
        }
    }

    std::cerr << "Maximum login attempts exceeded. Exiting.\n";
    return;
}

void ClientHandler::sendLoginCredentials() {
    int userId;
    std::string password;

    std::cout << "Please Enter Login Credentials:\n";
    std::cout << "UserId: ";
    std::cin >> userId;
    std::cout << "Password: ";
    std::cin >> password;
    Login login(userId, password);
    Operation operation = Operation::LoginUser;
    auto loginData = DataSerializer::serialize(login);
    this->userIdLoggedIn = login.userId;
    auto loginSerializedRequest = DataSerializer::serializeOperation(operation, loginData);

    requestHandler->sendRequest(loginSerializedRequest);
}
