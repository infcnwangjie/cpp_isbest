#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include<QMdiArea>
#include <QMdiSubWindow>
#include <QVBoxLayout>
#include "loginform.h"
//#include "mainwindow.h"

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
};
#endif // MAINWINDOW_H
