#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "connection.h"

TEST(ConnectionTest, ConnectToServerSuccess) {
    Connection connection(8080);
    
    // Assuming the server is running locally, this should connect
    EXPECT_NO_THROW(connection.connectToServer());
}

TEST(ConnectionTest, ConnectToServerFailure) {
    Connection connection(12345); // Assuming no server on this port
    
    // Expect a ConnectionException due to no server on port 12345
    EXPECT_THROW(connection.connectToServer(), ConnectionException);
}

TEST(ConnectionTest, DisconnectSuccess) {
    Connection connection(8080);
    connection.connectToServer();
    
    EXPECT_NO_THROW(connection.disconnect());
    EXPECT_EQ(connection.getSocket(), -1);
}

TEST(ConnectionTest, GetSocketAndAddress) {
    Connection connection(8080);
    
    EXPECT_GE(connection.getSocket(), 0);
    EXPECT_EQ(connection.getAddress().sin_port, htons(8080));
}
