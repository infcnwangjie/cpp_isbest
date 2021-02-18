#ifndef EMPLOYEE_DAO_H
#define EMPLOYEE_DAO_H

#include "BaseDao.h"
#include <map>
#include<list>

using namespace std;

class EmployeeDao
{
public:
    EmployeeDao(){

    }

public:

    string addEmployee(string name,int dept_id,string duty,string gender,string birthdate,string maturedate,string identitycard,
                     string address,string phone,string email
                     );
    string deleteEmployee(string name);
    string deleteEmployeeById(int id);
    string modifyEmployee(int id,string name,int dept_id,string duty,string gender,string birthdate,string maturedate,string identitycard,
                        string address,string phone,string email);
    string getEmployeeById(int id);
    string selectEmployeess(string name="",int dept_id=0,
                                            int pageSize=3,int currentPage=1);

};


#endif // EMPLOYEE_DAO_H
