#ifndef ROOMSQL_H
#define ROOMSQL_H
#include<vector>
#include<room.h>
#include"db_connect.h"


class RoomSql
{
private:
    DButil dbutil;
public:
    RoomSql();

    bool insert(Room room);
    bool update(Room room);
    bool deleteById(int roomId);

    Room findRoombyId(int id);
    std::vector<Room> findAllRoom();
    std::vector<Room> findRoomByStatus(int status);
    std::vector<Room> findRoomByRoomType(QString roomType);
    std::vector<Room> findRoomByGuestsId(QString guestsId);
    std::vector<Room> findRoomByRoomCost(double maxCost,double minCost);
    std::vector<Room> findRoomByDiscount(double maxDiscount,double minDiscount);


};

#endif // ROOMSQL_H
