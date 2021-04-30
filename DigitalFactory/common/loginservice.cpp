#include "loginservice.h"

#include <sstream>
#include<iostream>
#include <QTimer>
#include <QEventLoop>
#include "result.h"

LoginService::LoginService()
{

    //    connect(&oNetAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
}


bool LoginService::login(QString userName, QString password){




    QByteArray postArray;
    postArray.append("name="+userName);

    postArray.append("&password="+password);

    QNetworkRequest request;

    //    oNetRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");

    request.setHeader(QNetworkRequest::ContentLengthHeader,postArray.size());

    request.setUrl(QUrl("http://localhost:8080/user/restlogin"));

    QNetworkReply* reply = oNetAccessManager.post(request, postArray);

    QTimer timer;
    timer.setInterval(10000);  // 设置超时时间 10 秒
    timer.setSingleShot(true);  // 单次触发

    QEventLoop eventLoop;
    connect(&timer, &QTimer::timeout, &eventLoop, &QEventLoop::quit);
    connect(&oNetAccessManager, &QNetworkAccessManager::finished, &eventLoop, &QEventLoop::quit);
    timer.start();//启动定时器
    eventLoop.exec();//启动事件循环

    bool loginStatus=false;

    if(timer.isActive()){//处理响应，定时器激活状态
        timer.stop();//停止定时器
        if(reply->error() != QNetworkReply::NoError){//http请求出错，进行错误处理
            qDebug() << "http请求出错 : " << reply->errorString();
            reply->deleteLater();
            loginStatus=false;
        }
        else{
            // http - 响应状态码
            int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
            qDebug()<<"服务器返回的Code : "<<statusCode;
            if(statusCode==200){//http请求响应正常
                QByteArray replyContent = reply->readAll();

                QJsonObject replyJson=QJsonObject(QJsonDocument::fromJson(replyContent).object());

                if (replyJson.contains("status")) {
                    QString loginstatus = replyJson.value("status").toString();
                    //ui->plainTextEdit->appendPlainText(tr("\n")+succ_msg);

                    loginStatus=loginstatus=="ok"?true:false;
                }

            }
            else{
                reply->deleteLater();
                loginStatus=false;

            }
        }
    }
    else{//超时处理
        disconnect(&oNetAccessManager, &QNetworkAccessManager::finished, &eventLoop, &QEventLoop::quit);
        reply->abort();
        qDebug() << "http请求超时 ";
        loginStatus=false;

    }
    return loginStatus;








}
