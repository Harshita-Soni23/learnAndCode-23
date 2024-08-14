#pragma once

#include <string>
#include <sstream>

struct DataSerializer {
    virtual std::string serialize() const = 0;
    virtual void deserialize(const std::string &data) = 0;
};
