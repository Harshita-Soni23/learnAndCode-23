#pragma once

#include "connection.h"
#include "requestHandler.h"
#include "IUser.h"
#include "clientFactory.h"
#include "login.h"
#include "socketException.h"

class ClientHandler {
public:
    ClientHandler(Connection &connection);
    void handleRequest();

private:
    Connection& connection;
    RequestHandler* requestHandler;
    int userIdLoggedIn;
    std::unique_ptr<IUser> user;

    void handleUserLogin();
    void sendLoginCredentials();

};
