#ifndef PRODUCTSPEC_DAO_H
#define PRODUCTSPEC_DAO_H

#include "BaseDao.h"
#include <map>
#include<list>

using namespace std;

class ProductSpecDao
{
public:
    ProductSpecDao(){

    }

public:

    string addSpec(string name,int employee_id,string createdate,string remark);
    string deleteSpec(string name);
    string deleteSpecById(int id);
    string modifySpec(int id,string name,int employee_id,string createdate,string remark);
    string getSpecById(int id);
    string selectSpecs(string name="",string remark="",
                       int pageSize=3,int currentPage=1);

};


#endif // PRODUCTCLASS_DAO_H
