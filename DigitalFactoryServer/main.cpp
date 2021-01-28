#include "mainwindow.h"

#include <QApplication>

#include <iostream>
#include<string>
using namespace  std;

#include "mysql.h"

#define DEBUG 1

#ifdef DEBUG
#include "UserDao.h"
#include "UserRoleDao.h"
#endif

void testmysql(){

    MYSQL mysql;
    mysql_init(&mysql);
    const char *host = "127.0.0.1";
    const char *user = "root";
    const char *pass = "root";
    const char *db = "myshop"; // 数据库名称（已存在）
    if (!mysql_real_connect(&mysql, host, user, pass, db, 3306, 0, 0))
    {
        cout << "Failed" << endl;
    }
    else
    {
        cout << "success" << endl;
        if (0 == mysql_query(&mysql, "select * from goods "))
        {
            cout << "Operate_Mysql Query Success" << endl;
            MYSQL_RES *result = nullptr;
            result = mysql_store_result(&mysql);
            unsigned int rows = (unsigned int)mysql_num_rows(result);
            cout << "总记录条数： " << rows << endl;
            unsigned int fields = mysql_num_fields(result);
            cout << "每条记录总共 " << fields << " 个字段" << endl;
            MYSQL_FIELD *field = nullptr;
            for (unsigned int i = 0; i < fields; i++)
            {
                field = mysql_fetch_field_direct(result, i);
                cout << field->name << "\t\t";
            }
            cout << endl;
            MYSQL_ROW row = nullptr;
            row = mysql_fetch_row(result);
            while (nullptr != row)
            {
                for (unsigned int i = 0; i < fields; ++i)
                {
                    if (row[i] != nullptr)
                        cout << row[i] << "\t\t";
                    else
                        cout << "null" << "\t\t";
                }
                cout << endl;
                row = mysql_fetch_row(result);
            }
            mysql_free_result(result);
        }
        else
        {
            cout << "Operate_Mysql Query Failed" << endl;
            cout << mysql_error(&mysql) << endl;
        }

    }
    mysql_close(&mysql);

}


void testLogin(){
    UserDao a;

    a.addUser("cyi","cyi@163.com",1,1,"test");
    a.login("cyi","78","dd");
    a.modifyUser(5,"cyi","wj@163.com",2,2,"testmodify","2323");
    //    a.deleteUserById(6);
    //   cout<< a.getUserById(1)["name"]<<endl;
    for(map<string,string> record :a.selectUsers()){
        cout<< record["name"]<<endl;
    }
}


void testRole(){
    UserRoleDao a;
    a.addRole("测试","测试可行");
    a.addRole("仓库管理员","仓库");
    a.addRole("工程主管","工程主管");
    a.addRole("车间主任","车间");
    for(map<string,string> record :a.selectRoles()){
        cout<< record["name"]<<endl;
    }
}

int main(int argc, char *argv[])
{


#ifdef DEBUG
    //testmysql();
//    testLogin();
    testRole();
#endif


    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
