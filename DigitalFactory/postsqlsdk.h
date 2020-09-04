#ifndef POSTSQLSDK_H
#define POSTSQLSDK_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QString>
#include <fstream> //文件
#include <sstream>

//#include "regex.hpp" //正则
#include <regex>   //正则
#include <iostream>
#include <map>

/**********************************************************************************
 *作者：王杰
 *功能：封装QT_Postgresql常用API，作为基础dao
 *注：  类构造函数从应用程序目录中找到dbconfig.txt文件，依次从该文件读取数据库连接信息，用来初
 * 始化数据库连接信息
 ***********************************************************************************/

class PostgreSqlSdk{
public:
    /*****************
    *构造函数从dbconfig.txt加载数据库连接信息
    */
    PostgreSqlSdk(){
        initDbInfoFromFile();
    }
    ~PostgreSqlSdk(){
        //如果数据库还连接中退出前需要先关闭
        if(db.isOpen()){
            db.close();
        }

    }

    bool  open();


    void test_sql(){
        bool ok=open();

        if(ok){
            QSqlQuery query;
            query.exec("Select * from \"test\"");
            while (query.next())
            {
                QString id = query.value(1).toString();
                qDebug() << id;
            }
        }else{
            QSqlError lastError = db.lastError();
            QString message = "数据库打开失败（创建测试项）！错误原因："+lastError.driverText();
            qDebug()<<message;

        }


    }

private:
    std::map<std::string,std::string> dbMap;
    QSqlDatabase db;
    void  initDbInfoFromFile();

};


#endif // POSTSQLSDK_H
