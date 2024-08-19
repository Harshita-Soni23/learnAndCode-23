#include "clientFactory.h"

static std::unique_ptr<IUser> clientFactory::initializeClient(Role userRole, RequestHandler* RequestHandler)
{
    std::cout<<"User Role : "<<userRole<<"\n";

    std::unique_ptr<IUser> user;
    if (userRole == Role::Admin)
    {
        user = std::make_unique<Admin>(requestHandler);
    }
    else if(userRole == Role::Employee)
    {
        user = std::make_unique<Employee>(requestHandler, this->userIdLoggedIn);
    }
    else if(userRole == Role::Chef)
    {
        user = std::make_unique<Chef>(requestHandler);
    }
    else
    {
        throw std::invalid_argument("Unknown client type");
    }

    return user;
}