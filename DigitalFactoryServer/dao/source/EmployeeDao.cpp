#include "EmployeeDao.h"




string EmployeeDao::addEmployee(string name, int dept_id, string duty, string gender, string birthdate, string maturedate,
                                string identitycard, string address,
                                string phone, string email){


    stringstream sqlBuilder;
    sqlBuilder<<"insert into employee(name,dept_id,duty,gender,birthdate,maturedate,identitycard,address,phone,email) values"<<"('"<<name<<"',"
             <<dept_id<<",'"<<duty<<"','"<<gender<<"','"<<birthdate<<"','"<<maturedate<<"','"
            <<identitycard<<"','"<<address<<"','"<<phone<<"','"<<email<<"')";

    string sql=sqlBuilder.str();
    return sql;
}


string EmployeeDao::deleteEmployee(string name){


    stringstream sqlBuilder;
    sqlBuilder<<"delete from  employee where name='"<<name<<"'";

    string sql=sqlBuilder.str();

    return sql;


}
string EmployeeDao::deleteEmployeeById(int id){

    stringstream sqlBuilder;
    sqlBuilder<<"delete from  employee where id="<<id;

    string sql=sqlBuilder.str();

    return sql;
}
string EmployeeDao::modifyEmployee(int id, string name, int dept_id, string duty, string gender, string birthdate, string maturedate,
                                   string identitycard, string address, string phone, string email){


    stringstream sqlBuilder;
    sqlBuilder<<"update employee set name= '"<<name<<"', dept_id="<<dept_id<<",duty='"<<duty<<"',gender='"<<gender
             <<"',birthdate='"<<birthdate<<"',maturedate='"<<maturedate<<"',identitycard='"<<identitycard<<"',address='"
            <<address<<"',phone='"<<phone<<"',email='"<<email
           <<"' where id="<<id;

    string sql=sqlBuilder.str();
    return sql;

}
string EmployeeDao::getEmployeeById(int id){


    stringstream sqlBuilder;
    sqlBuilder<<"select * from employee  where id="<<id;
    string sql=sqlBuilder.str();


    return sql;


}
string EmployeeDao::selectEmployeess(string name,int dept_id,
                                     int pageSize,int currentPage){
    stringstream sqlBuilder;
    sqlBuilder<<"select * from employee";
    if(name!="" or dept_id!=0){
        sqlBuilder<<" where ";
        if(name!=""){
            sqlBuilder<<"  name='"<<name<<"'";
        }
        if(dept_id!=0){
            sqlBuilder<<"  dept_id="<<dept_id;
        }
    }

    sqlBuilder<<" limit "<<(currentPage-1)*pageSize<<","<<pageSize;
    string sql=sqlBuilder.str();

    return sql;


}






