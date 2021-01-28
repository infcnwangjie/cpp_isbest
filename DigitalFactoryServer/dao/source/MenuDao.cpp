#include "MenuDao.h"


bool MenuDao::addMenu(string menuname,string url,string icon,int pid,int is_parent){

    stringstream sqlBuilder;
    sqlBuilder<<"insert into menu(menuname,url,icon,pid,is_parent) values"<<"('"<<menuname<<"','"
             <<url<<"','"<<icon<<"',"<<pid<<","<<is_parent<<")";

    string sql=sqlBuilder.str();

    return add(sql);
}

bool MenuDao::deleteMenu(string menuname){

    stringstream sqlBuilder;
    sqlBuilder<<"delete from  menu where name='"<<menuname<<"'";

    string sql=sqlBuilder.str();

    return deleteDatas(sql);

}
bool MenuDao::deleteMenuById(int id){
    stringstream sqlBuilder;
    sqlBuilder<<"delete from  menu where id="<<id;

    string sql=sqlBuilder.str();

    return deleteDatas(sql);
}
bool MenuDao::modifyMenu(int id,string menuname,string url,string icon,int pid,int is_parent){


    stringstream sqlBuilder;
    sqlBuilder<<"update menu set name='"<<menuname<<",url='"<<url<<"',"<<icon<<"',"<<pid<<","<<is_parent
             <<" where id="<<id;

    string sql=sqlBuilder.str();

    return modify(sql);
}
map<string,string> MenuDao::getMenuById(int id){
    map<string,string> menuInfo;


    stringstream sqlBuilder;
    sqlBuilder<<"select * from menu  where id="<<id;

    string sql=sqlBuilder.str();

    return getOne(sql);
}
list<map<string,string>> MenuDao::selectMenus(string menuname,string url,
                                              int pageSize,int currentPage){
    list<map<string,string>> menuInfos;

    stringstream sqlBuilder;
    sqlBuilder<<"select * from role";
    if(menuname!="" or url!="" ){
        sqlBuilder<<" where ";
        if(menuname!=""){
            sqlBuilder<<"  menuname='"<<menuname<<"'";
        }

        if(url!=""){
            sqlBuilder<<"  url='"<<url<<"'";
        }


    }

    sqlBuilder<<" limit "<<(currentPage-1)*pageSize<<","<<pageSize;

    string sql=sqlBuilder.str();

    cout<<sql<<endl;

    return query(sql);
}






