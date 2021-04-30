#include "result.h"

Result::Result()
{

}

Result::Result(std::string message,std::string status,User user):message(message),status(status),user(user){

}


std::string Result::getMessage(){
    return this->message;
}
void Result:: setMessage(std::string message){
    this->message=message;
}

std::string Result:: getStatus(){
    return this->status;
}
void Result::  setStatus(std::string status){
    this->status=status;
}

User Result::getUser(){
    return this->user;
}
void Result::setUser(User user){
    this->user=user;
}
