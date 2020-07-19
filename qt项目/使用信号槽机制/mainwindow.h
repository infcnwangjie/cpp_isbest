#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "first_widget.h"
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Ui_Dialog * newWindow;


public:
    MainWindow(QWidget *parent = nullptr);


    ~MainWindow();

 public slots:
    void open_window();



private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
