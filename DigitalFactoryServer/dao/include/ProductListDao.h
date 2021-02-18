#ifndef PRODUCTLIST_DAO_H
#define PRODUCTLIST_DAO_H

#include "BaseDao.h"
#include <map>
#include<list>

using namespace std;

/****
产品细分类表
***/
class ProductListDao
{
public:
    ProductListDao(){

    }

public:

    string addList(int productclass_id,string name,int employee_id,string createdate,string remark);
    string deleteList(string name);
    string deleteListById(int id);
    string modifyList(int id,int productclass_id,string name,int employee_id,string createdate,string remark);
    string getListById(int id);
    string selectLists(string name="",string remark="",
                                         int pageSize=3,int currentPage=1);

};


#endif // PRODUCTLIST_DAO_H
