#pragma once

#include "connection.h"
#include "requestHandler.h"
#include "IUser.h"
#include "clientFactory.h"
#include "login.h"
#include "socketException.h"
#include "admin.h"
#include "chef.h"
#include "employee.h"

class ClientHandler {
public:
    ClientHandler(Connection &connection);
    void handleRequest();

private:
    Connection& connection;
    RequestHandler* requestHandler;
    int userIdLoggedIn;
    IUser* user;
    ClientFactory clientFactory;

    void handleUserLogin();
    void sendLoginCredentials();

};
