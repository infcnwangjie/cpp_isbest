#include "BehindServerThread.h"
#include <QWidget>
#include <QMessageBox>
#include <UserDao.h>




BehindServerThread::~BehindServerThread()
{



}


void BehindServerThread::run(){
    this->task(this->jsonInfo);
}

mutex mutexobj;

