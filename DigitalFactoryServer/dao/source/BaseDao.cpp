#include "BaseDao.h"


MYSQL BaseDao::fetchConn(){
    connectPool=this->connectPool->getInstance();

    MYSQL conn=connectPool->getConnect();
    return conn;
}




bool BaseDao::add(string sql){



    MYSQL conn=fetchConn();


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

bool BaseDao::deleteDatas(string sql){

    MYSQL conn=fetchConn();



    cout<<sql<<endl;

    if(mysql_query(&conn, sql.data()))        //执行SQL语句
    {
        printf("delete user failed (%s)\n",mysql_error(&conn));
        return false;
    }
    else
    {
        printf("delete success\n");
        return true;
    }




}


bool BaseDao::modify(string sql){

    MYSQL conn=fetchConn();

    cout<<sql<<endl;
    mysql_query(&conn, "set names utf8");

    if(mysql_query(&conn, sql.data()))        //执行SQL语句
    {
        printf("modify user failed (%s)\n",mysql_error(&conn));
        return false;
    }
    else
    {
        printf("modify success\n");
        return true;
    }
}


map<string,string> BaseDao:: getOne(string sql){



    map<string,string> data;

    MYSQL conn=fetchConn();

    cout<<sql<<endl;

    mysql_query(&conn, "set names utf8");

    if (0 == mysql_query(&conn, sql.data()))
    {

        MYSQL_RES *result = nullptr;

        result = mysql_store_result(&conn); //获得sql语句结束后返回的结果集
        unsigned int rows = (unsigned int)mysql_num_rows(result);

        if(rows==0)return data;


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
                    data.insert(pair<string,string>(fieldNames[i],row[i]));
                else
                    cout << "null" << "\t\t";
            }
            cout << endl;
            row = mysql_fetch_row(result);
        }
        mysql_free_result(result);
        //         mysql_close(&conn);
        cout<<"find it"<<endl;
        //        return true;
        return data;
    }
    else
    {
        cout << "no find " << \
                mysql_error(&conn) << endl;
        //         mysql_close(&conn);
        //        return false;

        return data;
    }


}
list<map<string,string>> BaseDao::query(string sql){



    list<map<string,string>> datas;

    MYSQL conn=fetchConn();


    cout<<sql<<endl;

    mysql_query(&conn, "set names utf8");

    if (0 == mysql_query(&conn, sql.data()))
    {

        MYSQL_RES *result = nullptr;

        result = mysql_store_result(&conn); //获得sql语句结束后返回的结果集
        unsigned int rows = (unsigned int)mysql_num_rows(result);

        if(rows==0)return datas;


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
            datas.push_back(record);

            row = mysql_fetch_row(result);
        }
        mysql_free_result(result);
        //         mysql_close(&conn);

        return datas;
    }
    else
    {
        cout << "no find user" << \
                mysql_error(&conn) << endl;
        //         mysql_close(&conn);
        //        return false;

        return datas;
    }

}
