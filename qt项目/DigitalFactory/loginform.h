#ifndef LOGINFORM_H
#define LOGINFORM_H
#include "ui_loginform.h"
#include <QBitmap>
//using namespace Ui;

class LoginForm:public QDialog{

public:
    LoginForm():ui(new Ui::LoginDialogUi){
        this->ui->setupUi(this);
        this->setFixedSize(this->width(), this->height());
        //        this->setLayout(this->ui->gridLayout);
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
    }
    ~LoginForm(){
        delete ui;
    }



private:
    Ui::LoginDialogUi * ui;

};




#endif // LOGINWIDGET_H
