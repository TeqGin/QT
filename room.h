#ifndef ROMM_H
#define ROMM_H
#include<QString>
struct roomNode;
class Room{
private:
    int roomId;          //客房号
    double discount; //客房折扣
    double roomCost; //客房价格
    QString roomType;//客房种类，分为平价房、高级房等
    int status;     //客房状态 1为可入住，0为不可入住（已被占用）,2为维修中,3为其他情况
    QString guestsId;
public:
    Room(int roomId,double discount,double roomCost,QString roomType,int status,QString guestsId);
    Room(int roomId,double roomCost,QString roomType,int status);
    Room(int roomId,double discount,double roomCost,QString roomType,QString guestsId);
    Room();
    int getRoomId();
    double getDiscount();
    double getRoomCost();
    QString getRoomType();
    int getStatus();
    void setRoomId(int roomId);
    void setStatus(int status);
    void setDiscount(double discount);
    void setRoomCost(double roomCost);
    void setRoomType(QString roomType);
    QString getGuestsId();
    void setGuestsId(QString guestsId);
    ~Room();
};

#endif // ROMM_H
