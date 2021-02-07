#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <BehindServerThread.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void click_button();
private:
    QTcpServer *TCP_server; //QTcpServer服务器
//    QTcpSocket *itemSocket; //与客户端连接套接字


//    BehindServerThread * behindThread;
    Ui::MainWindow *ui;


private slots:
    void initServerSocket();

    void ReceiveData(QTcpSocket *itemSocket);
};
#endif // MAINWINDOW_H
