#include "ProductSpecDao.h"




string ProductSpecDao::addSpec(string name, int employee_id, string createdate, string remark){


    stringstream sqlBuilder;
    sqlBuilder<<"insert into productspec(name,employee_id,createdate,remark) values"<<"('"<<name<<"',"<<employee_id<<",'"
             <<createdate<<"','"<<remark<<"')";

    string sql=sqlBuilder.str();
    return sql;
}


string ProductSpecDao::deleteSpec(string name){


    stringstream sqlBuilder;
    sqlBuilder<<"delete from  productspec where name='"<<name<<"'";

    string sql=sqlBuilder.str();

    return sql;


}
string ProductSpecDao::deleteSpecById(int id){

    stringstream sqlBuilder;
    sqlBuilder<<"delete from  productspec where id="<<id;

    string sql=sqlBuilder.str();

    return sql;

}
string ProductSpecDao::modifySpec(int id, string name, int employee_id, string createdate, string remark){


    stringstream sqlBuilder;
    sqlBuilder<<"update productspec set name='"<<name<<"',employee_id="<<employee_id<<",createdate='"<<createdate<<"',remark='"<<remark<<"'"
             <<" where id="<<id;

    string sql=sqlBuilder.str();

    return sql;

}
string ProductSpecDao::getSpecById(int id){


    stringstream sqlBuilder;
    sqlBuilder<<"select * from productspec  where id="<<id;
    string sql=sqlBuilder.str();

    return sql;


}
string ProductSpecDao::selectSpecs(string name,string remark,
                                   int pageSize,int currentPage){
    stringstream sqlBuilder;
    sqlBuilder<<"select * from productspec";
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
    return sql;


}






