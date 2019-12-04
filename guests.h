#ifndef GUESTS_H
#define GUESTS_H
#include"person.h"
#include"date.h"
#include"room.h"

struct roomNode{
    int roomId;
    Date inDate;
    Date outDate;
    double stayTime;
    roomNode *next;
};

class Guests:public Person
{
public:
    Guests();
    //初始化一位客人
    Guests(QString name,QString id,QString sex,QString passWord);
    //订购一间房间
    bool BuyRoom(int roomId,Date inDate,Date outDate);
    //退房
    bool leaveRoom(int roomId);
};

#endif // GUESTS_H
