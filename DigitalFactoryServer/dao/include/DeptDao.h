#ifndef DEPTDAO_H
#define DEPTDAO_H

#include "BaseDao.h"
#include <map>
#include<list>

using namespace std;

class DeptDao
{
public:
    DeptDao(){

    }

public:

    string  addDept(string name,string remark);
    string deleteDept(string name);
    string deleteDeptById(int id);
    string modifyDept(int id,string name,string remark);
    string getDeptById(int id);
    string selectDepts(string name="",string remark="",
                                         int pageSize=3,int currentPage=1);



};


#endif // MENUDAO_H
