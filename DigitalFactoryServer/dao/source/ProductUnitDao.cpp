#include "ProductUnitDao.h"




bool ProductuNnitDao::addUnit(string name, int employee_id, string createdate, string remark){


    stringstream sqlBuilder;
    sqlBuilder<<"insert into productunit(name,employee_id,createdate,remark) values"<<"('"<<name<<"',"
             <<employee_id<<",'"<<createdate<<"','"
            <<remark<<"')";

    string sql=sqlBuilder.str();
    return add(sql);
}


bool ProductuNnitDao::deleteUnit(string name){


    stringstream sqlBuilder;
    sqlBuilder<<"delete from  productunit where name='"<<name<<"'";

    string sql=sqlBuilder.str();

    return deleteDatas(sql);


}
bool ProductuNnitDao::deleteUnitById(int id){

    stringstream sqlBuilder;
    sqlBuilder<<"delete from  productunit where id="<<id;

    string sql=sqlBuilder.str();

    return deleteDatas(sql);

}
bool ProductuNnitDao::modifyUnit(int id, string name, int employee_id, string createdate, string remark){


    stringstream sqlBuilder;
    sqlBuilder<<"update productunit set name= '"<<name<<"', employee_id="<<employee_id<<",createdate='"<<createdate<<"',remark='"<<remark
             <<"' where id="<<id;

    string sql=sqlBuilder.str();

    return modify(sql);

}
map<string,string> ProductuNnitDao::getUnitById(int id){


    stringstream sqlBuilder;
    sqlBuilder<<"select * from productunit  where id="<<id;
    string sql=sqlBuilder.str();

    map<string,string> deptInfo;
    return getOne(sql);


}
list<map<string,string>> ProductuNnitDao::selectUnits(string name,string remark,
                                                    int pageSize,int currentPage){
    stringstream sqlBuilder;
    sqlBuilder<<"select * from productunit";
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






