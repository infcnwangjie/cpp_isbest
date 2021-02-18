#ifndef PRODUCT_DAO_H
#define PRODUCT_DAO_H

#include "BaseDao.h"
#include <map>
#include<list>

using namespace std;

class ProductDao
{
public:
    ProductDao(){

    }

public:

    string addProduct(int productList_id,string name,int productspec_id,int productunit_id,float price,int employee_id,string preatedate,string remark);
    string deleteProduct(string name);
    string deleteProductById(int id);
    string modifyProduct(int id,int productList_id,string name,int productspec_id,int productunit_id,float price,int employee_id,string preatedate,string remark);
    string getProductById(int id);
    string selectProducts(string name="",string remark="",
                          int pageSize=3,int currentPage=1);

};


#endif // PRODUCT_DAO_H
