#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "clientFactory.h"
#include "requestHandler.h"
#include "connection.h"
#include "admin.h"
#include "chef.h"
#include "employee.h"

class ClientFactoryTest : public ::testing::Test {
protected:
    int portNumber;
    Connection* connection;
    RequestHandler* requestHandler;
    ClientFactory factory;

    void SetUp() override {
        portNumber = 8083;
        connection = new Connection(portNumber);
        connection->connectToServer();
        requestHandler = new RequestHandler(connection->getSocket(), connection->getAddress());
    }

    void TearDown() override {
        delete requestHandler;
        delete connection;
    }
};

TEST_F(ClientFactoryTest, when_InitializeAdmin_then_ReturnsAdminInstance) {
    IUser* user = factory.initializeClient(Role::Admin_, requestHandler, 1);
    EXPECT_NE(dynamic_cast<Admin*>(user), nullptr);
    delete user;
}

TEST_F(ClientFactoryTest, when_InitializeEmployee_then_ReturnsEmployeeInstance) {
    IUser* user = factory.initializeClient(Role::Employee_, requestHandler, 1);
    EXPECT_NE(dynamic_cast<Employee*>(user), nullptr);
    delete user;
}

TEST_F(ClientFactoryTest, when_InitializeChef_then_ReturnsChefInstance) {
    IUser* user = factory.initializeClient(Role::Chef_, requestHandler, 1);
    EXPECT_NE(dynamic_cast<Chef*>(user), nullptr);
    delete user;
}

TEST_F(ClientFactoryTest, when_InitializeUnknownRole_then_ThrowsInvalidArgument) {
    EXPECT_THROW(factory.initializeClient(static_cast<Role>(-1), requestHandler, 4), std::invalid_argument);
}
