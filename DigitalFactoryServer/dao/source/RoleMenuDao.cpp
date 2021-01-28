#include "RoleMenuDao.h"





bool RoleMenuDao::addRoleMenu(int menuid ,int roleid){

    stringstream sqlBuilder;
    sqlBuilder<<"insert into role_menu(menuid,roleid) values"<<"("<<menuid<<","
             <<roleid<<")";

    string sql=sqlBuilder.str();

    return add(sql);
}
bool RoleMenuDao::deleteRoleMenu(int roleId){

    stringstream sqlBuilder;
    sqlBuilder<<"delete from  role_menu where roleid="<<roleId;

    string sql=sqlBuilder.str();

    return deleteDatas(sql);

}
bool RoleMenuDao::deleteRoleMenuById(int roleId, int menuId){


    stringstream sqlBuilder;
    sqlBuilder<<"delete from  role_menu where menuid="<<menuId<<" roleid="<<roleId;

    string sql=sqlBuilder.str();

    return deleteDatas(sql);

}

map<string,string> RoleMenuDao::getRoleMenuByRoleId(int roleId){

    map<string,string> roleMenuInfo;



    stringstream sqlBuilder;
    sqlBuilder<<"select * from role_menu  where roleid="<<roleId;

    string sql=sqlBuilder.str();

    cout<<sql<<endl;

    return getOne(sql);
}
list<map<string,string>> RoleMenuDao::selectRoleMenus(int roleId,int menuId,
                                                      int pageSize,int currentPage){
    list<map<string,string>> roleMenuInfos;



    stringstream sqlBuilder;
    sqlBuilder<<"select * from role_menu";
    if(roleId!=0 or menuId!=0 ){
        sqlBuilder<<" where ";
        if(roleId!=0){
            sqlBuilder<<"  roleid="<<roleId;
        }

        if(menuId!=0){
            sqlBuilder<<"  menuId="<<menuId;
        }
    }

    sqlBuilder<<" limit "<<(currentPage-1)*pageSize<<","<<pageSize;

    string sql=sqlBuilder.str();

    return query(sql);

}
