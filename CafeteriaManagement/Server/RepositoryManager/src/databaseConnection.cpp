#include "databaseConnection.h"
#include <cppconn/connection.h>
#include <memory>
#include <mysql_driver.h>
#include <stdexcept>

// Definition of static members
std::shared_ptr<DatabaseConnection> DatabaseConnection::instance = nullptr;
std::shared_ptr<sql::Connection> DatabaseConnection::connection = nullptr;

DatabaseConnection::DatabaseConnection() {}

std::shared_ptr<sql::Connection> DatabaseConnection::getConnection() {
    if (connection != nullptr) {
        return connection;
    }
    throw std::runtime_error(
        "Connection is not initialized. Need to call initDbConnection first");
}

void DatabaseConnection::initDbConnection(const std::string &hostName,
                                          const std::string &userName,
                                          const std::string &password,
                                          const std::string &schemaName) {
    sql::mysql::MySQL_Driver *driver;
    driver = sql::mysql::get_mysql_driver_instance();
    connection = std::shared_ptr<sql::Connection>(
        driver->connect(hostName, userName, password));
    connection->setSchema(schemaName);
}

std::shared_ptr<DatabaseConnection> DatabaseConnection::getInstance() {
    if (instance == nullptr) {
        instance = std::shared_ptr<DatabaseConnection>(new DatabaseConnection());
    }
    return instance;
}

DatabaseConnection::~DatabaseConnection() {
    if (connection != nullptr) {
        connection->close();
    }
}
