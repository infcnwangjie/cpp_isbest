#include "ProductClassDao.h"




string ProductClassDao::addClass(string name, int employee_id, string createdate, string remark){

    stringstream sqlBuilder;
    sqlBuilder<<"insert into productclass(name,employee_id,createdate,remark) values"<<"('"<<name<<"',"<<employee_id<<",'"
             <<createdate<<"','"
            <<remark<<"')";

    string sql=sqlBuilder.str();
    return sql;
}


string ProductClassDao::deleteClass(string name){


    stringstream sqlBuilder;
    sqlBuilder<<"delete from  productclass where name='"<<name<<"'";

    string sql=sqlBuilder.str();

    return sql;


}
string ProductClassDao::deleteClassById(int id){

    stringstream sqlBuilder;
    sqlBuilder<<"delete from  productclass where id="<<id;

    string sql=sqlBuilder.str();

    return sql;
}
string ProductClassDao::modifyClass(int id, string name, int employee_id, string createdate, string remark){


    stringstream sqlBuilder;
    sqlBuilder<<"update productclass set name='"<<name<<"', employee_id="<<employee_id<<",createdate='"<<createdate<<
                "',remark='"<<remark<<"'  where id="<<id;

    string sql=sqlBuilder.str();
    return sql;

}
string ProductClassDao::getClassById(int id){


    stringstream sqlBuilder;
    sqlBuilder<<"select * from productclass  where id="<<id;
    string sql=sqlBuilder.str();

    map<string,string> deptInfo;
    return sql;


}
string ProductClassDao::selectClasses(string name,int employee_id,string remark,
                                      int pageSize,int currentPage){
    stringstream sqlBuilder;
    sqlBuilder<<"select * from productclass";
    if(name!="" or remark!="" ){
        sqlBuilder<<" where ";
        if(name!=""){
            sqlBuilder<<"  name='"<<name<<"'";
        }
        if(remark!=""){
            sqlBuilder<<"  remark='"<<remark<<"'";
        }
        if(employee_id!=0){
            sqlBuilder<<"  employee_id="<<employee_id;
        }
        if(remark!=""){
            sqlBuilder<<"  remark like '%"<<employee_id <<"%'";
        }
    }

    sqlBuilder<<" limit "<<(currentPage-1)*pageSize<<","<<pageSize;
    string sql=sqlBuilder.str();
    return sql;


}






