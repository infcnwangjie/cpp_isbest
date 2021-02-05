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
    BehindServerThread();
    ~BehindServerThread();

private:
    QTcpServer *TCP_server; //QTcpServer服务器
    QTcpSocket *TCP_connectSocket; //与客户端连接套接字

//private slots:
private:
    void newConnection();
    void ReceiveData();

public:

    void run(){



        qDebug()<<"run";
//        TCP_server->listen(QHostAddress::Any,6666);
        int i=0;
        while(i++<10000){
//            this->TCP_connectSocket=this->TCP_server->nextPendingConnection();

//            connect(this->TCP_connectSocket,SIGNAL(readyRead()),this,SLOT(ReceiveData()));



        }

    }

};


#endif // BEHINDSERVERTHREAD_H


