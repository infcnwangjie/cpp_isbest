#include "BehindServerThread.h"
#include <QWidget>
#include <QMessageBox>


BehindServerThread::BehindServerThread()
{
    //初始化
    TCP_server = new QTcpServer(this);
    TCP_connectSocket = nullptr;
    TCP_server->listen(QHostAddress::Any,6666);
    //connect(this->TCP_server,SIGNAL(newConnection()),this,SLOT(newConnection()));
     connect(this->TCP_server,&QTcpServer::newConnection,this,&BehindServerThread::newConnection);



}

BehindServerThread::~BehindServerThread()
{

    if(TCP_connectSocket != nullptr){
        TCP_connectSocket->close(); //关闭客户端
        TCP_connectSocket->deleteLater();
    }

}

void BehindServerThread::newConnection(){
    this->TCP_connectSocket=this->TCP_server->nextPendingConnection();
    qDebug()<<"有新的连接";
    connect(this->TCP_connectSocket,SIGNAL(readyRead()),this,SLOT(ReceiveData()));
}
void BehindServerThread::ReceiveData(){
     qDebug()<<"接收到客户端的发送的信息";
    QByteArray bytearryinfo=this->TCP_connectSocket->readAll();

    QString info=bytearryinfo;
    std::cout<<info.toStdString();


    this->TCP_connectSocket->write(" i have receive from client");
}

