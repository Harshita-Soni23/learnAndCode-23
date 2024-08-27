#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../inc/requestHandler.h"
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <cstring>

// Mock functions for system calls
class MockRequestHandler : public RequestHandler {
public:
    MockRequestHandler(int clientSocket, struct sockaddr_in serv_addr)
        : RequestHandler(clientSocket, serv_addr) {}

    MOCK_METHOD(ssize_t, send, (int sockfd, const void* buf, size_t len, int flags), (const));
    MOCK_METHOD(ssize_t, read, (int sockfd, void* buf, size_t count), (const));
};

TEST(RequestHandlerTest, SendRequestSuccess) {
    struct sockaddr_in serv_addr;
    MockRequestHandler handler(1, serv_addr);

    EXPECT_CALL(handler, send(::testing::_, ::testing::_, ::testing::_, ::testing::_))
        .WillOnce(::testing::Return(1024)); // Simulate successful send

    EXPECT_NO_THROW(handler.sendRequest("Test request"));
}

TEST(RequestHandlerTest, SendRequestFailure) {
    struct sockaddr_in serv_addr;
    MockRequestHandler handler(1, serv_addr);

    EXPECT_CALL(handler, send(::testing::_, ::testing::_, ::testing::_, ::testing::_))
        .WillOnce(::testing::Return(-1)); // Simulate failure in send

    EXPECT_THROW(handler.sendRequest("Test request"), RequestException);
}

TEST(RequestHandlerTest, ReceiveResponseSuccess) {
    struct sockaddr_in serv_addr;
    MockRequestHandler handler(1, serv_addr);

    const char* mockResponse = "Test response";
    EXPECT_CALL(handler, read(::testing::_, ::testing::_, ::testing::_))
        .WillOnce(::testing::Invoke([&](int, void* buf, size_t) {
            std::memcpy(buf, mockResponse, std::strlen(mockResponse));
            return std::strlen(mockResponse); // Simulate successful read
        }));

    EXPECT_EQ(handler.receiveResponse(), "Test response");
}

TEST(RequestHandlerTest, ReceiveResponseFailure) {
    struct sockaddr_in serv_addr;
    MockRequestHandler handler(1, serv_addr);

    EXPECT_CALL(handler, read(::testing::_, ::testing::_, ::testing::_))
        .WillOnce(::testing::Return(-1)); // Simulate failure in read

    EXPECT_THROW(handler.receiveResponse(), ResponseException);
}
