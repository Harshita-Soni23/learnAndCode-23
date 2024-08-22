#pragma once

#include <memory>
#include <stdexcept>
#include "requestHandler.h"
#include "IUser.h"

class ClientFactory {
public:
    IUser* initializeClient(Role userRole, RequestHandler* requestHandler);
};
