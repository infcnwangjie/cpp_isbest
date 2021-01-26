#ifndef LOGINDAO_H
#define LOGINDAO_H
#include "ConnPool.h"


class  LoginDao{

public:
    LoginDao(){

    }
    ~LoginDao(){

    }


public:
    bool login(string userName,string passWord,string registcode );

private:
    ConnPool  * connectPool;

};

#endif // LOGINDAO_H


