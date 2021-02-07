#ifndef BEHINDSERVERTHREAD_H
#define BEHINDSERVERTHREAD_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDateTime>
#include <QThread>
#include <QMessageBox>
#include<iostream>
using namespace std;

class BehindServerThread:public QThread
{
    Q_OBJECT
public:
    BehindServerThread(QTcpSocket *socket):itemSocket(socket){};
    ~BehindServerThread();

private:


   QTcpSocket *itemSocket;


public:

    void run();

};


#endif // BEHINDSERVERTHREAD_H


