#ifndef STORAGE_H
#define STORAGE_H
#include "BaseDao.h"
#include <map>
#include<list>

using namespace std;

class  StorageDao:protected BaseDao{

public:
    StorageDao(){

    }
    ~StorageDao(){
        delete connectPool;
    }


public:


    bool addStorage(string sn,string name,string contact,string phone,string desc,int status,string address,string add_time);
    bool deleteStorage(string sn="");
    bool deleteStorageById(int id);
    bool modifyStorage(int id,string sn,string name,string contact,string phone,string desc,int status,string address,string add_time);
    map<string,string> getStorageById(int id);
    list<map<string,string>> selectStorages(string sn="",string name="",string address="",string phone="",int status=0,string add_time\
                                            ="",int pageSize=3,int currentPage=1);




};


#endif // STORAGE_H
