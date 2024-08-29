#include "clientFactory.h"
#include "iostream"
#include "admin.h"
#include "chef.h"
#include "employee.h"

IUser* ClientFactory::initializeClient(Role userRole, RequestHandler* requestHandler, int userIdLoggedIn)
{
    std::cout<<"User Role : "<<userRole<<"\n";

    IUser* user = nullptr;
    if (userRole == Role::Admin_)
    {
        user = new Admin(requestHandler);
    }
    else if(userRole == Role::Employee_)
    {
        user = new Employee(requestHandler, userIdLoggedIn);
    }
    else if(userRole == Role::Chef_)
    {
        user = new Chef(requestHandler);
    }
    else
    {
        throw std::invalid_argument("Unknown client type");
    }

    return user;
}
