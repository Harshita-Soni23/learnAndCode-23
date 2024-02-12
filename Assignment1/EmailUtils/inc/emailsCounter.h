#ifndef EMAILSCOUNTER_H
#define EMAILSCOUNTER_H 

#include <iostream>
#include <mailCounter.h>
#include <emailSourceRetriever.h>
#include <ConnectionAPI.h>
#include <emailInfo.h>
class EmailsCounter {
public:
    EmailsCount getEmailsCount(const std::string &entity, const std::string &password);
private:
    EmailSourceRetriever emailSourceRetriever;
    MailCounter mailCounter;
    ConnectionAPI connection;
};

#endif