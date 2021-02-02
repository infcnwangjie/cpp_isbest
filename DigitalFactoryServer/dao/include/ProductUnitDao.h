#ifndef PRODUCTUNIT_DAO_H
#define PRODUCTUNIT_DAO_H

#include "BaseDao.h"
#include <map>
#include<list>

using namespace std;

class ProductuNnitDao:protected BaseDao
{
public:
    ProductuNnitDao(){

    }

public:

    bool addUnit(string name,int employee_id,string createdate,string remark);
    bool deleteUnit(string name);
    bool deleteUnitById(int id);
    bool modifyUnit(int id,string name,int employee_id,string createdate,string remark);
    map<string,string> getUnitById(int id);
    list<map<string,string>> selectUnits(string name="",string remark="",
                                            int pageSize=3,int currentPage=1);

};


#endif // PRODUCTCLASS_DAO_H
