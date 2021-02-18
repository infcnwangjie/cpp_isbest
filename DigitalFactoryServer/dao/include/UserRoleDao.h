#ifndef USER_ROLEDAO_H
#define USER_ROLEDAO_H
#include "BaseDao.h"
#include <string>
using namespace std;
class UserRoleDao{

public:
    UserRoleDao(){

    }
    ~UserRoleDao(){

    }


public:

    string addUserRole(int user_id,int role_id);
    string deleteUserRole(int user_id,int role_id);
    string deleteUserRoleById(int id);
    string getUserRoleById(int id);
    string selectRolesByUserId(int user_id=0,
                               int pageSize=3,int currentPage=1);

};

#endif // USERROLEDAO_H


