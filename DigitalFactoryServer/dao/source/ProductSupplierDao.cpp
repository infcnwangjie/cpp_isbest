#include "ProductSupplier.h"



bool ProductSupplierDao::addProductSupplier(int product_id, int supplier_id){


    stringstream sqlBuilder;
    sqlBuilder<<"insert into product_supplier(product_id,supplier_id) values"<<"("<<supplier_id<<","
             <<supplier_id<<")";

    string sql=sqlBuilder.str();
    return add(sql);
}


bool ProductSupplierDao::deleteProductSupplier(int product_id, int supplier_id){


    stringstream sqlBuilder;
    sqlBuilder<<"delete from  product_supplier where product_id="<<product_id<<" and  supplier_id="<<supplier_id;

    string sql=sqlBuilder.str();

    return deleteDatas(sql);


}

map<string,string> ProductSupplierDao::getProductSupplier(int product_id, int supplier_id){


    stringstream sqlBuilder;
    sqlBuilder<<"select * from product_supplier  where product_id="<<product_id<<",supplier_id="<<supplier_id;
    string sql=sqlBuilder.str();

    map<string,string> deptInfo;
    return getOne(sql);


}
list<map<string,string>> ProductSupplierDao::selectProductSuppliers(int product_id,int supplier_id,
                                              int pageSize,int currentPage){
    stringstream sqlBuilder;
    sqlBuilder<<"select * from product_supplier";
    if(product_id!=0 or supplier_id!=0 ){
        sqlBuilder<<" where ";
        if(product_id!=0){
            sqlBuilder<<"  product_id="<<product_id;
        }
        if(supplier_id!=0){
            sqlBuilder<<"  supplier_id="<<supplier_id;
        }
    }

    sqlBuilder<<" limit "<<(currentPage-1)*pageSize<<","<<pageSize;
    string sql=sqlBuilder.str();
    list<map<string,string>> deptInfos;
    return query(sql);


}






