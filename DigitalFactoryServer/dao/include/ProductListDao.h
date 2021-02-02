#ifndef PRODUCTLIST_DAO_H
#define PRODUCTLIST_DAO_H

#include "BaseDao.h"
#include <map>
#include<list>

using namespace std;

/****
产品细分类表
***/
class ProductListDao:protected BaseDao
{
public:
    ProductListDao(){

    }

public:

    bool addList(int productclass_id,string name,int employee_id,string createdate,string remark);
    bool deleteList(string name);
    bool deleteListById(int id);
    bool modifyList(int id,int productclass_id,string name,int employee_id,string createdate,string remark);
    map<string,string> getListById(int id);
    list<map<string,string>> selectLists(string name="",string remark="",
                                         int pageSize=3,int currentPage=1);

};


#endif // PRODUCTLIST_DAO_H
