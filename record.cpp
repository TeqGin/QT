#include "record.h"

Record::Record(QString guestsId,QString guestsName,int roomId,double roomDiscount,
       double roomCost,QString roomType,Date inTime,Date outTime,int flag):
       Room (roomId,roomDiscount,roomCost,roomType,guestsId),
       Person (guestsName){
    this->inTime=inTime;
    this->outTime=outTime;
    this->flag=flag;
}

Date Record::getInTime(){
    return this->inTime;
}
Date Record::getOutTime(){
    return this->outTime;
}
void Record::setInTime(Date inTime){
    this->inTime=inTime;
}
void Record::setOutTime(Date outTime){
    this->outTime=outTime;
}
int Record::getFlag(){
    return this->flag;
}
void Record::setFlag(int flag){
    this->flag=flag;
}
int Record::getRecordId(){
    return this->recordId;
}
void Record::setRecord(int recordId){
    this->recordId=recordId;
}

