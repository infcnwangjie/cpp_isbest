#ifndef USER_H
#define USER_H
#include<string>

class User
{
public:
    User();
    std::string getUserName();
    void setUserName(std::string name);

    std::string getPassWord();
    void setPassWord(std::string password);

    std::string getTrueName();
    void setTrueName(std::string trueName);

    std::string getRoles();
    void setRoles(std::string rolls);


    std::string getRemarks();
    void setRemarks(std::string remarks);


private:

    long userId;
    std::string userName;
    std::string password;
    std::string trueName;
    std::string roles;
    std::string remarks;

};

#endif // USER_H
