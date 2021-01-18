#include "mainwindow.h"
//#include "./ui_mainwindow.h"
#include<mainwindowui.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),behindThread(new BehindServerThread)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    connect(this->ui->pushButton,SIGNAL(clicked()),this,SLOT(click_button()));
     connect(this->ui->pushButton,&QPushButton::clicked,this,&MainWindow::click_button);
}

MainWindow::~MainWindow()
{
    delete ui;
}

