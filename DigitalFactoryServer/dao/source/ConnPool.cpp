
#include "ConnPool.h"

ConnPool * ConnPool::instance=nullptr;
ConnPool::ConnPool(){
    //    this->initConn();
}

ConnPool::~ConnPool(){
    closeConn();
}

void ConnPool:: loadDbConfig(){

    ifstream  db_config("C:/work/gitwork/cpp_isbest/DigitalFactoryServer/dbconfig.txt",ios::in);
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

MYSQL ConnPool:: createOneConnect(){
    if(this->dbMap.size()==0){
        this->loadDbConfig();
    }
    const char *host =dbMap["databaseip"].data();
    const char *user = dbMap["databaseuser"].data();
    const char *pass = dbMap["databasepassword"].data();
    const char *db =dbMap["databasename"].data(); // 数据库名称（已存在）

    stringstream porttemp(dbMap["databasename"]);
    int port =0;
    porttemp>>port; // 数据库名称（已存在）
    MYSQL conn;
    mysql_init(&conn);
    mysql_real_connect(&conn, host, user, pass, db, port, 0, 0);
    return conn;
}


bool ConnPool::initConns(int maxConnectSize){

    if(this->dbMap.size()==0){
        this->loadDbConfig();
    }
    const char *host =dbMap["databaseip"].data();
    const char *user = dbMap["databaseuser"].data();
    const char *pass = dbMap["databasepassword"].data();
    const char *db =dbMap["databasename"].data(); // 数据库名称（已存在）


    stringstream porttemp(dbMap["databasename"]);
    int port =0;
    porttemp>>port; // 数据库名称（已存在）
    bool succuss=false;
    try {

        for(int i=0;i<maxConnectSize;i++){
            MYSQL conn=  this-> createOneConnect();
            connList.push_back(conn);
        }

        this->successConn=true;
    } catch (...) {
        succuss=false;
    }

    return succuss;
}

bool ConnPool::closeConn(){

    try {

        if(this->connList.size()==0)
            return true;
        for(MYSQL conn:this->connList){
            mysql_close(&conn);
        }

        return true;

    } catch (...) {
        return false;
    }
}


ConnPool * ConnPool::getInstance(){
    if(instance==nullptr){

        instance=new ConnPool();
    }

    return instance;
}


MYSQL ConnPool:: getConnect(){

    std::unique_lock<std::mutex> uniqlock(this->lock);

    if(this->dbMap.size()==0){
        this->loadDbConfig();
    }
    const char *host =dbMap["databaseip"].data();
    const char *user = dbMap["databaseuser"].data();
    const char *pass = dbMap["databasepassword"].data();
    const char *db =dbMap["databasename"].data(); // 数据库名称（已存在）
    stringstream porttemp(dbMap["databasename"]);
    int port =0;
    porttemp>>port; // 数据库名称（已存在）


    if(connList.size()>0){
        mysqlconn=connList.front();

        if (mysql_real_connect(&mysqlconn, host, user, pass, db, port, 0, 0)){
            connList.pop_front();
        }else{
            mysqlconn=createOneConnect();connList.push_back(mysqlconn);
        }


    }else{
        initConns();

        mysqlconn=connList.front();
        connList.pop_front();
        return mysqlconn;
    }
    uniqlock.unlock();


    return  mysqlconn;

}


//void testmysql(){

//    MYSQL mysql;
//    mysql_init(&mysql);
//    const char *host = "127.0.0.1";
//    const char *user = "root";
//    const char *pass = "root";
//    const char *db = "myshop"; // 数据库名称（已存在）
//    if (!mysql_real_connect(&mysql, host, user, pass, db, 3306, 0, 0))
//    {
//        cout << "Failed" << endl;
//    }
//    else
//    {
//        cout << "success" << endl;
//        if (0 == mysql_query(&mysql, "select * from goods "))
//        {
//            cout << "Operate_Mysql Query Success" << endl;
//            MYSQL_RES *result = nullptr;
//            result = mysql_store_result(&mysql);
//            unsigned int rows = (unsigned int)mysql_num_rows(result);
//            cout << "总记录条数： " << rows << endl;
//            unsigned int fields = mysql_num_fields(result);
//            cout << "每条记录总共 " << fields << " 个字段" << endl;
//            MYSQL_FIELD *field = nullptr;
//            for (unsigned int i = 0; i < fields; i++)
//            {
//                field = mysql_fetch_field_direct(result, i);
//                cout << field->name << "\t\t";
//            }
//            cout << endl;
//            MYSQL_ROW row = nullptr;
//            row = mysql_fetch_row(result);
//            while (nullptr != row)
//            {
//                for (unsigned int i = 0; i < fields; ++i)
//                {
//                    if (row[i] != nullptr)
//                        cout << row[i] << "\t\t";
//                    else
//                        cout << "null" << "\t\t";
//                }
//                cout << endl;
//                row = mysql_fetch_row(result);
//            }
//            mysql_free_result(result);
//        }
//        else
//        {
//            cout << "Operate_Mysql Query Failed" << endl;
//            cout << mysql_error(&mysql) << endl;
//        }

//    }
//    mysql_close(&mysql);

//}
