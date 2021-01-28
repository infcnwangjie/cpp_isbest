#include "UserDao.h"


MYSQL UserDao::fetchConn(){
    connectPool=this->connectPool->getInstance();

    MYSQL conn=connectPool->getConnect();
    return conn;
}


bool UserDao::login(string user,string password,string registcode){



    MYSQL conn=fetchConn();

    stringstream sqlBuilder;
    sqlBuilder<<"select * from user  where name='"<<user<<"' and password= '"<<password<<"'";

    string sql=sqlBuilder.str();

    cout<<sql<<endl;

    mysql_query(&conn,"set names gbk");

    if (0 == mysql_query(&conn, sql.data()))
    {

        MYSQL_RES *result = nullptr;

        result = mysql_store_result(&conn); //获得sql语句结束后返回的结果集
        unsigned int rows = (unsigned int)mysql_num_rows(result);
        //        cout << "总记录条数： " << rows << endl;
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
        bool matchName=false,matchPasswd=false;
        while (nullptr != row)
        {

            for (unsigned int i = 0; i < fields; ++i)
            {
                if(fieldNames[i]=="name" && row[i]==user){
                    matchName=true;
                }

                if(fieldNames[i]=="password" && row[i]==password){
                    matchPasswd=true;
                }
                if(matchName==true &&matchPasswd==true){
                    break;
                }
            }
            cout << endl;
            row = mysql_fetch_row(result);
        }


        mysql_free_result(result);
        //         mysql_close(&conn);
        if(matchName &&matchPasswd)
            cout<<"find user"<<endl;
        else
             cout<<"not find user"<<endl;

        return matchName &&matchPasswd;
    }
    else
    {
        cout << "no find user" << endl;
        //        cout << mysql_error(&conn) << endl;
        //         mysql_close(&conn);
        return false;
    }




}


bool UserDao::addUser(string name,string email,int role_id,int depart_id,string remark,string password){



    MYSQL conn=fetchConn();

    stringstream sqlBuilder;
    sqlBuilder<<"insert into user(name,password,email,role_id,depart_id,remark) values"<<"('"<<name<<"','"
             <<password<<"','"<<email<<"',"<<role_id<<","<<depart_id<<",'"<<remark<<"')";

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

bool UserDao::deleteUser(string name,string password){

    MYSQL conn=fetchConn();

    stringstream sqlBuilder;
    sqlBuilder<<"delete from  user where name='"<<name<<"' and password='"<<password<<"'";

    string sql=sqlBuilder.str();

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

bool UserDao::deleteUserById(int id){
    MYSQL conn=fetchConn();

    stringstream sqlBuilder;
    sqlBuilder<<"delete from  user where id="<<id;

    string sql=sqlBuilder.str();

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

bool UserDao::modifyUser(int id,string name,string email,int role_id,int depart_id,string remark,string password){

    MYSQL conn=fetchConn();

    stringstream sqlBuilder;
    sqlBuilder<<"update user set name='"<<name<<"',password='"<<password<<"',email='"<<email<<"',role_id="<<role_id\
             <<",depart_id="<<depart_id<<",remark='"<<remark<<"'"
            <<" where id="<<id;

    string sql=sqlBuilder.str();

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


map<string,string> UserDao:: getUserById(int id){



    map<string,string> userInfo;

    MYSQL conn=fetchConn();

    stringstream sqlBuilder;
    sqlBuilder<<"select * from user  where id="<<id;

    string sql=sqlBuilder.str();

    cout<<sql<<endl;

    mysql_query(&conn, "set names utf8");

    if (0 == mysql_query(&conn, sql.data()))
    {

        MYSQL_RES *result = nullptr;

        result = mysql_store_result(&conn); //获得sql语句结束后返回的结果集
        unsigned int rows = (unsigned int)mysql_num_rows(result);

        if(rows==0)return userInfo;


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
                    userInfo.insert(pair<string,string>(fieldNames[i],row[i]));
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
        return userInfo;
    }
    else
    {
        cout << "no find user" << \
                mysql_error(&conn) << endl;
        //         mysql_close(&conn);
        //        return false;

        return userInfo;
    }


}
list<map<string,string>> UserDao::selectUsers(string name,string email,int role_id,int depart_id,string password,\
                                               int pageSize,int currentPage){



    list<map<string,string>> userInfos;

    MYSQL conn=fetchConn();

    stringstream sqlBuilder;
    sqlBuilder<<"select * from user";
    if(name!="" or email!="" or password!="" or  role_id !=0 or depart_id!=0){
        sqlBuilder<<" where ";
        if(name!=""){
            sqlBuilder<<"  name='"<<name<<"'";
        }

        if(email!=""){
            sqlBuilder<<"  email='"<<email<<"'";
        }

        if(password!=""){
            sqlBuilder<<"  password='"<<password<<"'";
        }

        if(role_id!=0){
            sqlBuilder<<" role_id="<<role_id<<"";
        }

        if(depart_id!=0){
            sqlBuilder<<" depart_id="<<depart_id<<"";
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

        if(rows==0)return userInfos;


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
            userInfos.push_back(record);

            row = mysql_fetch_row(result);
        }
        mysql_free_result(result);
        //         mysql_close(&conn);

        return userInfos;
    }
    else
    {
        cout << "no find user" << \
                mysql_error(&conn) << endl;
        //         mysql_close(&conn);
        //        return false;

        return userInfos;
    }

}
