#ifndef ROLEDAO_H
#define ROLEDAO_H
#include "BaseDao.h"

class RoleDao{

public:
    RoleDao(){

    }
    ~RoleDao(){

    }


public:

    string addRole(string name,string remark);
    string deleteRole(string name);
    string deleteRoleById(int id);
    string modifyRole(int id,string name,string remark);
    string getRoleById(int id);
    string selectRoles(string name="",string remarks="",
                       int pageSize=3,int currentPage=2);

};

#endif // USERROLEDAO_H


