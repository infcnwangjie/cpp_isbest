#ifndef PRODUCT_SUPPLIER_H
#define PRODUCT_SUPPLIER_H

#include "BaseDao.h"
#include <map>
#include<list>

using namespace std;

class ProductSupplierDao
{
public:
    ProductSupplierDao(){

    }

public:

    string addProductSupplier(int product_id,int supplier_id);
    string deleteProductSupplier(int product_id,int supplier_id);
    string getProductSupplier(int product_id,int supplier_id);
    string selectProductSuppliers(int product_id=0,int supplier_id=0,
                                         int pageSize=3,int currentPage=1);

};


#endif // PRODUCT_SUPPLIER_H
