#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDateTime>
#include <QThread>
#include <QMessageBox>
#include<iostream>
using namespace std;

class ThreadPool
{

public:
    ThreadPool();
    ~ThreadPool();

private:

QThread createOneThread();
bool initThreadPool();
QThread fetchOneThread();


private:
 vector<Qthread> threads;

};


#endif // THREADPOOL_H


