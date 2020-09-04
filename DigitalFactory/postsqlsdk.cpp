#include "postsqlsdk.h"
#include<string>
using namespace std;



/************************************************************************
 * 方法名称 initDbInfoFromFile
 * 用途：加载数据库连接信息
 * 作者：王杰
 * 时间：2020-07-19 周末
 ************************************************************************/
void  PostgreSqlSdk::initDbInfoFromFile(){
    ifstream  db_config("dbconfig.txt",ios::in);
    string temp;

    regex dbInfoRegex("([a-z0-9_]+):(.*)$");
    //        std::regex dbInfoRegex(".*");
    smatch m;

    try {
        while(getline(db_config,temp)){
            bool success=regex_match(temp,m,dbInfoRegex);
            if(success && m.size()>1){
                //                    std::cout<<m[1].str()<<std::endl;
                //                    std::cout<<m[2].str()<<std::endl;
                dbMap.insert(pair<string,string>{m[1].str(),m[2].str()});
            }

        }
    } catch (std::regex_error e) {
        std::cout <<e.what() <<endl<<"code:"<< e.code() << std::endl;
    }
    //        std::map<std::string,std::string>::iterator mapiterator;
    //        for(mapiterator=dbMap.begin();mapiterator!=dbMap.end();mapiterator++){
    //              std::cout<<mapiterator->first<<"="<<mapiterator->second<<std::endl;
    //        }
    db_config.close();

}


/************************************************************************
 * 方法名称 open
 * 用途：打开postgresql数据库连接
 * 作者：王杰
 * 时间：2020-07-19 周末
 ************************************************************************/
bool PostgreSqlSdk::open(){

    db = QSqlDatabase::addDatabase("QPSQL");
    if(dbMap.size()>1){
        db.setHostName(QString::fromStdString(dbMap["databaseip"]));
        db.setDatabaseName(QString::fromStdString(dbMap["databasename"]));
        std::stringstream port(dbMap["databaseport"]);
        int port_int;
        port>>port_int;
        db.setPort(port_int);//5432
        db.setUserName(QString::fromStdString(dbMap["databaseuser"]));
        db.setPassword(QString::fromStdString(dbMap["databasepassword"]));


        bool ok = false;
        try {
            db.open();
            ok=true;
        } catch (...) {
            ok=false;
            //TODO 添加日志信息
        }

        return ok;
    }else{
        return false;
    }
}

