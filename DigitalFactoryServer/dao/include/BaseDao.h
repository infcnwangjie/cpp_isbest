#ifndef BASEDAO_H
#define BASEDAO_H
#include "ConnPool.h"
#include <map>
#include<list>

using namespace std;

class  BaseDao{

public:
    BaseDao(){
        conn=mysql_init((MYSQL*) 0);

//                fetchConn();
    }
    ~BaseDao(){
       mysql_close(conn);
    }


public:
    bool  sql_connect();

    bool add(string sql);
    bool deleteDatas(string sql);
    bool modify(string sql);
    map<string,string> getOne(string sql);
    list<map<string,string>> query(string sql);

    static mutex mutexobj;
    MYSQL * conn;
//    static ConnPool  * connectPool;



};

#endif // LOGINDAO_H


