#include "loginwindow.h"

#define DEBUG 1      //开启测试
#include <QApplication>
#include <meanshift.h>
#include <iostream>
#include<string>
#include "postsqlsdk.h"
#include "mysql.h"

//#define DEBUG 1
using namespace  std;



int main(int argc, char *argv[])
{


    //   测试用例编写
#ifdef DEBUG
//    PostgreSqlSdk p;
//    p.test_sql();
//    cout<<"执行debug"<<endl;

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

#endif




    QApplication a(argc, argv);
    LoginWindow w;
    w.setWindowTitle("智慧工厂");
    w.show();


    return a.exec();
}
