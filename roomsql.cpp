#include "roomsql.h"
#include<iostream>


RoomSql::RoomSql(){

}

bool RoomSql::deleteById(int roomId){
    QSqlDatabase db=dbutil.getDatabase();
    QString sql="delete from room where id=?";
    QSqlQuery query;
    query.prepare(sql);
    query.addBindValue(roomId);
    if(query.exec()){
        db.close();
        return true;
    }
    db.close();
    return false;
}

bool RoomSql::insert(Room room){
    QSqlDatabase db=dbutil.getDatabase();
    QString sql="insert into room(id,discount,room_cost,room_type,status,guests_id) values(?,?,?,?,?,?)";
    QSqlQuery query;
    query.prepare(sql);
    query.addBindValue(room.getRoomId());
    query.addBindValue(room.getDiscount());
    query.addBindValue(room.getRoomCost());
    query.addBindValue(room.getRoomType());
    query.addBindValue(room.getStatus());
    query.addBindValue(room.getGuestsId());

    if(query.exec()){
        db.close();
        return true;
    }
    db.close();
    return false;
}

bool RoomSql::update(Room room){
    QSqlDatabase db=dbutil.getDatabase();
    QString sql="update room set discount=?,room_cost=?,room_type=?,status=?,guests_id=? where id=?";
    QSqlQuery query;
    query.prepare(sql);
    query.addBindValue(room.getDiscount());
    query.addBindValue(room.getRoomCost());
    query.addBindValue(room.getRoomType());
    query.addBindValue(room.getStatus());
    query.addBindValue(room.getGuestsId());
    query.addBindValue(room.getRoomId());

    if(query.exec()){
        db.close();
        return true;
    }
    db.close();
    return false;
}

Room RoomSql::findRoombyId(int id){
    QSqlDatabase db;
    db=dbutil.getDatabase();
    QString sql="select * from room where id=?";
    QSqlQuery query;
    query.prepare(sql);
    query.addBindValue(id);
    if(query.exec()){
        //由于数据库查找完毕以后停在第一条记录之前，所以需要先用query.next()把记录向后移动
        if(query.next()){
        Room room(
                    query.value("id").toInt(),
                    query.value("discount").toDouble(),
                    query.value("room_cost").toDouble(),
                    query.value("room_type").toString(),
                    query.value("status").toInt(),
                    query.value("guests_id").toString()
                  );
        db.close();
        return room;
        }else{
            db.close();
            return Room();
        }
    }else {
        db.close();
        return Room();
    }
}

std::vector<Room> RoomSql::findAllRoom(){
    QSqlDatabase db=dbutil.getDatabase();
    QString sql="select * from room";
    QSqlQuery query;
    std::vector<Room> roomVector;
    if(query.exec(sql)){
        while(query.next()){
            Room room(
                        query.value("id").toInt(),
                        query.value("discount").toDouble(),
                        query.value("room_cost").toDouble(),
                        query.value("room_type").toString(),
                        query.value("status").toInt(),
                        query.value("guests_id").toString()
                      );
            roomVector.push_back(room);
        }
    }
    db.close();
    return roomVector;
}

std::vector<Room> RoomSql::findRoomByRoomType(QString roomType){
    QSqlDatabase db=dbutil.getDatabase();
    QString sql="select * from room where room_type=?";
    QSqlQuery query;
    std::vector<Room> roomVector;
    query.prepare(sql);
    query.addBindValue(roomType);
    if(query.exec()){
        while(query.next()){
            Room room(
                        query.value("id").toInt(),
                        query.value("discount").toDouble(),
                        query.value("room_cost").toDouble(),
                        query.value("room_type").toString(),
                        query.value("status").toInt(),
                        query.value("guests_id").toString()
                      );
            roomVector.push_back(room);
        }
    }
    db.close();
    return roomVector;
}

std::vector<Room> RoomSql::findRoomByStatus(int status){
    QSqlDatabase db=dbutil.getDatabase();
    QString sql="select * from room where status=?";
    QSqlQuery query;
    std::vector<Room> roomVector;
    query.prepare(sql);
    query.addBindValue(status);
    if(query.exec()){
        while(query.next()){
            Room room(
                        query.value("id").toInt(),
                        query.value("discount").toDouble(),
                        query.value("room_cost").toDouble(),
                        query.value("room_type").toString(),
                        query.value("status").toInt(),
                        query.value("guests_id").toString()
                      );
            roomVector.push_back(room);
        }
    }
    db.close();
    return roomVector;
}

std::vector<Room> RoomSql::findRoomByDiscount(double maxDiscount, double minDiscount){
    QSqlDatabase db=dbutil.getDatabase();
    QString sql="select * from room where discount>=? and discount<=?";
    QSqlQuery query;
    std::vector<Room> roomVector;
    query.prepare(sql);
    query.addBindValue(minDiscount);
    query.addBindValue(maxDiscount);
    if(query.exec()){
        while(query.next()){
            Room room(
                        query.value("id").toInt(),
                        query.value("discount").toDouble(),
                        query.value("room_cost").toDouble(),
                        query.value("room_type").toString(),
                        query.value("status").toInt(),
                        query.value("guests_id").toString()
                      );
            roomVector.push_back(room);
        }
    }
    db.close();
    return roomVector;
}

std::vector<Room> RoomSql::findRoomByGuestsId(QString guestsId){
    QSqlDatabase db;
    db=dbutil.getDatabase();
    QString sql="select * from room where guests_id=?";
    QSqlQuery query;
    std::vector<Room> roomVector;
    query.prepare(sql);
    query.addBindValue(guestsId);
    if(query.exec()){
        //由于数据库查找完毕以后停在第一条记录之前，所以需要先用query.next()把记录向后移动
        while(query.next()){
            Room room(
                        query.value("id").toInt(),
                        query.value("discount").toDouble(),
                        query.value("room_cost").toDouble(),
                        query.value("room_type").toString(),
                        query.value("status").toInt(),
                        query.value("guests_id").toString()
                      );
            roomVector.push_back(room);
        }
    }
    db.close();
    return roomVector;
}

std::vector<Room> RoomSql::findRoomByRoomCost(double maxCost, double minCost){
    QSqlDatabase db=dbutil.getDatabase();
    QString sql="select * from room where room_cost>=? and room_cost<=?";
    QSqlQuery query;
    std::vector<Room> roomVector;
    query.prepare(sql);
    query.addBindValue(minCost);
    query.addBindValue(maxCost);

    if(query.exec()){
        while(query.next()){
            Room room(
                        query.value("id").toInt(),
                        query.value("discount").toDouble(),
                        query.value("room_cost").toDouble(),
                        query.value("room_type").toString(),
                        query.value("status").toInt(),
                        query.value("guests_id").toString()
                      );
            roomVector.push_back(room);
        }
    }
    db.close();
    return roomVector;
}






