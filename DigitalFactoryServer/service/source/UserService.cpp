#include "UserService.h"



bool UserService::login(string jsonstr){

    TinyJson json;
    json.ReadJson(jsonstr);

    string name = json.Get<string>("name");
    string password = json.Get<string>("password");
    string registcode = json.Get<string>("registcode");

    bool correct=this->userDao->login(name,password,registcode);

    return correct;
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
    return this->userDao->addUser(name,email,staffposition_id,role_id,depart_id,remark,password);
}

bool UserService::deleteUser(string jsonstr){

    TinyJson json;
    json.ReadJson(jsonstr);
    string name = json.Get<string>("name");
    string password = json.Get<string>("password");
    return this->userDao->deleteUser(name,password);

}

bool UserService::deleteUserById(string jsonstr){

    TinyJson json;
    json.ReadJson(jsonstr);
    int id = json.Get<int>("id");

    return this->userDao->deleteUserById(id);
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

    return this->userDao->modifyUser( id, name, email, staffposition_id, role_id, depart_id, remark, password);
}


map<string,string> UserService:: getUserById(string jsonstr){




    TinyJson json;
    json.ReadJson(jsonstr);
    int id = json.Get<int>("id");

    return this->userDao->getUserById(id);

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

    return this->userDao->selectUsers(name,email,staffposition_id,role_id,depart_id,password,pageSize,currentPage);

}
