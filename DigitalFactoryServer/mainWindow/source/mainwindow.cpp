#include "mainwindow.h"
//#include "./ui_mainwindow.h"
#include<mainwindowui.h>
#include "tinyjson.hpp"
#include <cassert>
using namespace std;
using namespace tiny;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //    connect(this->ui->pushButton,SIGNAL(clicked()),this,SLOT(click_button()));
    connect(this->ui->pushButton,&QPushButton::clicked,this,&MainWindow::click_button);

    initServerSocket();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::initServerSocket(){
    TCP_server = new QTcpServer(this);
    //    TCP_connectSocket = nullptr;
    TCP_server->listen(QHostAddress::Any,6666);
    connect(this->TCP_server,&QTcpServer::newConnection,this,[=](){


        //与客户端连接套接字
        QTcpSocket *itemSocket=this->TCP_server->nextPendingConnection();
        if(itemSocket!=nullptr){

            qDebug()<<"有新的连接";
            //            BehindServerThread thread(itemSocket);
            connect(itemSocket,&QTcpSocket::readyRead,this,[=](){
                MainWindow::ReceiveData(itemSocket);
                //                thread.start();

            } );



        }else{
            qDebug()<<"套接字异常";
        }



    });

    //
}


void MainWindow::ReceiveData(QTcpSocket *itemSocket){

    //改成支持线程池

//    BehindServerThread thread(itemSocket);
//    itemSocket->moveToThread(&thread);
//    thread.start();
//    thread.wait();

        QByteArray bytearryinfo=itemSocket->readAll();

        QString info=bytearryinfo;
        std::cout<<info.toStdString();


        TinyJson json;
        json.ReadJson(info.toStdString());

        string method=json.Get<string>("method");


        if(method=="login"){
            //loginstatus
            qDebug()<<"login";
            qDebug()<<info;

            TinyJson loginJson;
            loginJson["loginstatus"].Set("ok");


            string jsonstr = loginJson.WriteJson();
            //        TCP_connectSocket->write(QString::fromStdString(jsonstr));



            QString jsonStr=QString::fromStdString(jsonstr);
            QByteArray jsonbytes;
            jsonbytes.append(jsonStr);
            qDebug()<<jsonStr;
            itemSocket->write(jsonbytes);
                    itemSocket->close();
            //        delete itemSocket;

        }




}



void MainWindow::click_button(){
    // connect(this->TCP_server,&QTcpServer::newConnection,this,&MainWindow::newConnection);
    QMessageBox::information(this,"提示","点击登录");

}
