#include "UserIdGenerator.h"

UserIdGenerator::UserIdGenerator() 
    : randomDevice(), randomEngine(randomDevice()), distribution(1000, 9999) {
}

std::string UserIdGenerator::generateUserId() {
    auto currentTime = std::chrono::system_clock::now();
    auto timeInMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime.time_since_epoch()).count();
    auto randomValue = distribution(randomEngine);
    return "ID_" + std::to_string(timeInMilliseconds) + "_" + std::to_string(randomValue);
}
