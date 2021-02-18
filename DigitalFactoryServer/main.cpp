#include "mainwindow.h"

#include <QApplication>

#include <iostream>
#include<string>
using namespace  std;

#include "mysql.h"

#define DEBUG 1

#ifdef DEBUG
using namespace std;

#endif



int main(int argc, char *argv[])
{



    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
