#ifndef PRODUCTCLASS_DAO_H
#define PRODUCTCLASS_DAO_H

#include "BaseDao.h"
#include <map>
#include<list>

using namespace std;

class ProductClassDao:protected BaseDao
{
public:
    ProductClassDao(){

    }

public:

    bool addClass(string name,int employee_id,string createdate,string remark);
    bool deleteClass(string name);
    bool deleteClassById(int id);
    bool modifyClass(int id,string name,int employee_id,string createdate,string remark);
    map<string,string> getClassById(int id);
    list<map<string,string>> selectClasses(string name="",int employee_id=0,string remark="",
                                            int pageSize=3,int currentPage=1);

};


#endif // PRODUCTCLASS_DAO_H
