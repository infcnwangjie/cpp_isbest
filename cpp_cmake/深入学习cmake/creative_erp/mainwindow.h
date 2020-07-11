#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "loginwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    LoginWidget  * loginWidget;

public:
    void paintEvent(QPaintEvent *event);
private:
    Ui::MainWindow *ui;
    Ui::Ui_Login * loginUi;
};
#endif // MAINWINDOW_H
