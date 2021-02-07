#include "BehindServerThread.h"
#include <QWidget>
#include <QMessageBox>
#include "tinyjson.hpp"
#include <cassert>
using namespace std;
using namespace tiny;


BehindServerThread::~BehindServerThread()
{

    if(itemSocket!=nullptr){
        //    itemSocket->close();
        delete itemSocket;
    }

}


void BehindServerThread::run(){


    QByteArray bytearryinfo=itemSocket->readAll();

    QString info=bytearryinfo;
    std::cout<<info.toStdString();


    TinyJson json;
    json.ReadJson(info.toStdString());
    qDebug()<<info;
    string method=json.Get<string>("method");


    if(method=="login"){
        //loginstatus
        qDebug()<<"login";


        TinyJson loginJson;
        loginJson["loginstatus"].Set("ok");


        string jsonstr = loginJson.WriteJson();
        //        TCP_connectSocket->write(QString::fromStdString(jsonstr));



        QString jsonStr=QString::fromStdString(jsonstr);
        QByteArray jsonbytes;
        jsonbytes.append(jsonStr);
        qDebug()<<jsonStr;
        itemSocket->write(jsonbytes);
    }
}


