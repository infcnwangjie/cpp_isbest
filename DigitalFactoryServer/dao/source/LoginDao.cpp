#include "LoginDao.h"


bool LoginDao::login(string user,string password,string registcode){

    connectPool=this->connectPool->getInstance();

    MYSQL conn=connectPool->getConnect();

    stringstream sqlBuilder;
    sqlBuilder<<"select * from user  where name='"<<user<<"' and password= '"<<password<<"'";



    string sql=sqlBuilder.str();

    cout<<sql<<endl;

    if (0 == mysql_query(&conn, sql.data()))
    {

        MYSQL_RES *result = nullptr;
        result = mysql_store_result(&conn);
        unsigned int rows = (unsigned int)mysql_num_rows(result);
        cout << "总记录条数： " << rows << endl;
        unsigned int fields = mysql_num_fields(result);
        cout << "每条记录总共 " << fields << " 个字段" << endl;
        MYSQL_FIELD *field = nullptr;
        for (unsigned int i = 0; i < fields; i++)
        {
            field = mysql_fetch_field_direct(result, i);
            cout << field->name << "\t\t";
        }
        cout << endl;
        MYSQL_ROW row = nullptr;
        row = mysql_fetch_row(result);
        while (nullptr != row)
        {
            for (unsigned int i = 0; i < fields; ++i)
            {
                if (row[i] != nullptr)
                    cout << row[i] << "\t\t";
                else
                    cout << "null" << "\t\t";
            }
            cout << endl;
            row = mysql_fetch_row(result);
        }
        mysql_free_result(result);
        //         mysql_close(&conn);
        cout<<"find user"<<endl;
    }
    else
    {
        cout << "no find user" << endl;
        //        cout << mysql_error(&conn) << endl;
        //         mysql_close(&conn);
        return false;
    }


    return true;

}
