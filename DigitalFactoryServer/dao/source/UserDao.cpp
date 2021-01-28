#include "UserDao.h"



bool UserDao::login(string user,string password,string registcode){

    stringstream sqlBuilder;
    sqlBuilder<<"select * from user  where name='"<<user<<"' and password= '"<<password<<"'";

    string sql=sqlBuilder.str();

    map<string,string> userInfo=getOne(sql);
    cout<<userInfo.size();
    return userInfo.size()!=0;
}


bool UserDao::addUser(string name,string email,int role_id,int depart_id,string remark,string password){


    stringstream sqlBuilder;
    sqlBuilder<<"insert into user(name,password,email,role_id,depart_id,remark) values"<<"('"<<name<<"','"
             <<password<<"','"<<email<<"',"<<role_id<<","<<depart_id<<",'"<<remark<<"')";

    string sql=sqlBuilder.str();

    return add(sql);
}

bool UserDao::deleteUser(string name,string password){



    stringstream sqlBuilder;
    sqlBuilder<<"delete from  user where name='"<<name<<"' and password='"<<password<<"'";

    string sql=sqlBuilder.str();

    cout<<sql<<endl;

    return deleteDatas(sql);




}

bool UserDao::deleteUserById(int id){


    stringstream sqlBuilder;
    sqlBuilder<<"delete from  user where id="<<id;

    string sql=sqlBuilder.str();

    return deleteDatas(sql);
}

bool UserDao::modifyUser(int id,string name,string email,int role_id,int depart_id,string remark,string password){


    stringstream sqlBuilder;
    sqlBuilder<<"update user set name='"<<name<<"',password='"<<password<<"',email='"<<email<<"',role_id="<<role_id\
             <<",depart_id="<<depart_id<<",remark='"<<remark<<"'"
            <<" where id="<<id;

    string sql=sqlBuilder.str();

    return modify(sql);
}


map<string,string> UserDao:: getUserById(int id){



    map<string,string> userInfo;


    stringstream sqlBuilder;
    sqlBuilder<<"select * from user  where id="<<id;

    string sql=sqlBuilder.str();

    return getOne(sql);

}
list<map<string,string>> UserDao::selectUsers(string name,string email,int role_id,int depart_id,string password,\
                                              int pageSize,int currentPage){



    list<map<string,string>> userInfos;



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

    return query(sql);

}
