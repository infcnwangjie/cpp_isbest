#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include<QMdiArea>
#include <QMdiSubWindow>
#include <QVBoxLayout>
#include "loginform.h"
//#include "mainwindow.h"


#include <QTcpServer>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindowUi; }
QT_END_NAMESPACE






class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

public:
    void paintEvent(QPaintEvent *event);
    //    friend class MainWindow;
private:
    Ui::LoginWindowUi *ui;
    QVBoxLayout *loginLayout;
    LoginForm  * loginDialog;// 登录窗体
    QTcpSocket * m_pTcpSocket;

private slots:
    void connected(){
        qDebug()<<"连接成功!";
        QString string = "Hello";
        QByteArray array;
        array.append(string);
        this->m_pTcpSocket->write(array);

        int i=0;
         connect(this->m_pTcpSocket,SIGNAL(readyRead()),this,SLOT(readyread()));
    }

    void readyread(){
        QByteArray arr=this->m_pTcpSocket->readAll();
        qDebug() << arr;  //读取socket中的数据并打印
    }
};
#endif // MAINWINDOW_H
