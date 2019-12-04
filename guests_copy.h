#ifndef GUESTS_H
#define GUESTS_H
#include"person.h"
#include"date.h"
#include"room.h"
struct roomNode{
    Room * room;
    roomNode *next;
};

class guests:public Person
{
private:
    Date inDate;
    Date outDate;
    double stayTime;
    QString passWord;
    roomNode * hisRooms;   //用链表的形式存储客人订购的房间
public:
    guests();
    guests();
};

#endif // GUESTS_H
