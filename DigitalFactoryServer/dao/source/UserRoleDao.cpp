#include "UserRoleDao.h"




string UserRoleDao::addUserRole(int user_id, int role_id){

    stringstream sqlBuilder;
    sqlBuilder<<"insert into user_role(user_id,role_id) values"<<"("<<user_id<<","
             <<role_id<<")";

    string sql=sqlBuilder.str();

    return sql;
}
string UserRoleDao::deleteUserRole(int user_id,int role_id){



    stringstream sqlBuilder;
    sqlBuilder<<"delete from  user_role where user_id="<<user_id<<" and  role_id="<<role_id;

    string sql=sqlBuilder.str();

    return sql;

}
string UserRoleDao::deleteUserRoleById(int id){

    stringstream sqlBuilder;
    sqlBuilder<<"delete from  user_role where id="<<id;

    string sql=sqlBuilder.str();

    return sql;
}

string UserRoleDao::getUserRoleById(int id){

    map<string,string> roleInfo;


    stringstream sqlBuilder;
    sqlBuilder<<"select * from user_role  where id="<<id;

    string sql=sqlBuilder.str();

    return sql;
}

string UserRoleDao::selectRolesByUserId(int user_id,
                                        int pageSize,int currentPage){
    list<map<string,string>> roleInfos;


    stringstream sqlBuilder;
    sqlBuilder<<"SELECT * from role where id in (SELECT role_id from user_role where user_id="<<user_id<<")";


    sqlBuilder<<" limit "<<(currentPage-1)*pageSize<<","<<pageSize;

    string sql=sqlBuilder.str();

    return sql;

}
