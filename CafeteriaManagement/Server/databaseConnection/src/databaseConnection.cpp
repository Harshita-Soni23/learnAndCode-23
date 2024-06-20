#include "databaseConnection.h"

DatabaseConnection* DatabaseConnection::instance = nullptr;

DatabaseConnection::DatabaseConnection()
    : host("localhost"), user("harshita"), password("harshita_MySq1"), database("testdatabase") {
    connection = mysql_init(nullptr);
    if (connection == nullptr) {
        throw std::runtime_error("MySQL initialization failed");
    }
    connection = mysql_real_connect(connection, host, user, password, database, 0, nullptr, 0);
    if (connection == nullptr) {
        throw std::runtime_error("MySQL connection failed: " + std::string(mysql_error(connection)));
    }
}

DatabaseConnection* DatabaseConnection::getInstance() {
    if (instance == nullptr) {
        instance = new DatabaseConnection();
    }
    return instance;
}

MYSQL* DatabaseConnection::getConnection() {
    return connection;
}

DatabaseConnection::~DatabaseConnection() {
    if (connection != nullptr) {
        mysql_close(connection);
    }
}
