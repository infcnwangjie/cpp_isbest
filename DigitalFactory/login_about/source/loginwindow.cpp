#include "loginwindow.h"
#include "login_window_ui.h"
#include "login_form_ui.h"
#include <QBitmap>
#include <QPainter>
#include <QDesktopWidget>
#include <QPushButton>
using namespace Ui;


LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent), ui(new LoginWindowUi),loginLayout(new QVBoxLayout)
{


    this->loginDialog=new LoginForm(this);
//    this->setWindowTitle("登录");
    this->setWindowIcon(QIcon(":/resource/images/xiaoren.png"));


    ui->setupUi(this);
//    this->showNormal();
//    this->setWindowFlags(this->windowFlags() &~ Qt::WindowMaximizeButtonHint);//禁止最大和最小化

    loginDialog->setStyleSheet ("background-color: rgb(255, 255, 255);");
    loginDialog->show();

    loginLayout->addWidget(loginDialog);
    loginLayout->setAlignment(Qt::AlignCenter);
    this->centralWidget()->setLayout(loginLayout);
//    QObject::connect(&this->processcore,&ImgProcessCore::finish,&this->afterProcessSlot,&AfterProcessSlot::receiveMsg);
    QObject::connect(this->loginDialog->ui->loginButton, &QPushButton::clicked,this->loginDialog, &LoginForm::onlogin);


}

void LoginWindow::paintEvent(QPaintEvent *event){

    QPainter p(this);
    //    p.drawRoundedRect(0, 0, width() - 1, height() - 1, 20, 20);
    p.drawPixmap(rect(),QPixmap(":/resource/images/loginbg.png"));
}

LoginWindow::~LoginWindow()
{
    delete ui;
    delete loginDialog;
    delete loginLayout;
    //    delete loginFormMdiSubWindow;
    //    delete mdiArea;
    //    delete loginUi;
}

