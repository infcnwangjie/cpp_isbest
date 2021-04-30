#ifndef RESULT_H
#define RESULT_H

#include <string>
#include "user.h"

class Result
{
public:
    Result();
    Result(std::string message,std::string status,User user);

    std::string getMessage();
    void setMessage(std::string message);

    std::string getStatus();
    void setStatus(std::string status);

    User getUser();
    void setUser(User user);


private:
    std::string message;
    std::string status;
    User user;
};

#endif // RESULT_H
