#include "StorageDao.h"


bool StorageDao::addStorage(string sn, string name, string contact, string phone, string desc, int status, string address, string add_time){


    stringstream sqlBuilder;
    sqlBuilder<<"insert into storage(sn,name,contact,phone,desc,status,address,add_time) values"<<"('"<<sn<<"','"
             <<name<<"','"<<contact<<"','"<<phone<<"','"<<desc<<"',"<<status<<",'"<<address<<"','"<<add_time<<"')";

    string sql=sqlBuilder.str();

    return add(sql);
}
bool StorageDao::deleteStorage(string sn){


    stringstream sqlBuilder;
    sqlBuilder<<"delete from  storage  where sn='"<<sn<<"'";

    string sql=sqlBuilder.str();

    return deleteDatas(sql);
}
bool StorageDao::deleteStorageById(int id){
    MYSQL conn=fetchConn();

    stringstream sqlBuilder;
    sqlBuilder<<"delete from  storage where id="<<id;

    string sql=sqlBuilder.str();

    return deleteDatas(sql);
}
bool StorageDao::modifyStorage(int id, string sn, string name, string contact, string phone, string desc, int status, string address, string add_time){

    stringstream sqlBuilder;
    sqlBuilder<<"update storage set sn='"<<sn<<"',name='"<<name<<"',contact='"<<contact<<"',phone='"<<phone<<"',desc='"<<desc<<"',status="\
             <<status<<",address='"<<address<<"',add_time='"<<add_time<<"'"
            <<" where id="<<id;

    string sql=sqlBuilder.str();

    return modify(sql);
}
map<string,string> StorageDao::getStorageById(int id){
    map<string,string> storeInfo;


    stringstream sqlBuilder;
    sqlBuilder<<"select * from storage  where id="<<id;

    string sql=sqlBuilder.str();

    return getOne(sql);
}
list<map<string,string>> StorageDao::selectStorages(string sn,string name,string address,string phone,int status,string add_time\
                                                    ,int pageSize,int currentPage){
    list<map<string,string>> storageInfos;
    stringstream sqlBuilder;
    sqlBuilder<<"select * from storage";
    if(sn!="" or name!="" or address!="" or phone !="" or add_time!="" ){
        sqlBuilder<<" where ";
        if(name!=""){
            sqlBuilder<<"  name='"<<name<<"'";
        }

        if(sn!=""){
            sqlBuilder<<"  sn='"<<sn<<"'";
        }
        if(address!=""){
            sqlBuilder<<"  address='"<<address<<"'";
        }
        if(phone!=""){
            sqlBuilder<<"  phone='"<<phone<<"'";
        }
        if(status!=0){
            sqlBuilder<<"  status="<<status;
        }
        if(add_time!=""){
            sqlBuilder<<"  add_time='"<<add_time<<"'";
        }

    }

    sqlBuilder<<" limit "<<(currentPage-1)*pageSize<<","<<pageSize;

    string sql=sqlBuilder.str();
    return query(sql);

}






