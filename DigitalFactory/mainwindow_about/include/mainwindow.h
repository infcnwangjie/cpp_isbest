#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMdiArea>
#include <QMdiSubWindow>
#include <QVBoxLayout>
//#include "loginform.h"
#include "tinyjson.hpp"
#include <cassert>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowUi;
             class MainWindowNewUi;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

//private:
//    LoginForm  * loginDialog;

public:
    void paintEvent(QPaintEvent *event);

    void currentuserinfo();//当前用户信息

private:
    Ui::MainWindowUi *ui;
//    QVBoxLayout *loginLayout;
//    QMdiArea * mdiArea;
//    QMdiSubWindow *loginFormMdiSubWindow;
//    Ui::LoginDialog * loginUi;
};
#endif // MAINWINDOW_H
