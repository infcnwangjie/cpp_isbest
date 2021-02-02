#ifndef PRODUCT_DAO_H
#define PRODUCT_DAO_H

#include "BaseDao.h"
#include <map>
#include<list>

using namespace std;

class ProductDao:protected BaseDao
{
public:
    ProductDao(){

    }

public:

    bool addProduct(int productList_id,string name,int productspec_id,int productunit_id,float price,int employee_id,string preatedate,string remark);
    bool deleteProduct(string name);
    bool deleteProductById(int id);
    bool modifyProduct(int id,int productList_id,string name,int productspec_id,int productunit_id,float price,int employee_id,string preatedate,string remark);
    map<string,string> getProductById(int id);
    list<map<string,string>> selectProducts(string name="",string remark="",
                                            int pageSize=3,int currentPage=1);

};


#endif // PRODUCT_DAO_H
