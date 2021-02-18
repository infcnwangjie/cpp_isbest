#ifndef LOGINDAO_H
#define LOGINDAO_H
#include "BaseDao.h"
#include <map>
#include<list>

using namespace std;

class  UserDao{

public:
    UserDao(){

    }
    ~UserDao(){

    }


public:

    string login(string userName,string passWord,string registcode);
    string addUser(string name,string email,int staffposition_id,int role_id,int depart_id,string remark,string password="123456");
    string deleteUser(string name,string password);
    string deleteUserById(int id);
    string modifyUser(int id,string name,string email,int staffposition_id,int role_id,int depart_id,string remark,string password);
    string getUserById(int id);
    string selectUsers(string name="",string email="",int staffposition_id=0,int role_id=0,int depart_id=0,string password="",
                      int pageSize=3,int currentPage=1);



};

#endif // LOGINDAO_H


