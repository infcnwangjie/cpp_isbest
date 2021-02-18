#ifndef USERROLEMENUDAO_H
#define USERROLEMENUDAO_H
#include "BaseDao.h"

class RoleMenuDao{

public:
    RoleMenuDao(){

    }
    ~RoleMenuDao(){

    }


public:

    string addRoleMenu(int menuid ,int roleid);
    string deleteRoleMenu(int  roleId);
    string deleteRoleMenuById(int roleId,int menuId);

    string getRoleMenuByRoleId(int roleId);
    string selectRoleMenus(int roleId=0,int menuId=0,
                                         int pageSize=3,int currentPage=1);
    string selectRoleMenus(list<string> roleids);


};

#endif // USERROLEDAO_H


