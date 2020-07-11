#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H
#include "ui_login.h"
//using namespace Ui;

class LoginWidget:public QWidget{

public:
    LoginWidget():ui(new Ui::Ui_Login){
        this->ui->setupUi(this);
    }
    ~LoginWidget(){
        delete ui;
    }
public:
    void paintEvent(QPaintEvent *event);

private:
    Ui::Ui_Login * ui;

};




#endif // LOGINWIDGET_H
