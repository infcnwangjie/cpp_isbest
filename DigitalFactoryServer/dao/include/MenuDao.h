#ifndef MENUDAO_H
#define MENUDAO_H
#include "ConnPool.h"
#include <map>
#include<list>

using namespace std;

class  MenuDao{

public:
    MenuDao(){

    }
    ~MenuDao(){
        delete connectPool;
    }


public:
    MYSQL fetchConn();
    bool addMenu(string menuname,string url,string icon,int pid,int is_parent);
    bool deleteMenu(string menuname);
    bool deleteMenuById(int id);
    bool modifyMenu(int id,string menuname,string url,string icon,int pid,int is_parent);
    map<string,string> getMenuById(int id);
    list<map<string,string>> selectMenus(string menuname,string url,
                                         int pageSize=3,int currentPage=2);

private:
    ConnPool  * connectPool;


};


#endif // MENUDAO_H
