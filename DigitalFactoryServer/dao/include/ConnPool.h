#ifndef CONNECTPOOL_H
#define CONNECTPOOL_H

#include "mysql.h"
#include <iostream>

#include <QString>
#include <fstream> //文件
#include <sstream>

//#include "regex.hpp" //正则
#include <regex>   //正则
#include <iostream>
#include <map>
#include <list>
#include <mutex>


using namespace  std;

class ConnPool{
public :
    ConnPool();
    ~ConnPool();

public:

    void loadDbConfig();

    MYSQL  createOneConnect();
    bool initConns(int maxConnectSize=10);

    bool closeConn();

    static ConnPool * getInstance();
    MYSQL  getConnect();



protected:
    static std::map<std::string,std::string> dbMap;
//    list<MYSQL> connList;
    MYSQL mysqlconn;
    bool successConn=false;
    static  ConnPool * instance;

    static mutex mutexobj;
};
#endif // CONNECTPOOL_H
