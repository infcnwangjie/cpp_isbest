#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include<QMdiArea>
#include <QMdiSubWindow>
#include <QVBoxLayout>
#include "loginform.h"
//#include "mainwindow.h"
#include "loginservice.h"

#include <QTcpServer>
#include <QTcpSocket>

#include "tinyjson.hpp"
#include <cassert>
using namespace std;
using namespace tiny;

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindowUi; }
QT_END_NAMESPACE

/****
处理登录
**/

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
    MainWindow * mainWindow;//主窗口
    LoginWindow *loginWindow;//登录窗口
    friend class MainWindow;

    LoginService * loginService;
    //private slots:
private  slots:
    void initSocket();
    void connectServer();
    void onlogin();//点击登录
    void connected();//连接成功后触发
    void fetchLoginMessageFromServer();//可读取的时候调用

private :
    bool connectStatus=false;//连接状态
    bool readwriteStatus=false;//写入状态
    bool loginclick=false;


};
#endif // MAINWINDOW_H
