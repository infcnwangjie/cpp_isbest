#include "loginwindow.h"

//#define DEBUG 1      //开启测试

#include <QApplication>
#include <iostream>
#include<string>
using namespace  std;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    LoginWindow w;
    w.setWindowTitle("智慧工厂");
    w.show();


    return a.exec();
}
