#include"person.h"

Person::Person(){
    
}
Person::Person(QString name){
    this->name=name;
}
Person::Person(QString name,QString id,QString sex,QString password){
    this->name=name;
    this->PersonId=id;
    this->sex=sex;
    this->password=password;

}
Person::Person(QString name,QString id,QString sex,QString password,int role){
    this->name=name;
    this->PersonId=id;
    this->sex=sex;
    this->password=password;
    this->role=role;
}

QString Person::getPassword(){
    return this->password;
}
void Person::setPassword(QString password){
    this->password=password;
}

QString Person::getName(){
    return this->name;
}
QString Person::getPersonId(){
    return this->PersonId;
}
QString Person::getSex(){
    return this->sex;
}
void Person::setName(QString name){
    this->name=name;
}
void Person::setPersonId(QString id){
    this->PersonId=id;
}
void Person::setSex(QString sex){
    this->sex=sex;
}

void Person::setRole(int role){
    this->role=role;
}
int Person::getRole(){
    return this->role;
}
