#include "MenuDao.h"

MYSQL MenuDao::fetchConn(){
    connectPool=this->connectPool->getInstance();

    MYSQL conn=connectPool->getConnect();
    return conn;
}
bool MenuDao::addMenu(string menuname,string url,string icon,int pid,int is_parent){
    MYSQL conn=fetchConn();

    stringstream sqlBuilder;
    sqlBuilder<<"insert into menu(menuname,url,icon,pid,is_parent) values"<<"('"<<menuname<<"','"
             <<url<<"','"<<icon<<"',"<<pid<<","<<is_parent<<")";

    string sql=sqlBuilder.str();

    cout<<sql<<endl;
    mysql_query(&conn, "set names utf8");

    if(mysql_query(&conn, sql.data()))        //执行SQL语句
    {
        printf("insert failed (%s)\n",mysql_error(&conn));
        return false;
    }
    else
    {
        printf("Insert success\n");
        return true;
    }

    return true;
}
bool MenuDao::deleteMenu(string menuname){
    MYSQL conn=fetchConn();

    stringstream sqlBuilder;
    sqlBuilder<<"delete from  menu where name='"<<menuname<<"'";

    string sql=sqlBuilder.str();

    cout<<sql<<endl;

    if(mysql_query(&conn, sql.data()))        //执行SQL语句
    {
        printf("delete menu failed (%s)\n",mysql_error(&conn));
        return false;
    }
    else
    {
        printf("delete success\n");
        return true;
    }

}
bool MenuDao::deleteMenuById(int id){
    MYSQL conn=fetchConn();

    stringstream sqlBuilder;
    sqlBuilder<<"delete from  menu where id="<<id;

    string sql=sqlBuilder.str();

    cout<<sql<<endl;

    if(mysql_query(&conn, sql.data()))        //执行SQL语句
    {
        printf("delete rolw failed (%s)\n",mysql_error(&conn));
        return false;
    }
    else
    {
        printf("delete success\n");
        return true;
    }
}
bool MenuDao::modifyMenu(int id,string menuname,string url,string icon,int pid,int is_parent){
    MYSQL conn=fetchConn();

    stringstream sqlBuilder;
    sqlBuilder<<"update menu set name='"<<menuname<<",url='"<<url<<"',"<<icon<<"',"<<pid<<","<<is_parent
             <<" where id="<<id;

    string sql=sqlBuilder.str();

    cout<<sql<<endl;
    mysql_query(&conn, "set names utf8");

    if(mysql_query(&conn, sql.data()))        //执行SQL语句
    {
        printf("modify menu failed (%s)\n",mysql_error(&conn));
        return false;
    }
    else
    {
        printf("modify success\n");
        return true;
    }
}
map<string,string> MenuDao::getMenuById(int id){
    map<string,string> menuInfo;

    MYSQL conn=fetchConn();

    stringstream sqlBuilder;
    sqlBuilder<<"select * from menu  where id="<<id;

    string sql=sqlBuilder.str();

    cout<<sql<<endl;

    mysql_query(&conn, "set names utf8");

    if (0 == mysql_query(&conn, sql.data()))
    {

        MYSQL_RES *result = nullptr;

        result = mysql_store_result(&conn); //获得sql语句结束后返回的结果集
        unsigned int rows = (unsigned int)mysql_num_rows(result);

        if(rows==0)return menuInfo;


        const unsigned int fields = mysql_num_fields(result);
        //        cout << "每条记录总共 " << fields << " 个字段" << endl;
        MYSQL_FIELD *field = nullptr;
        string fieldNames[fields];
        for (unsigned int i = 0; i < fields; i++)
        {
            field = mysql_fetch_field_direct(result, i);
            fieldNames[i]=field->name ;
            //            cout << field->name << "\t\t";
        }

        MYSQL_ROW row = nullptr;
        row = mysql_fetch_row(result);
        while (nullptr != row)
        {
            for (unsigned int i = 0; i < fields; ++i)
            {
                //                field = mysql_fetch_field_direct(result, i);
                if (row[i] != nullptr)
                    menuInfo.insert(pair<string,string>(fieldNames[i],row[i]));
                else
                    cout << "null" << "\t\t";
            }
            cout << endl;
            row = mysql_fetch_row(result);
        }
        mysql_free_result(result);
        //         mysql_close(&conn);

        //        return true;
        return menuInfo;
    }
    else
    {
        cout << "no find " << \
                mysql_error(&conn) << endl;
        //         mysql_close(&conn);
        //        return false;

        return menuInfo;
    }
}
list<map<string,string>> MenuDao::selectMenus(string menuname,string url,
                                              int pageSize,int currentPage){
    list<map<string,string>> menuInfos;

    MYSQL conn=fetchConn();

    stringstream sqlBuilder;
    sqlBuilder<<"select * from role";
    if(menuname!="" or url!="" ){
        sqlBuilder<<" where ";
        if(menuname!=""){
            sqlBuilder<<"  menuname='"<<menuname<<"'";
        }

        if(url!=""){
            sqlBuilder<<"  url='"<<url<<"'";
        }


    }

    sqlBuilder<<" limit "<<(currentPage-1)*pageSize<<","<<pageSize;

    string sql=sqlBuilder.str();

    cout<<sql<<endl;

    mysql_query(&conn, "set names utf8");

    if (0 == mysql_query(&conn, sql.data()))
    {

        MYSQL_RES *result = nullptr;

        result = mysql_store_result(&conn); //获得sql语句结束后返回的结果集
        unsigned int rows = (unsigned int)mysql_num_rows(result);

        if(rows==0)return menuInfos;


        const unsigned int fields = mysql_num_fields(result);
        //        cout << "每条记录总共 " << fields << " 个字段" << endl;
        MYSQL_FIELD *field = nullptr;
        string fieldNames[fields];
        for (unsigned int i = 0; i < fields; i++)
        {
            field = mysql_fetch_field_direct(result, i);
            fieldNames[i]=field->name ;
            //            cout << field->name << "\t\t";
        }

        MYSQL_ROW row = nullptr;
        row = mysql_fetch_row(result);
        while (nullptr != row)
        {
            map<string,string> record;
            for (unsigned int i = 0; i < fields; ++i)
            {
                //                field = mysql_fetch_field_direct(result, i);
                if (row[i] != nullptr)
                    record.insert(pair<string,string>(fieldNames[i],row[i]));
                else
                    cout << "null" << "\t\t";
            }
            menuInfos.push_back(record);

            row = mysql_fetch_row(result);
        }
        mysql_free_result(result);
        //         mysql_close(&conn);

        return menuInfos;
    }
    else
    {
        cout << "no find user" << \
                mysql_error(&conn) << endl;
        //         mysql_close(&conn);
        //        return false;

        return menuInfos;
    }

}






