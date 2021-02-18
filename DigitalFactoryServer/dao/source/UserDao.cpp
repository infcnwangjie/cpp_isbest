#include "UserDao.h"



string UserDao::login(string user,string password,string registcode){

    stringstream sqlBuilder;
    sqlBuilder<<"select * from user  where name='"<<user<<"' and password= '"<<password<<"'";

    string sql=sqlBuilder.str();



return sql;
}


string UserDao::addUser(string name,string email,int staffposition_id,int role_id,int depart_id,string remark,string password){


    stringstream sqlBuilder;
    sqlBuilder<<"insert into user(name,password,email,staff_positionid,role_id,depart_id,remark) values"<<"('"<<name<<"','"
             <<password<<"','"<<email<<"',"<<staffposition_id<<","<<role_id<<","<<depart_id<<",'"<<remark<<"')";

    string sql=sqlBuilder.str();

return sql;
}

string UserDao::deleteUser(string name,string password){



    stringstream sqlBuilder;
    sqlBuilder<<"delete from  user where name='"<<name<<"' and password='"<<password<<"'";

    string sql=sqlBuilder.str();

    cout<<sql<<endl;

   return sql;



}

string UserDao::deleteUserById(int id){


    stringstream sqlBuilder;
    sqlBuilder<<"delete from  user where id="<<id;

    string sql=sqlBuilder.str();

   return sql;
}

string UserDao::modifyUser(int id,string name,string email,int staffposition_id,int role_id,int depart_id,string remark,string password){


    stringstream sqlBuilder;
    sqlBuilder<<"update user set name='"<<name<<"',password='"<<password<<"',email='"<<email<<"',staffposition_id="<<staffposition_id<<",role_id="<<role_id\
             <<",depart_id="<<depart_id<<",remark='"<<remark<<"'"
            <<" where id="<<id;

    string sql=sqlBuilder.str();

   return sql;
}


string UserDao:: getUserById(int id){



    map<string,string> userInfo;


    stringstream sqlBuilder;
    sqlBuilder<<"select * from user  where id="<<id;

    string sql=sqlBuilder.str();

   return sql;

}
string UserDao::selectUsers(string name,string email,int staffposition_id,int role_id,int depart_id,string password,\
                                              int pageSize,int currentPage){



    list<map<string,string>> userInfos;



    stringstream sqlBuilder;
    sqlBuilder<<"select * from user";
    if(name!="" || email!="" || password!="" ||  role_id !=0 || depart_id!=0){
        sqlBuilder<<" where ";
        if(name!=""){
            sqlBuilder<<"  name='"<<name;

            if(email!="" || password!="" ||  role_id !=0 || depart_id!=0||staffposition_id!=0){
                sqlBuilder<<"' and ";
            }

        }

        if(email!=""){
            sqlBuilder<<"  email='"<<email;
            if( password!="" ||  role_id !=0 || depart_id!=0 ||staffposition_id!=0){
                sqlBuilder<<"' and ";
            }
        }

        if(password!=""){
            sqlBuilder<<"  password='"<<password<<"'";
            if(   role_id !=0 || depart_id!=0 ||staffposition_id!=0){
                sqlBuilder<<" and ";
            }
        }

        if(staffposition_id!=0){
            sqlBuilder<<" staff_positionid="<<staffposition_id;
            if(   role_id !=0 || depart_id!=0){
                sqlBuilder<<"' and ";
            }
        }
        if(role_id!=0){
            sqlBuilder<<" role_id="<<role_id;
            if(  depart_id!=0){
                sqlBuilder<<"' and ";
            }
        }

        if(depart_id!=0){
            sqlBuilder<<" depart_id="<<depart_id;

        }
    }

    sqlBuilder<<" limit "<<(currentPage-1)*pageSize<<","<<pageSize;

    string sql=sqlBuilder.str();

    return sql;

}
