#include "UserService.h"
#include "tinyjson.hpp"

using namespace tiny;
using namespace std;


string myint_to_string(int data){
    std::stringstream transform;
    std::string result;
    transform<<data;
    transform>>result;
    return result;
}

int mystring_to_int(string data){

    stringstream transform;
    int result=0;
    transform<<data;
    transform>>result;
    return result;

}

string UserService::login(string jsonstr){

    TinyJson json;
    json.ReadJson(jsonstr);

    xobject data = json.Get<xobject>("data");
    string user,password,registcode;
    if(data.Count()==0){
        return "";
    }else{
        data.Enter(0);
        user = data.Get<string>("user");
        password = data.Get<string>("password");

        registcode = data.Get<string>("registcode");

    }




    //    bool correct=this->userDao->login(name,password,registcode);



    bool mysqlIfConn=dao->sql_connect();

    TinyJson result;

    if(mysqlIfConn==false){
        result["authorized"].Set("false");
        result["error"].Set("mysql cant connect");
        string str = result.WriteJson();
        return str;
    }

    list<map<string,string>> userInfos=dao->query(this->userDao->selectUsers(user,"",0,0,0,password,10,1));


    string authorized=userInfos.size()==1?"true":"false";


    result["authorized"].Set(authorized);
    result["name"].Set(user);
    result["password"].Set(password);
    TinyJson rolearray,menuarray;
    list<string> roleids;

    if(authorized=="true"){

        map<string,string>  usermap= userInfos.front();

        int userId=mystring_to_int(usermap["id"]);




        list<map<string,string>> roles=  dao->query(this->userRoleDao->selectRolesByUserId(userId));


        for(map<string,string>role :roles){
            TinyJson roleJson;
            roleJson["id"].Set(role["id"]);
            roleJson["name"].Set(role["name"]);
            roleJson["remark"].Set(role["remark"]);
            rolearray.Push(roleJson);

            roleids.push_back(role["id"]);
        }



        result["roles"].Set(rolearray);

        auto menus=dao->query(this->roleMenuDao->selectRoleMenus(roleids));

        for(map<string,string> menu :menus){
            TinyJson menuJson;
            menuJson["id"].Set(menu["id"]);
            menuJson["menuname"].Set(menu["menuname"]);
            menuJson["url"].Set(menu["url"]);
            menuJson["icon"].Set(menu["icon"]);
            menuJson["pid"].Set(menu["pid"]);
            menuJson["is_parent"].Set(menu["is_parent"]);
            menuarray.Push(menuJson);
        }
        result["menus"].Set(menuarray);


    }


    string str = result.WriteJson();


    return str;
}


bool UserService::addUser(string jsonstr){

    TinyJson json;
    json.ReadJson(jsonstr);

    string name = json.Get<string>("name");
    string password = json.Get<string>("password");
    string email = json.Get<string>("email");
    int staffposition_id = json.Get<int>("staffposition_id");
    int role_id = json.Get<int>("role_id");
    int depart_id = json.Get<int>("depart_id");
    string remark = json.Get<string>("remark");
    return dao->add(this->userDao->addUser(name,email,staffposition_id,role_id,depart_id,remark,password));
}

bool UserService::deleteUser(string jsonstr){

    TinyJson json;
    json.ReadJson(jsonstr);
    string name = json.Get<string>("name");
    string password = json.Get<string>("password");
    return dao->deleteDatas(this->userDao->deleteUser(name,password));

}

bool UserService::deleteUserById(string jsonstr){

    TinyJson json;
    json.ReadJson(jsonstr);
    int id = json.Get<int>("id");

    return dao->deleteDatas(this->userDao->deleteUserById(id));
}

bool UserService::modifyUser(string jsonstr){


    TinyJson json;
    json.ReadJson(jsonstr);
    int id = json.Get<int>("id");
    string name = json.Get<string>("name");
    string password = json.Get<string>("password");
    string email = json.Get<string>("email");
    int staffposition_id = json.Get<int>("staffposition_id");
    int role_id = json.Get<int>("role_id");
    int depart_id = json.Get<int>("depart_id");
    string remark = json.Get<string>("remark");

    return dao->modify(this->userDao->modifyUser( id, name, email, staffposition_id, role_id, depart_id, remark, password));
}


map<string,string> UserService:: getUserById(string jsonstr){




    TinyJson json;
    json.ReadJson(jsonstr);
    int id = json.Get<int>("id");

    return dao->getOne(this->userDao->getUserById(id));

}
list<map<string,string>> UserService::selectUsers(string jsonstr){


    //                                                  int pageSize,int currentPage

    TinyJson json;
    json.ReadJson(jsonstr);

    auto name = json.Get<string>("name");
    auto email = json.Get<string>("email");
    auto staffposition_id = json.Get<int>("staffposition_id");
    auto role_id = json.Get<int>("role_id");
    auto depart_id = json.Get<int>("depart_id");
    auto password = json.Get<string>("password");

    auto pageSize = json.Get<int>("pageSize");
    auto currentPage=json.Get<int>("currentPage");

    return dao->query(this->userDao->selectUsers(name,email,staffposition_id,role_id,depart_id,password,pageSize,currentPage));

}
