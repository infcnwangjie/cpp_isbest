#ifndef PRODUCTSPEC_DAO_H
#define PRODUCTSPEC_DAO_H

#include "BaseDao.h"
#include <map>
#include<list>

using namespace std;

class ProductSpecDao:protected BaseDao
{
public:
    ProductSpecDao(){

    }

public:

    bool addSpec(string name,int employee_id,string createdate,string remark);
    bool deleteSpec(string name);
    bool deleteSpecById(int id);
    bool modifySpec(int id,string name,int employee_id,string createdate,string remark);
    map<string,string> getSpecById(int id);
    list<map<string,string>> selectSpecs(string name="",string remark="",
                                            int pageSize=3,int currentPage=1);

};


#endif // PRODUCTCLASS_DAO_H
