#ifndef PRODUCTUNIT_DAO_H
#define PRODUCTUNIT_DAO_H

#include "BaseDao.h"
#include <map>
#include<list>

using namespace std;

class ProductuNnitDao
{
public:
    ProductuNnitDao(){

    }

public:

    string addUnit(string name,int employee_id,string createdate,string remark);
    string deleteUnit(string name);
    string deleteUnitById(int id);
    string modifyUnit(int id,string name,int employee_id,string createdate,string remark);
    string getUnitById(int id);
    string selectUnits(string name="",string remark="",
                       int pageSize=3,int currentPage=1);

};


#endif // PRODUCTCLASS_DAO_H
