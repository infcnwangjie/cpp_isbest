#ifndef MENUDAO_H
#define MENUDAO_H
#include "BaseDao.h"
#include <map>
#include<list>

using namespace std;

class  MenuDao{

public:
    MenuDao(){

    }
    ~MenuDao(){

    }


public:

    string addMenu(string menuname,string url,string icon,int pid,int is_parent);
    string deleteMenu(string menuname);
    string deleteMenuById(int id);
    string modifyMenu(int id,string menuname,string url,string icon,int pid,int is_parent);
    string getMenuById(int id);
    string selectMenus(string menuname,string url,
                       int pageSize=3,int currentPage=2);
};


#endif // MENUDAO_H
