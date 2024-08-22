#pragma once

#include <memory>
#include <stdexcept>
#include "requestHandler.h"
#include "IUser.h"
#include "admin.h"
#include "chef.h"
#include "employee.h"

class ClientFactory {
public:
    static IUser* initializeClient(Role userRole, RequestHandler* requestHandler);
};
