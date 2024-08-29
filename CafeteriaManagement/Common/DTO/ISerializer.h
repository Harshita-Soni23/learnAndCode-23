#pragma once

#include <string>
#include <sstream>

class ISerializer {
    virtual std::string serialize() const = 0;
    virtual void deserialize(const std::string &serializedData) = 0;
};
