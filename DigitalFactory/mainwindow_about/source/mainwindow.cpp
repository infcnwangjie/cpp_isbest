#include "mainwindow.h"
#include "mainwindow_ui.h"
//#include "login_form_ui.h"
#include <QBitmap>
#include <QPainter>
#include <QDesktopWidget>
using namespace Ui;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new MainWindowUi)
{

        this->setWindowTitle("闪亮");
    this->setWindowIcon(QIcon(":/resource/images/xiaoren.png"));


    ui->setupUi(this);
    //    this->showNormal();
    //    this->setWindowFlags(this->windowFlags() &~ Qt::WindowMaximizeButtonHint);//禁止最大和最小化

    //    loginDialog->setStyleSheet ("background-color: rgb(255, 255, 255);");
    //    loginDialog->show();

    //    loginLayout->addWidget(loginDialog);
    //    loginLayout->setAlignment(Qt::AlignCenter);
    //    this->centralWidget()->setLayout(loginLayout);


}

void MainWindow::paintEvent(QPaintEvent *event){

//    QPainter p(this);
    //    p.drawRoundedRect(0, 0, width() - 1, height() - 1, 20, 20);
//    p.drawPixmap(rect(),QPixmap(":/resource/images/loginbg.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
    //    delete loginDialog;
    //    delete loginLayout;
    //    delete loginFormMdiSubWindow;
    //    delete mdiArea;
    //    delete loginUi;
}

