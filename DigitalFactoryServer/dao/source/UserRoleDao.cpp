#include "UserRoleDao.h"


MYSQL UserRoleDao::fetchConn(){
    connectPool=this->connectPool->getInstance();

    MYSQL conn=connectPool->getConnect();
    return conn;
}


bool UserRoleDao::addRole(string name,string remark){
    MYSQL conn=fetchConn();

    stringstream sqlBuilder;
    sqlBuilder<<"insert into role(name,remark) values"<<"('"<<name<<"','"
             <<remark<<"')";

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
bool UserRoleDao::deleteRole(string name){

    MYSQL conn=fetchConn();

    stringstream sqlBuilder;
    sqlBuilder<<"delete from  role where name='"<<name<<"'";

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
bool UserRoleDao::deleteRoleById(int id){
    MYSQL conn=fetchConn();

    stringstream sqlBuilder;
    sqlBuilder<<"delete from  role where id="<<id;

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
bool UserRoleDao::modifyRole(int id,string name,string remark){
    MYSQL conn=fetchConn();

    stringstream sqlBuilder;
    sqlBuilder<<"update role set name='"<<name<<",remark='"<<remark<<"'"
             <<" where id="<<id;

    string sql=sqlBuilder.str();

    cout<<sql<<endl;

    if(mysql_query(&conn, sql.data()))        //执行SQL语句
    {
        printf("modify role failed (%s)\n",mysql_error(&conn));
        return false;
    }
    else
    {
        printf("modify success\n");
        return true;
    }
}
map<string,string> UserRoleDao::getRoleById(int id){

    map<string,string> roleInfo;

    MYSQL conn=fetchConn();

    stringstream sqlBuilder;
    sqlBuilder<<"select * from role  where id="<<id;

    string sql=sqlBuilder.str();

    cout<<sql<<endl;

    mysql_query(&conn,"set names gbk");

    if (0 == mysql_query(&conn, sql.data()))
    {

        MYSQL_RES *result = nullptr;

        result = mysql_store_result(&conn); //获得sql语句结束后返回的结果集
        unsigned int rows = (unsigned int)mysql_num_rows(result);

        if(rows==0)return roleInfo;


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
                    roleInfo.insert(pair<string,string>(fieldNames[i],row[i]));
                else
                    cout << "null" << "\t\t";
            }
            cout << endl;
            row = mysql_fetch_row(result);
        }
        mysql_free_result(result);
        //         mysql_close(&conn);
        cout<<"find user"<<endl;
        //        return true;
        return roleInfo;
    }
    else
    {
        cout << "no find user" << \
                mysql_error(&conn) << endl;
        //         mysql_close(&conn);
        //        return false;

        return roleInfo;
    }
}
list<map<string,string>> UserRoleDao::selectRoles(string name,string remarks,
                                                  int pageSize,int currentPage){
    list<map<string,string>> roleInfos;

    MYSQL conn=fetchConn();

    stringstream sqlBuilder;
    sqlBuilder<<"select * from role";
    if(name!="" or remarks!="" ){
        sqlBuilder<<" where ";
        if(name!=""){
            sqlBuilder<<"  name='"<<name<<"'";
        }

        if(remarks!=""){
            sqlBuilder<<"  remarks='"<<remarks<<"'";
        }


    }

    sqlBuilder<<" limit "<<(currentPage-1)*pageSize<<","<<pageSize;

    string sql=sqlBuilder.str();

    cout<<sql<<endl;

    mysql_query(&conn,"set names gbk");

    if (0 == mysql_query(&conn, sql.data()))
    {

        MYSQL_RES *result = nullptr;

        result = mysql_store_result(&conn); //获得sql语句结束后返回的结果集
        unsigned int rows = (unsigned int)mysql_num_rows(result);

        if(rows==0)return roleInfos;


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
            roleInfos.push_back(record);

            row = mysql_fetch_row(result);
        }
        mysql_free_result(result);
        //         mysql_close(&conn);

        return roleInfos;
    }
    else
    {
        cout << "no find user" << \
                mysql_error(&conn) << endl;
        //         mysql_close(&conn);
        //        return false;

        return roleInfos;
    }

}
