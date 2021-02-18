#include "mainwindow.h"
//#include "./ui_mainwindow.h"
#include<mainwindowui.h>
#include <UserService.h>
#include "tinyjson.hpp"
//#include <cassert>
using namespace std;
using namespace tiny;


//extern std::string myint_to_string(int data);
//extern int mystring_to_int(std::string data);

string  processhandle(string  jsonInfo){
    //    unique_lock<mutex> lock(mutexobj);
    TinyJson json;
    json.ReadJson(jsonInfo);
    qDebug()<<QString::fromStdString(jsonInfo);
    string method=json.Get<string>("method");

    if(method=="login"){

        xobject data = json.Get<xobject>("data");
        if(data.Count()==0){
           return "";
        }else{
            data.Enter(0);
            string user = data.Get<string>("user");
            string password = data.Get<string>("password");
            UserService userService;
            string  result=userService.login(jsonInfo);
          return result;


        }



    }
    return "";
}


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
            //            clientSockets.push_back(itemSocket);

            connect(itemSocket,&QTcpSocket::readyRead,this,[=](){
                MainWindow::ReceiveData(itemSocket);
            } );
            //            itemSocket->waitForReadyRead();
            //            MainWindow::ReceiveData(itemSocket);



        }else{
            qDebug()<<"套接字异常";
        }



    });

    //
}


void MainWindow::useThread(QTcpSocket *itemSocket){
    QByteArray bytearryinfo=itemSocket->readAll();

    QString info=bytearryinfo;

    if(info.isNull()){
        return;
    }
    std::cout<<info.toStdString();


    TinyJson json;
    json.ReadJson(info.toStdString());

    packaged_task<string(string)> task(processhandle);
    BehindServerThread thread(info.toStdString());
    std::future<string> fu1=thread.task.get_future();
    thread.start();


    //    std::future<string> fu1=task.get_future();
    //    std::thread th(std::move(task), info.toStdString());
    //    th.join();


    QString jsonStr=QString::fromStdString(fu1.get());

//    QString jsonStr=QString::fromStdString(processhandle(info.toStdString()));

    QByteArray jsonbytes;
    jsonbytes.append(jsonStr);
    qDebug()<<jsonStr;

    if(itemSocket==nullptr){
        QMessageBox::warning(this,"错误提示","指针为空");
    }else{
        if(itemSocket->isValid()){
            itemSocket->write(jsonbytes);
            itemSocket->flush();
//            itemSocket->close();
            //        delete itemSocket;
        }

    }


    //    itemSocket->

    //    itemSocket->close();
    //    delete itemSocket;

    //        }
}

void MainWindow::ReceiveData(QTcpSocket *itemSocket){

    //改成支持线程池
    useThread(itemSocket);

    //    qDebug()<<clientSockets.size();

    //    for(int i=0;i<clientSockets.size();i++){
    //        if(clientSockets.at(i)->bytesAvailable()){

    //            useThread(clientSockets.at(i));

    //        }
    //    }



}










void MainWindow::click_button(){
    // connect(this->TCP_server,&QTcpServer::newConnection,this,&MainWindow::newConnection);
    QMessageBox::information(this,"提示","点击登录");

}
