#ifndef USERROLEDAO_H
#define USERROLEDAO_H
#include "ConnPool.h"

class UserRoleDao{

public:
    UserRoleDao(){

    }
    ~UserRoleDao(){
        delete connectPool;
    }


public:
    MYSQL fetchConn();
    bool addRole(string name,string remark);
    bool deleteRole(string name);
    bool deleteRoleById(int id);
    bool modifyRole(int id,string name,string remark);
    map<string,string> getRoleById(int id);
    list<map<string,string>> selectRoles(string name="",string remarks="",
                                         int pageSize=3,int currentPage=2);

private:
    ConnPool  * connectPool;

};

#endif // USERROLEDAO_H


