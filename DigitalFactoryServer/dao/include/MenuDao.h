#ifndef MENUDAO_H
#define MENUDAO_H
#include "BaseDao.h"
#include <map>
#include<list>

using namespace std;

class  MenuDao:protected BaseDao{

public:
    MenuDao(){

    }
    ~MenuDao(){
        delete connectPool;
    }


public:

    bool addMenu(string menuname,string url,string icon,int pid,int is_parent);
    bool deleteMenu(string menuname);
    bool deleteMenuById(int id);
    bool modifyMenu(int id,string menuname,string url,string icon,int pid,int is_parent);
    map<string,string> getMenuById(int id);
    list<map<string,string>> selectMenus(string menuname,string url,
                                         int pageSize=3,int currentPage=2);
};


#endif // MENUDAO_H
