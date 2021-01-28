#ifndef BASEDAO_H
#define BASEDAO_H
#include "ConnPool.h"
#include <map>
#include<list>

using namespace std;

class  BaseDao{

public:
    BaseDao(){

    }
    ~BaseDao(){
        delete connectPool;
    }


public:
    virtual MYSQL fetchConn();

    bool add(string sql);
    bool deleteDatas(string sql);
    bool modify(string sql);
    map<string,string> getOne(string sql);
    list<map<string,string>> query(string sql);

protected:
    ConnPool  * connectPool;
};

#endif // LOGINDAO_H


