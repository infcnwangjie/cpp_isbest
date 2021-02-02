#include "ProductListDao.h"




bool ProductListDao::addList(int productclass_id, string name, int employee_id, string createdate, string remark){


    stringstream sqlBuilder;
    sqlBuilder<<"insert into productlist(productclass_id,name,employee_id,createdate,remark) values"<<"('"<<productclass_id<<"','"<<name<<"',"
             <<employee_id<<",'"<<createdate<<"','"<<remark<<"')";

    string sql=sqlBuilder.str();
    return add(sql);
}


bool ProductListDao::deleteList(string name){


    stringstream sqlBuilder;
    sqlBuilder<<"delete from  productlist where name='"<<name<<"'";

    string sql=sqlBuilder.str();

    return deleteDatas(sql);


}
bool ProductListDao::deleteListById(int id){

    stringstream sqlBuilder;
    sqlBuilder<<"delete from  productlist where id="<<id;

    string sql=sqlBuilder.str();

    return deleteDatas(sql);

}
bool ProductListDao::modifyList(int id, int productclass_id, string name, int employee_id, string createdate, string remark){


    stringstream sqlBuilder;
    sqlBuilder<<"update productlist set productclass_id="<<productclass_id<<", name='"<<name<<"',employee_id="<<employee_id<<",createdate='"<<createdate<<"',remark='"
            <<remark <<"' where id="<<id;


    string sql=sqlBuilder.str();

    return modify(sql);

}
map<string,string> ProductListDao::getListById(int id){


    stringstream sqlBuilder;
    sqlBuilder<<"select * from productlist  where id="<<id;
    string sql=sqlBuilder.str();

    map<string,string> deptInfo;
    return getOne(sql);


}
list<map<string,string>> ProductListDao::selectLists(string name,string remark,
                                                    int pageSize,int currentPage){
    stringstream sqlBuilder;
    sqlBuilder<<"select * from productlist";
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






