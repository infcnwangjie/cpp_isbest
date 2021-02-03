#ifndef USER_SERVICE_H
#define USER_SERVICE_H
#include "UserDao.h"
#include <map>
#include<list>
#include "tinyjson.hpp"

using namespace tiny;
using namespace std;

class  UserService{

public:
    UserService():userDao(new UserDao()){

    }
    ~UserService(){
        if(userDao!=nullptr){
            delete userDao;
        }
    }

private:
    UserDao * userDao;


public:

    bool login(string jsonstr);
    bool addUser(string jsonstr);
    bool deleteUser(string jsonstr);
    bool deleteUserById(string jsonstr);
    bool modifyUser(string jsonstr);
    map<string,string> getUserById(string jsonstr);
    list<map<string,string>> selectUsers(string jsonstr);



};

#endif // USER_SERVICE_H


