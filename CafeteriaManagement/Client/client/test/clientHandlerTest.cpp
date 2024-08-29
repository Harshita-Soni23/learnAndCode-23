#include <gtest/gtest.h>
#include "clientHandler.h"
#include "requestHandler.h"
#include "connection.h"
#include "clientFactory.h"
#include "login.h"
#include "clientOperationType.h"
#include <iostream>

class ClientHandlerTest : public ::testing::Test {
protected:
    Connection* connection;
    RequestHandler* requestHandler;
    ClientHandler* clientHandler;

    void SetUp() override {
        connection = new Connection(8083);
        connection->connectToServer();

        requestHandler = new RequestHandler(connection->getSocket(), connection->getAddress());
        clientHandler = new ClientHandler(*connection);
    }

    void TearDown() override {
        delete requestHandler;
        delete connection;
        delete clientHandler;
    }
};

TEST_F(ClientHandlerTest, HandleRequest_SuccessfulLogin) {
    
}
