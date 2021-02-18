#include "ProductDao.h"




string ProductDao::addProduct(int productList_id,string name,int productspec_id,int productunit_id,float price,int employee_id,string preatedate,string remark){


    stringstream sqlBuilder;
    sqlBuilder<<"insert into product(productList_id,name,productspec_id,productunit_id,price,employee_id,preatedate,remark) values"<<"("<<productList_id<<",'"<<name<<"',"
             <<productspec_id<<","<<productunit_id<<","<<price<<","<<employee_id<<",'"<<preatedate<<"','"
            <<remark<<"')";

    string sql=sqlBuilder.str();
 return sql;
}


string ProductDao::deleteProduct(string name){


    stringstream sqlBuilder;
    sqlBuilder<<"delete from  product where name='"<<name<<"'";

    string sql=sqlBuilder.str();

 return sql;


}
string ProductDao::deleteProductById(int id){

    stringstream sqlBuilder;
    sqlBuilder<<"delete from  product where id="<<id;

    string sql=sqlBuilder.str();

 return sql;

}
string ProductDao::modifyProduct(int id,int productList_id,string name,int productspec_id,int productunit_id,float price,int employee_id,string preatedate,string remark){


    stringstream sqlBuilder;
    sqlBuilder<<"update product set productList_id="<<productList_id<<", name='"<<name<<"',productspec_id="<<productspec_id<<",productunit_id="<<productunit_id<<",price="
            <<price<<",employee_id="<<employee_id<<",preatedate="<<preatedate<<",remark='"<<remark<<"'"
             <<" where id="<<id;

    string sql=sqlBuilder.str();
 return sql;

}
string ProductDao::getProductById(int id){


    stringstream sqlBuilder;
    sqlBuilder<<"select * from product  where id="<<id;
    string sql=sqlBuilder.str();

 return sql;


}
string ProductDao::selectProducts(string name,string remark,
                                                    int pageSize,int currentPage){
    stringstream sqlBuilder;
    sqlBuilder<<"select * from product";
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
   return sql;


}






