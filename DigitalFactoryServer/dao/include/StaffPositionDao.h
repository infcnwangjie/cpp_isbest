#ifndef STAFFPOSITION_H
#define STAFFPOSITION_H

#include "BaseDao.h"
#include <map>
#include<list>

using namespace std;

class StaffPositionDao
{
public:
    StaffPositionDao(){

    }

public:

    string addStaffPosition(string name,string remark);
    string deleteStaffPosition(string name);
    string deleteStaffPositionById(int id);
    string modifyStaffPosition(int id,string name,string remark);
    string getStaffPositionById(int id);
    string selectStaffPositions(string name="",string remark="",
                                         int pageSize=3,int currentPage=1);



};


#endif // STAFFPOSITION_H
