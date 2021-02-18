#ifndef USER_SERVICE_H
#define USER_SERVICE_H


#include <map>
#include<list>


#include "UserDao.h"
#include "UserRoleDao.h"
#include "RoleMenuDao.h"


using namespace std;

class  UserService{

public:
    UserService():userDao(new UserDao()){

        dao=new BaseDao();
    }
    ~UserService(){
        if(userDao!=nullptr){
            delete userDao;
        }
    }

private:
    UserDao * userDao;
    UserRoleDao *userRoleDao;
    RoleMenuDao *roleMenuDao;
    BaseDao * dao;

public:

    string login(string jsonstr);
    bool addUser(string jsonstr);
    bool deleteUser(string jsonstr);
    bool deleteUserById(string jsonstr);
    bool modifyUser(string jsonstr);
    map<string,string> getUserById(string jsonstr);
    list<map<string,string>> selectUsers(string jsonstr);



};

#endif // USER_SERVICE_H


