#ifndef USERIDGENERATOR_H
#define USERIDGENERATOR_H

#include <string>
#include <chrono>
#include <random>

class UserIdGenerator {
public:
    UserIdGenerator(); // Constructor
    std::string generateUserId();

private:
    std::random_device randomDevice;
    std::mt19937 randomEngine;
    std::uniform_int_distribution<int> distribution;
};

#endif // USERIDGENERATOR_H
