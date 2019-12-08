#ifndef RECORD_H
#define RECORD_H
#include"room.h"
#include"guests.h"
#include"date.h"



class Record:public Room,public Person
{
public:
    Record(QString guestsId,QString guestsName,int roomId,double roomDiscount,
           double roomCost,QString roomType,Date inTime,Date outTime,int flag);
    Date getInTime();
    void setInTime(Date inTime);
    Date getOutTime();
    void setOutTime(Date outTime);
    int getRecordId();
    void setRecord(int recordId);
    int getFlag();
    void setFlag(int flag);

private:
    int recordId;
    Date inTime;
    Date outTime;
    int flag;//0为该记录无效，1为有效
};

#endif // RECORD_H
