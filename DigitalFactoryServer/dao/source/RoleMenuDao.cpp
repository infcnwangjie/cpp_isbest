#include "RoleMenuDao.h"


MYSQL RoleMenuDao::fetchConn(){
    connectPool=this->connectPool->getInstance();

    MYSQL conn=connectPool->getConnect();
    return conn;
}


bool RoleMenuDao::addRoleMenu(int menuid ,int roleid){
    MYSQL conn=fetchConn();

    stringstream sqlBuilder;
    sqlBuilder<<"insert into role_menu(menuid,roleid) values"<<"("<<menuid<<","
             <<roleid<<")";

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
bool RoleMenuDao::deleteRoleMenu(int roleId){

    MYSQL conn=fetchConn();

    stringstream sqlBuilder;
    sqlBuilder<<"delete from  role_menu where roleid="<<roleId;

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
bool RoleMenuDao::deleteRoleMenuById(int roleId, int menuId){
    MYSQL conn=fetchConn();

    stringstream sqlBuilder;
    sqlBuilder<<"delete from  role_menu where menuid="<<menuId<<" roleid="<<roleId;

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

map<string,string> RoleMenuDao::getRoleMenuByRoleId(int roleId){

    map<string,string> roleMenuInfo;

    MYSQL conn=fetchConn();

    stringstream sqlBuilder;
    sqlBuilder<<"select * from role_menu  where roleid="<<roleId;

    string sql=sqlBuilder.str();

    cout<<sql<<endl;

    mysql_query(&conn,"set names gbk");

    if (0 == mysql_query(&conn, sql.data()))
    {

        MYSQL_RES *result = nullptr;

        result = mysql_store_result(&conn); //获得sql语句结束后返回的结果集
        unsigned int rows = (unsigned int)mysql_num_rows(result);

        if(rows==0)return roleMenuInfo;


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
                    roleMenuInfo.insert(pair<string,string>(fieldNames[i],row[i]));
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
        return roleMenuInfo;
    }
    else
    {
        cout << "no find user" << \
                mysql_error(&conn) << endl;
        //         mysql_close(&conn);
        //        return false;

        return roleMenuInfo;
    }
}
list<map<string,string>> RoleMenuDao::selectRoleMenus(int roleId,int menuId,
                                                      int pageSize,int currentPage){
    list<map<string,string>> roleMenuInfos;

    MYSQL conn=fetchConn();

    stringstream sqlBuilder;
    sqlBuilder<<"select * from role_menu";
    if(roleId!=0 or menuId!=0 ){
        sqlBuilder<<" where ";
        if(roleId!=0){
            sqlBuilder<<"  roleid="<<roleId;
        }

        if(menuId!=0){
            sqlBuilder<<"  menuId="<<menuId;
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

        if(rows==0)return roleMenuInfos;


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
            roleMenuInfos.push_back(record);

            row = mysql_fetch_row(result);
        }
        mysql_free_result(result);
        //         mysql_close(&conn);

        return roleMenuInfos;
    }
    else
    {
        cout << "no find user" << \
                mysql_error(&conn) << endl;
        //         mysql_close(&conn);
        //        return false;

        return roleMenuInfos;
    }

}
