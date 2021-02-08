#ifndef BEHINDSERVERTHREAD_H
#define BEHINDSERVERTHREAD_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDateTime>
#include <QThread>
#include <QMessageBox>
#include<iostream>
#include <mutex>
#include <future>
#include "tinyjson.hpp"
#include <cassert>
#include <mainWindow.h>
using namespace tiny;
using namespace std;


extern string  processhandle(string  jsonInfo);



class BehindServerThread:public QThread
{
    Q_OBJECT
public:
    BehindServerThread( string jsonstr):jsonInfo(jsonstr),task(processhandle){
    };
    ~BehindServerThread();


private:

     string jsonInfo;
     packaged_task<string(string)> task;
     friend class MainWindow;



public:

    void run();

};


#endif // BEHINDSERVERTHREAD_H


