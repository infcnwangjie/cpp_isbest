#ifndef LOGINFORM_H
#define LOGINFORM_H
#include "login_form_ui.h"
#include "mainwindow.h"
#include <QBitmap>
//using namespace Ui;

class MainWindow;//extern 关键字 只能用于变量和方法
class LoginWindow;

class LoginForm:public QDialog{
    Q_OBJECT
public:
    LoginForm( LoginWindow *loginWindow):ui(new Ui::LoginDialogUi){
        this->ui->setupUi(this);
        this->setFixedSize(this->width(), this->height());
        //        this->setLayout(this->ui->gridLayout);
        this->loginWindow=loginWindow;

        //设置关于窗体为圆角
        setWindowFlags(Qt::FramelessWindowHint);

        QBitmap bmp(this->size());
        //填充颜色
        bmp.fill(Qt::white);

        QPainter p(&bmp);

        p.setPen(Qt::NoPen);

        p.setBrush(Qt::black);

        p.drawRoundedRect(bmp.rect(), 20, 20);

        setMask(bmp);

        //        connect(ui->loginButton, SIGNAL(QPushButton::clicked), this, SLOT(this->onlogin));

        //          QObject::connect(&this->processcore,&ImgProcessCore::finish,&this->afterProcessSlot,&AfterProcessSlot::receiveMsg);
    }

    ~LoginForm(){
        delete ui;
        //        delete LoginWindow;
    }
public:
    Ui::LoginDialogUi * ui;
public slots:

    void onlogin();//点击登录按钮


private:

    MainWindow * mainWindow;//主窗口
    LoginWindow *loginWindow;//登录窗口
    friend class MainWindow;

};
#endif // LOGINWIDGET_H
