#ifndef USERROLEMENUDAO_H
#define USERROLEMENUDAO_H
#include "ConnPool.h"

class RoleMenuDao{

public:
    RoleMenuDao(){

    }
    ~RoleMenuDao(){
        delete connectPool;
    }


public:
    MYSQL fetchConn();
    bool addRoleMenu(int menuid ,int roleid);
    bool deleteRoleMenu(int  roleId);
    bool deleteRoleMenuById(int roleId,int menuId);

    map<string,string> getRoleMenuByRoleId(int roleId);
    list<map<string,string>> selectRoleMenus(int roleId=0,int menuId=0,
                                         int pageSize=3,int currentPage=2);

private:
    ConnPool  * connectPool;

};

#endif // USERROLEDAO_H


