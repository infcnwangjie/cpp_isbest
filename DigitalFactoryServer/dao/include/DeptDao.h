#ifndef DEPTDAO_H
#define DEPTDAO_H

#include "BaseDao.h"
#include <map>
#include<list>

using namespace std;

class DeptDao:protected BaseDao
{
public:
    DeptDao(){

    }

public:

    bool addDept(string name,string remark);
    bool deleteDept(string name);
    bool deleteDeptById(int id);
    bool modifyDept(int id,string name,string remark);
    map<string,string> getDeptById(int id);
    list<map<string,string>> selectDepts(string name="",string remark="",
                                         int pageSize=3,int currentPage=1);



};


#endif // MENUDAO_H
