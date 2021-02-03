#ifndef EMPLOYEE_DAO_H
#define EMPLOYEE_DAO_H

#include "BaseDao.h"
#include <map>
#include<list>

using namespace std;

class EmployeeDao:protected BaseDao
{
public:
    EmployeeDao(){

    }

public:

    bool addEmployee(string name,int dept_id,string duty,string gender,string birthdate,string maturedate,string identitycard,
                     string address,string phone,string email
                     );
    bool deleteEmployee(string name);
    bool deleteEmployeeById(int id);
    bool modifyEmployee(int id,string name,int dept_id,string duty,string gender,string birthdate,string maturedate,string identitycard,
                        string address,string phone,string email);
    map<string,string> getEmployeeById(int id);
    list<map<string,string>> selectEmployeess(string name="",int dept_id=0,
                                            int pageSize=3,int currentPage=1);

};


#endif // EMPLOYEE_DAO_H
