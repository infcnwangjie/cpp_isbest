#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMdiArea>
#include <QMdiSubWindow>
#include <QVBoxLayout>
//#include "loginform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowUi; }
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

private:
    Ui::MainWindowUi *ui;
//    QVBoxLayout *loginLayout;
//    QMdiArea * mdiArea;
//    QMdiSubWindow *loginFormMdiSubWindow;
//    Ui::LoginDialog * loginUi;
};
#endif // MAINWINDOW_H
