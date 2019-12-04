#include"room.h"


Room::Room(int roomId,double discount,double roomCost,QString roomType,int status,QString guestsId){
    this->roomId=roomId;
    this->discount=discount;
    this->roomCost=roomCost;
    this->roomType=roomType;
    this->status=status;
    this->guestsId=guestsId;
}
Room::Room(int roomId,double discount,double roomCost,QString roomType,QString guestsId){
    this->roomId=roomId;
    this->discount=discount;
    this->roomCost=roomCost;
    this->roomType=roomType;
    this->guestsId=guestsId;
}
Room::Room(int roomId,double roomCost,QString roomType,int status){
    this->roomId=roomId;
    this->roomCost=roomCost;
    this->roomType=roomType;
    this->status=status; 
}
Room::Room(){
    
}

QString Room::getGuestsId(){
    return this->guestsId;
}
void Room::setGuestsId(QString guestsId){
    this->guestsId=guestsId;
}
int Room::getRoomId(){
    return this->roomId;
}
void Room::setRoomId(int roomId){
    this->roomId=roomId;
}
double Room::getDiscount(){
    return this->discount;
}
double Room::getRoomCost(){
    return this->roomCost;
}
QString Room::getRoomType(){
    return this->roomType;
}
int Room::getStatus(){
    return this->status;
}
void Room::setStatus(int status){
    this->status=status;
    
}
void Room::setDiscount(double discount){
    this->discount=discount;
}
void Room::setRoomCost(double roomCost){
    this->roomCost=roomCost;
}
void Room::setRoomType(QString roomType){
    this->roomType=roomType;
}

Room::~Room(){
    
}
