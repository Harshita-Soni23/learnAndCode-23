#ifndef EMAILSOURCE_RETRIEVER_H
#define EMAILSOURCE_RETRIEVER_H

#include <iostream>

class EmailSourceRetriever {
public:
    std::string getEmailSource(const std::string &email) const;
};

#endif