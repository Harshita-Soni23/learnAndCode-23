#include "clientFactory.h"
#include "iostream"
#include "admin.h"

IUser* ClientFactory::initializeClient(Role userRole, RequestHandler* requestHandler)
{
    std::cout<<"User Role : "<<userRole<<"\n";

    IUser* user = nullptr;
    if (userRole == Role::Admin)
    {
        user = new Admin(requestHandler);
    }
    else if(userRole == Role::Employee)
    {
        user = new Employee(requestHandler, this->userIdLoggedIn);
    }
    else if(userRole == Role::Chef)
    {
        user = new Chef(requestHandler);
    }
    else
    {
        throw std::invalid_argument("Unknown client type");
    }

    return user;
}