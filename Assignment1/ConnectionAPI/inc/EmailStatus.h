// EmailStatus.h
#pragma once

#include <string>

class EmailStatus {
public:
    static size_t parseMessageCount(const std::string& response);
};
