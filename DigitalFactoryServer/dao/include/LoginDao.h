#ifndef LOGINDAO_H
#define LOGINDAO_H
#include "ConnPool.h"
#include <map>
#include<list>

using namespace std;

class  LoginDao{

public:
    LoginDao(){

    }
    ~LoginDao(){
        delete connectPool;
    }


public:
    MYSQL fetchConn();
    bool login(string userName,string passWord,string registcode);
    bool addUser(string name,string email,int role_id,int depart_id,string remark,string password="123456");
    bool deleteUser(string name,string password);
    bool deleteUserById(int id);
    bool modifyUser(int id,string name,string email,int role_id,int depart_id,string remark,string password);
    map<string,string> getUserById(int id);
    list<map<string,string>> selectUsers(string name="",string email="",int role_id=0,int depart_id=0,string password="",
                                         int pageSize=3,int currentPage=2);

private:
    ConnPool  * connectPool;


};

#endif // LOGINDAO_H


