#ifndef PRODUCTCLASS_DAO_H
#define PRODUCTCLASS_DAO_H

#include "BaseDao.h"
#include <map>
#include<list>

using namespace std;

class ProductClassDao
{
public:
    ProductClassDao(){

    }

public:

    string addClass(string name,int employee_id,string createdate,string remark);
    string deleteClass(string name);
    string deleteClassById(int id);
    string modifyClass(int id,string name,int employee_id,string createdate,string remark);
    string getClassById(int id);
    string selectClasses(string name="",int employee_id=0,string remark="",
                                            int pageSize=3,int currentPage=1);

};


#endif // PRODUCTCLASS_DAO_H
