#ifndef STORAGE_H
#define STORAGE_H
#include "BaseDao.h"
#include <map>
#include<list>

using namespace std;

class  StorageDao{

public:
    StorageDao(){

    }
    ~StorageDao(){

    }


public:


    string addStorage(string sn,string name,string contact,string phone,string desc,int status,string address,string add_time);
    string deleteStorage(string sn="");
    string deleteStorageById(int id);
    string modifyStorage(int id,string sn,string name,string contact,string phone,string desc,int status,string address,string add_time);
    string getStorageById(int id);
    string selectStorages(string sn="",string name="",string address="",string phone="",int status=0,string add_time\
                                            ="",int pageSize=3,int currentPage=1);




};


#endif // STORAGE_H
