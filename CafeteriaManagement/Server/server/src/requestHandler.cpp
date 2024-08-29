
#include "requestHandler.h"
#include "socketException.h"
#include "databaseException.h"

#define BUFFER_SIZE 4096

RequestHandler::RequestHandler(int clientSocket)
    : clientSocket(clientSocket), running(true) {}

void RequestHandler::handle() {
    try {
        while (running) {
            std::string dataReceived = receiveRequest();
            if (dataReceived.empty()) {
                continue;
            }

            std::string response = requestProcessor.processRequest(dataReceived);

            if (!sendRequest(response)) {
                throw ResponseException("Failed to send response");
            }
        }
    } catch (const SocketException& e) {
        std::cerr << "RequestHandler exception: " << e.what() << std::endl;
    }

    close(clientSocket);
}

bool RequestHandler::sendRequest(const std::string& response) {
    std::vector<unsigned char> responseBuffer(response.begin(), response.end());

    int valsend = send(clientSocket, responseBuffer.data(), responseBuffer.size(), 0);
    if (valsend < 0) {
        throw ResponseException("Send failed with error code: " + std::string(strerror(errno)));
    }
    std::cout << "Number of bytes sent: " << valsend << "\n";
    return true;
}

std::string RequestHandler::receiveRequest() {
    char buffer[BUFFER_SIZE] = {0};

    int valread = read(clientSocket, buffer, BUFFER_SIZE);
    if (valread < 0) {
        throw RequestException("Read failed with error code: " + std::string(strerror(errno)));
    }
    if (valread > 0) {
        std::cout << "Number of bytes read: " << valread << "\n";
    }
    return std::string(buffer, valread);
}
