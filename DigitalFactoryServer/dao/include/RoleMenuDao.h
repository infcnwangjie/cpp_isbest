#ifndef USERROLEMENUDAO_H
#define USERROLEMENUDAO_H
#include "BaseDao.h"

class RoleMenuDao:protected BaseDao{

public:
    RoleMenuDao(){

    }
    ~RoleMenuDao(){
        delete connectPool;
    }


public:

    bool addRoleMenu(int menuid ,int roleid);
    bool deleteRoleMenu(int  roleId);
    bool deleteRoleMenuById(int roleId,int menuId);

    map<string,string> getRoleMenuByRoleId(int roleId);
    list<map<string,string>> selectRoleMenus(int roleId=0,int menuId=0,
                                         int pageSize=3,int currentPage=2);


};

#endif // USERROLEDAO_H


