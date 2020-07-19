#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QBitmap>
#include <QPainter>
#include <QDesktopWidget>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),loginDialog(new LoginForm),loginLayout(new QVBoxLayout)
{

//    this->setWindowTitle("登录");
    this->setWindowIcon(QIcon(":/resource/images/xiaoren.png"));


    ui->setupUi(this);
    this->showNormal();
    this->setWindowFlags(this->windowFlags() &~ Qt::WindowMaximizeButtonHint);//禁止最大和最小化

    loginDialog->setStyleSheet ("background-color: rgb(255, 255, 255);");
    loginDialog->show();

    loginLayout->addWidget(loginDialog);
    loginLayout->setAlignment(Qt::AlignCenter);
    this->centralWidget()->setLayout(loginLayout);

    //    mdiArea->addSubWindow(loginDialog);



    //     QDesktopWidget *desktop=QApplication::desktop();
    //     this->resize(desktop->width()*3/4,desktop->height()*3/4);





}

void MainWindow::paintEvent(QPaintEvent *event){

    QPainter p(this);
    //    p.drawRoundedRect(0, 0, width() - 1, height() - 1, 20, 20);
    p.drawPixmap(rect(),QPixmap(":/resource/images/loginbg.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete loginDialog;
    delete loginLayout;
    //    delete loginFormMdiSubWindow;
    //    delete mdiArea;
    //    delete loginUi;
}

