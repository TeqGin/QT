#include "guests.h"
#include"sql.h"
#include"domain.h"

Guests::Guests()
{

}
Guests::Guests(QString name,QString id,QString sex,QString passWord):Person (name,id,sex,passWord){
    setRole(1);
}

bool Guests::BuyRoom(int roomId, Date inDate, Date outDate){
    //插入语句
    //先查找该房间
    RoomSql roomSql;
    Room room=roomSql.findRoombyId(roomId);
    if(room.getStatus()==1){
    //构建该记录
    RecordSql recordSql;
    Record record(
                this->getPersonId(),
                this->getName(),
                room.getRoomId(),
                room.getDiscount(),
                room.getRoomCost(),
                room.getRoomType(),
                inDate,
                outDate,
                1
                );
    //插入该记录
    recordSql.insert(record);
    //改变房间状态
    room.setStatus(0);
    roomSql.update(room);
    return true;
    }
    return false;
}

bool Guests::leaveRoom(int roomId){
    //查找该条记录
    RecordSql recordSql;
    RoomSql roomSql;
    std::vector<Record> recordVector=recordSql.findRecordByRoomIdAndGuestsIdAndFlag(roomId,this->getPersonId(),1);
    if(recordVector.size()==1){
        Record record=recordVector[0];
        record.setFlag(0);
        recordSql.update(record);
        Room room=roomSql.findRoombyId(roomId);
        room.setStatus(1);
        roomSql.update(room);
        return true;
    }
    return false;
}

/*
void Guests::BuyRoom(int roomId, Date inDate, Date outDate){
    roomNode *p=hisRooms;
    while(p->next==nullptr){
        p=p->next;
    }

    roomNode *current=new roomNode;
    current->roomId=roomId;
    current->inDate=inDate;
    current->outDate=outDate;
    current->stayTime=outDate-inDate;
    current->next=nullptr;

    p->next=current;
}


bool Guests::leaveRoom(int roomId){
    roomNode *p=hisRooms;
    roomNode *current=hisRooms->next;
    bool flag=false;
    //遍历查找roomId为所寻找的房间的元素
    while(current){
        if(current->roomId==roomId){
            p->next=current->next;
            delete current;
            flag=true;
            break;
        }else{
            p=p->next;
            current=current->next;
        }
    }
    return flag;
}

*/





