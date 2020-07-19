#include "mainwindow.h"

//#define DEBUG 1      //开启测试
#include <QApplication>
#include <meanshift.h>
#include <iostream>
#include<string>
#include "postsqlsdk.h"

using namespace  std;



int main(int argc, char *argv[])
{



    #ifdef DEBUG
        PostgreSqlSdk p;
        p.test_sql();
        cout<<"执行debug"<<endl;
    #endif




    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("智慧工厂");
    w.show();



    return a.exec();
}
