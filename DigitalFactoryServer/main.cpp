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
#include "DeptDao.h"
#include "tinyjson.hpp"
#include <cassert>
using namespace std;
using namespace tiny;
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
    //    UserDao a;

    //    a.addUser("cyi","cyi@163.com",1,1,"test");
    //    a.login("cyi","78","dd");
    //    a.modifyUser(5,"cyi","wj@163.com",2,2,"testmodify","2323");
    //    //    a.deleteUserById(6);
    //    //   cout<< a.getUserById(1)["name"]<<endl;
    //    for(map<string,string> record :a.selectUsers()){
    //        cout<< record["name"]<<endl;
    //    }
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

void testDept(){
    DeptDao a;
    a.addDept("测试","通过会删除");
    for(map<string,string> record:a.selectDepts()){
        cout<<record["name"]<<endl;
    }
}

void  testJson(){

    string jsonstring = "\
    {\
            \"name\":\"lier  gou\",\
             \"age\" : 26.9,\
             \"data\" : [\
    {\
            \"one\":\"chenone\",\
             \"two\" : {\
             \"love1\":\"2233\",\
             \"love2\":44444\
}\
},\
    {\
        \"one\":\"chen22\",\
        \"two\" : {\
        \"love1\":\"8899\",\
        \"love2\":10000\
    }\
}\
],\
\"lang\":\"2cpp\"\
}\
";

string jsonstring2 = "\
{\
        \"name\":\"liergou\",\
         \"age\" : 26.9,\
         \"data\" : [\
{\
        \"one\":\"chenone\",\
         \"two\" : [\
         \"love_chen\",\
         \"love_hui\"\
        ]\
        },\
{\
        \"one\":\"chen22\",\
         \"two\" : [\
         \"love_chen2\",\
         \"love_hui2\"\
        ]\
        }\
        ],\
        \"lang\":\"cpp\"\
        }\
        ";

        string jsonstring3 = "\
{\
        \"xx\": {\
         \"a\": 1,\
         \"b\" : 2\
        }\
        }";

cout << "\nTEST 99 READ JSON" << endl;
// read
TinyJson json;
json.ReadJson(jsonstring3);

xobject data = json.Get<xobject>("xx");
for (int i = 0; i < data.Count(); i++) {
    data.Enter(i);
    int one = data.Get<int>("a");
    int two = data.Get<int>("b");
    int three = data.Get<int>("c", 99);
    assert(one == 1);
    assert(two == 2);
    assert(three == 99);
}
cout << "TEST 99 PASS" << endl;



cout << "\nTEST 2 READ JSON" << endl;
// read
TinyJson json2;
json.ReadJson(jsonstring2);

string name = json2.Get<string>("name");
float age = json2.Get<float>("age");
string lang = json2.Get<string>("lang");

//assert(name == "liergou");
//assert(age > 26 && age < 27);
//assert(lang == "cpp");

xarray data2 = json2.Get<xarray>("data");
for (int i = 0; i < data2.Count(); i++) {
    data2.Enter(i);
    string one = data2.Get<string>("one");
    if (i == 0)
    {
        assert(one == "chenone");
    }
    if (i == 1)
    {
        assert(one == "chen22");
    }
    xarray two = data2.Get<xarray>("two");
    for (int ii = 0; ii < two.Count(); ii++) {
        two.Enter(ii);
        string val = two.Get<string>();
        if (i == 0 && ii == 0)
        {
            assert(val == "love_chen");
        }
        if (i == 0 && ii == 1)
        {
            assert(val == "love_hui");
        }
        if (i == 1 && ii == 0)
        {
            assert(val == "love_chen2");
        }
        if (i == 1 && ii == 1)
        {
            assert(val == "love_hui2");
        }
    }
}
cout << "TEST 2 PASS" << endl;

    cout << "\nTEST 3 WRITE JSON" << endl;
    // write
    TinyJson wjson;
    wjson["name"].Set("liergou");
    wjson["age"].Set(26);
    wjson["handsome"].Set(true);

    TinyJson subjson;
    subjson["love1"].Set("book");
    subjson["love2"].Set(666);

    TinyJson subjson2;
    subjson2["love1"].Set("book2");
    subjson2["love2"].Set(6662);

    wjson["data"].Set(subjson);
    wjson["data2"].Set(subjson2);

    string str = wjson.WriteJson();
    cout << "json string: \r\n" << endl;
    cout << str << endl;


}


int main(int argc, char *argv[])
{


#ifdef DEBUG
    //testmysql();
    testLogin();
    //    testRole();
    //    testDept();
    testJson();
#endif


    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
