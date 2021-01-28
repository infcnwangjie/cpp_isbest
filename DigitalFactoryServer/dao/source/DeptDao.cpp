#include "DeptDao.h"


bool DeptDao::addDept(string name, string remark){


    stringstream sqlBuilder;
    sqlBuilder<<"insert into dept(name,remark) values"<<"('"<<name<<"','"
             <<remark<<"')";

    string sql=sqlBuilder.str();
    return add(sql);
}


bool DeptDao::deleteDept(string name){


    stringstream sqlBuilder;
    sqlBuilder<<"delete from  dept where name='"<<name<<"'";

    string sql=sqlBuilder.str();

    return deleteDatas(sql);


}
bool DeptDao::deleteDeptById(int id){

    stringstream sqlBuilder;
    sqlBuilder<<"delete from  dept where id="<<id;

    string sql=sqlBuilder.str();

    return deleteDatas(sql);

}
bool DeptDao::modifyDept(int id, string name, string remark){


    stringstream sqlBuilder;
    sqlBuilder<<"update dept set name='"<<name<<",remark='"<<remark<<"'"
             <<" where id="<<id;

    string sql=sqlBuilder.str();

    return modify(sql);

}
map<string,string> DeptDao::getDeptById(int id){


    stringstream sqlBuilder;
    sqlBuilder<<"select * from dept  where id="<<id;
    string sql=sqlBuilder.str();

    map<string,string> deptInfo;
    return getOne(sql);


}
list<map<string,string>> DeptDao::selectDepts(string name,string remark,
                                              int pageSize,int currentPage){
    stringstream sqlBuilder;
    sqlBuilder<<"select * from dept";
    if(name!="" or remark!="" ){
        sqlBuilder<<" where ";
        if(name!=""){
            sqlBuilder<<"  name='"<<name<<"'";
        }
        if(remark!=""){
            sqlBuilder<<"  remark='"<<remark<<"'";
        }
    }

    sqlBuilder<<" limit "<<(currentPage-1)*pageSize<<","<<pageSize;
    string sql=sqlBuilder.str();
    list<map<string,string>> deptInfos;
    return query(sql);


}






