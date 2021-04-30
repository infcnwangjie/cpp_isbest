#include "user.h"

using namespace  std;
User::User()
{

}

string User::getUserName(){
    return this->userName;
}

void User::setUserName(std::string name){
    this->userName=name;
}


string User::getPassWord(){
    return this->password;
}

void User::setPassWord(std::string password){
    this->password=password;
}

void User::setTrueName(std::string trueName){
    this->trueName=trueName;

}

string User::getTrueName(){return this->trueName;}


string User::getRemarks(){return this->remarks;}


void User::setRoles(std::string rolls){this->roles=rolls;}

string User::getRoles(){return this->roles;}
