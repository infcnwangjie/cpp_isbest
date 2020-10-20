#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QBitmap>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),loginWidget(new LoginWidget)
{
    ui->setupUi(this);
    this->setWindowTitle("登录");
    this->setWindowIcon(QIcon(":/resource/images/xiaoren.png"));


    QRect windowRect=this->rect();
//    QPoint topLeft=windowRect.topLeft();
//    QPoint topRigtht=windowRect.topRight();

//    QPoint bottomLeft=windowRect.bottomLeft();
//    QPoint bottomRigth=windowRect.bottomRight();

//    int windowWidth=topRigtht.x()-topLeft.x();

//    int windowHeight=bottomLeft.y()-topLeft.y();

//    printf("%d ,%d",windowWidth,windowHeight);



//    this->loginWidget->move(windowRect.width()/2,windowRect.height()/2);

//    this->loginUi->setupUi(this->loginWidget);
    this->setCentralWidget(this->loginWidget);
    this->loginWidget->show();


    //设置关于窗体为圆角
//    setWindowFlags(Qt::FramelessWindowHint);

//    QBitmap bmp(this->size());

//    bmp.fill();

//    QPainter p(&bmp);

//    p.setPen(Qt::NoPen);

//    p.setBrush(Qt::black);

//    p.drawRoundedRect(bmp.rect(), 20, 20);

//    setMask(bmp);

}

void MainWindow::paintEvent(QPaintEvent *event){

    QPainter p(this);
//    p.drawRoundedRect(0, 0, width() - 1, height() - 1, 20, 20);
    p.drawPixmap(rect(),QPixmap(":/resource/images/loginbg.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete loginWidget;
//    delete loginUi;
}

