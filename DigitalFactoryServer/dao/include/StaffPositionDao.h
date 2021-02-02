#ifndef STAFFPOSITION_H
#define STAFFPOSITION_H

#include "BaseDao.h"
#include <map>
#include<list>

using namespace std;

class StaffPositionDao:protected BaseDao
{
public:
    StaffPositionDao(){

    }

public:

    bool addStaffPosition(string name,string remark);
    bool deleteStaffPosition(string name);
    bool deleteStaffPositionById(int id);
    bool modifyStaffPosition(int id,string name,string remark);
    map<string,string> getStaffPositionById(int id);
    list<map<string,string>> selectStaffPositions(string name="",string remark="",
                                         int pageSize=3,int currentPage=1);



};


#endif // STAFFPOSITION_H
