#include "StaffPositionDao.h"


bool StaffPositionDao::addStaffPosition(string name, string remark){


    stringstream sqlBuilder;
    sqlBuilder<<"insert into staff_position(name,remark) values"<<"('"<<name<<"','"
             <<remark<<"')";

    string sql=sqlBuilder.str();
    return add(sql);
}


bool StaffPositionDao::deleteStaffPosition(string name){


    stringstream sqlBuilder;
    sqlBuilder<<"delete from  staff_position where name='"<<name<<"'";

    string sql=sqlBuilder.str();

    return deleteDatas(sql);


}
bool StaffPositionDao::deleteStaffPositionById(int id){

    stringstream sqlBuilder;
    sqlBuilder<<"delete from  staff_position where id="<<id;

    string sql=sqlBuilder.str();

    return deleteDatas(sql);

}
bool StaffPositionDao::modifyStaffPosition(int id, string name, string remark){


    stringstream sqlBuilder;
    sqlBuilder<<"update staff_position set name='"<<name<<",remark='"<<remark<<"'"
             <<" where id="<<id;

    string sql=sqlBuilder.str();

    return modify(sql);

}
map<string,string> StaffPositionDao::getStaffPositionById(int id){


    stringstream sqlBuilder;
    sqlBuilder<<"select * from staff_position  where id="<<id;
    string sql=sqlBuilder.str();

    map<string,string> deptInfo;
    return getOne(sql);


}
list<map<string,string>> StaffPositionDao::selectStaffPositions(string name,string remark,
                                              int pageSize,int currentPage){
    stringstream sqlBuilder;
    sqlBuilder<<"select * from staff_position";
    if(name!="" or remark!="" ){
        sqlBuilder<<" where ";
        if(name!=""){
            sqlBuilder<<"  name='"<<name<<"'";
        }
        if(remark!=""){
            sqlBuilder<<"  remark='"<<remark<<"'";
        }
    }

    sqlBuilder<<" limit "<<(currentPage-1)*pageSize<<","<<pageSize;
    string sql=sqlBuilder.str();
    list<map<string,string>> deptInfos;
    return query(sql);


}






