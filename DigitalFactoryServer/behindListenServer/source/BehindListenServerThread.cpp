#include "BehindServerThread.h"
#include <QWidget>
#include <QMessageBox>


BehindServerThread::BehindServerThread()
{
    //初始化
    TCP_server = new QTcpServer(this);
    TCP_connectSocket = nullptr;
    TCP_server->listen(QHostAddress::Any,6666);
    connect(this->TCP_server,SIGNAL(newConnection()),this,SLOT(newConnection()));



}

BehindServerThread::~BehindServerThread()
{

    if(TCP_connectSocket != nullptr){
        TCP_connectSocket->close(); //关闭客户端
        TCP_connectSocket->deleteLater();
    }

}




