#include "UserRoleDao.h"




bool UserRoleDao::addRole(string name,string remark){

    stringstream sqlBuilder;
    sqlBuilder<<"insert into role(name,remark) values"<<"('"<<name<<"','"
             <<remark<<"')";

    string sql=sqlBuilder.str();

    return add(sql);
}
bool UserRoleDao::deleteRole(string name){



    stringstream sqlBuilder;
    sqlBuilder<<"delete from  role where name='"<<name<<"'";

    string sql=sqlBuilder.str();

    return deleteDatas(sql);

}
bool UserRoleDao::deleteRoleById(int id){

    stringstream sqlBuilder;
    sqlBuilder<<"delete from  role where id="<<id;

    string sql=sqlBuilder.str();

    return deleteDatas(sql);
}
bool UserRoleDao::modifyRole(int id,string name,string remark){

    stringstream sqlBuilder;
    sqlBuilder<<"update role set name='"<<name<<",remark='"<<remark<<"'"
             <<" where id="<<id;

    string sql=sqlBuilder.str();

    return modify(sql);
}
map<string,string> UserRoleDao::getRoleById(int id){

    map<string,string> roleInfo;


    stringstream sqlBuilder;
    sqlBuilder<<"select * from role  where id="<<id;

    string sql=sqlBuilder.str();

    return getOne(sql);
}
list<map<string,string>> UserRoleDao::selectRoles(string name,string remarks,
                                                  int pageSize,int currentPage){
    list<map<string,string>> roleInfos;


    stringstream sqlBuilder;
    sqlBuilder<<"select * from role";
    if(name!="" or remarks!="" ){
        sqlBuilder<<" where ";
        if(name!=""){
            sqlBuilder<<"  name='"<<name<<"'";
        }

        if(remarks!=""){
            sqlBuilder<<"  remarks='"<<remarks<<"'";
        }
    }

    sqlBuilder<<" limit "<<(currentPage-1)*pageSize<<","<<pageSize;

    string sql=sqlBuilder.str();

    return query(sql);

}
