#pragma once

#include "connection.h"
#include "requestHandler.h"
#include "IUser.h"

class ClientHandler {
public:
    ClientHandler(Connection &connection);
    void handleRequest();

private:
    Connection& connection;
    RequestHandler* requestHandler;
    User *user;

    void handleUserLogin();
};
