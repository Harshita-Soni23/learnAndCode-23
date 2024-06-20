#pragma once

#include "client.h"
#include "requestHandler.h"

class UserHandler {
public:
    UserHandler(Client& client);
    void handleRequest();

private:
    Client& client;
    RequestHandler* requestHandler;

    void handleUserInput();
};
