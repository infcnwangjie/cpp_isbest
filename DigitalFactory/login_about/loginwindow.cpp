#include "loginwindow.h"
#include "login_window_ui.h"
#include "login_form_ui.h"
#include <QBitmap>
#include <QPainter>
#include <QDesktopWidget>
#include <QPushButton>
#include <QMessageBox>
using namespace Ui;


LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent), ui(new LoginWindowUi),loginLayout(new QVBoxLayout)
{


    this->loginDialog=new LoginForm(this);
    //    this->setWindowTitle("登录");
    this->setWindowIcon(QIcon(":/resource/images/xiaoren.png"));


    ui->setupUi(this);
    //        this->showNormal();
    this->setWindowFlags(this->windowFlags() &~ Qt::WindowMaximizeButtonHint);//禁止最大和最小化

    loginDialog->setStyleSheet ("background-color: rgb(255, 255, 255);");
    loginDialog->show();

    loginLayout->addWidget(loginDialog);
    loginLayout->setAlignment(Qt::AlignCenter);
    this->centralWidget()->setLayout(loginLayout);
    //    QObject::connect(&this->processcore,&ImgProcessCore::finish,&this->afterProcessSlot,&AfterProcessSlot::receiveMsg);
    QObject::connect(this->loginDialog->ui->loginButton, &QPushButton::clicked,this, &LoginWindow::onlogin);

    loginService=new LoginService();

    //    initSocket();//初始化socket
    //    connectServer();//连接服务器

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

void LoginWindow::initSocket(){
    m_pTcpSocket=new QTcpSocket(nullptr);
    //    connect(m_pTcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),
    //            this,SLOT(displayError(QAbstractSocket::SocketError)));   //发生错误时执行displayError函数
}

void LoginWindow::connectServer(){
    this->m_pTcpSocket->connectToHost(QHostAddress::LocalHost,6666,QTcpSocket::ReadWrite);

    connect(this->m_pTcpSocket,SIGNAL(connected()),this,SLOT(connected()));//意义不大，告知 连接成功了
    connect(this->m_pTcpSocket,SIGNAL(readyRead()),this,SLOT(fetchLoginMessageFromServer()));
}


/*****************
 * 点击登录
 *
*/
void LoginWindow::onlogin(){


    auto user= this->loginDialog->ui->idEdit->text();

    auto password=this->loginDialog->ui->passwdEdit->text();

    if(user.isEmpty() ||password.isEmpty()){
        QMessageBox::warning(this,"错误提示","请输入用户名密码");
        return;
    }

    //    TinyJson loginJson;
    //    loginJson["method"].Set("login");

    //    TinyJson loginData;
    //    loginData["user"].Set(user.toStdString());
    //    loginData["password"].Set(password.toStdString());



    //    loginJson["data"].Set(loginData);


    //    string str = loginJson.WriteJson();

    //    qDebug() << QString::fromStdString(str) << endl;


    //    QString jsonStr(str.data());
    //    QByteArray jsonbytes;
    //    jsonbytes.append(jsonStr);

    //    if(this->m_pTcpSocket==nullptr || !(this->m_pTcpSocket->isReadable() || this->m_pTcpSocket->isWritable())){
    //        if(this->m_pTcpSocket!=nullptr){
    //            this->m_pTcpSocket->close();
    //        }
    //        connectServer();

    //    }

    //    this->m_pTcpSocket->write(jsonbytes);
    //    this->m_pTcpSocket->flush();

    loginclick=true;
    bool loginstatus=loginService->login(user,password);


    if(loginstatus){
        this->mainWindow=new MainWindow;
        this->mainWindow->show();
        this->hide();
    }



}

void LoginWindow::connected(){
    //    qDebug()<<"连接成功!";
    //    connectStatus=true;
    //    QString string = "Hello";
    //    QByteArray array;
    //    array.append(string);
    //    this->m_pTcpSocket->write(array);
    //    connect(this->m_pTcpSocket,SIGNAL(readyRead()),this,SLOT(readyread()));
    //    this->m_pTcpSocket->waitForReadyRead();
    //    readwriteStatus=true;
}

void LoginWindow::fetchLoginMessageFromServer(){

    //    if(loginclick==true && this->m_pTcpSocket->bytesAvailable()){
    //        qDebug() << loginclick;
    //        QByteArray arr=this->m_pTcpSocket->readAll();
    //        qDebug() << arr;  //读取socket中的数据并打印
    //        QString jsonInfo(arr);

    //        TinyJson json;
    //        json.ReadJson(jsonInfo.toStdString());

    //        string loginstatus=json.Get<string>("authorized");
    //        string name=json.Get<string>("name");
    //        string password=json.Get<string>("password");
    //        xarray menus=json.Get<xarray>("menus");
    //        xarray roles=json.Get<xarray>("roles");


    //        if(loginstatus=="true"){
    //            this->m_pTcpSocket->close();


    //            this->mainWindow=new MainWindow;
    //            this->mainWindow->show();
    //            this->hide();

    //        }else if(loginstatus=="false"){
    //            QMessageBox::warning(this,"错误提示","用户或密码错误");
    //            loginclick=false;

    //        }




}
