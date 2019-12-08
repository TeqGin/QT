#include "recordsql.h"
#include"date.h"

RecordSql::RecordSql()
{

}

bool RecordSql::insert(Record record){
    QSqlDatabase db=dbutil.getDatabase();
    QString sql="insert into record(guests_id,guests_name,room_id,room_discount,room_cost,room_type,in_time,out_date,flag) values(?,?,?,?,?,?,?,?,?)";
    QSqlQuery query;
    query.prepare(sql);

    query.addBindValue(record.getGuestsId());
    query.addBindValue(record.getName());
    query.addBindValue(record.getRoomId());
    query.addBindValue(record.getDiscount());
    query.addBindValue(record.getRoomCost());
    query.addBindValue(record.getRoomType());
    query.addBindValue(record.getInTime().toString());
    query.addBindValue(record.getOutTime().toString());
    query.addBindValue(record.getFlag());

    db.close();
    if(query.exec()){
        return true;
    }
    return false;
}

bool RecordSql::update(Record record){
    QSqlDatabase db=dbutil.getDatabase();
    QString sql="update record set guests_id=?,guests_name=?,room_id=?,room_discount=?,room_cost=?,room_type=?,in_time=?,out_date=?,flag=? where id=?";
    QSqlQuery query;
    query.prepare(sql);

    query.addBindValue(record.getGuestsId());
    query.addBindValue(record.getName());
    query.addBindValue(record.getRoomId());
    query.addBindValue(record.getDiscount());
    query.addBindValue(record.getRoomCost());
    query.addBindValue(record.getRoomType());
    query.addBindValue(record.getInTime().toString());
    query.addBindValue(record.getOutTime().toString());
    query.addBindValue(record.getFlag());
    query.addBindValue(record.getRecordId());

    db.close();
    if(query.exec()){
        return true;
    }
    return false;
}

std::vector<Record> RecordSql::findAllRecord(){
    QSqlDatabase db=dbutil.getDatabase();
    QString sql="select * from record";
    QSqlQuery query;
    std::vector<Record> recordVector;
    if(query.exec(sql)){
        while(query.next()){
            QString date1=query.value("in_time").toString();
            int date1Year=date1.section('-',0,0).toInt();
            int date1Month=date1.section('-',1,1).toInt();
            int date1Day=date1.section('-',2,2).toInt();
            Date inTime(date1Year,date1Month,date1Day);

            QString date2=query.value("out_date").toString();
            int date2Year=date2.section('-',0,0).toInt();
            int date2Month=date2.section('-',1,1).toInt();
            int date2Day=date2.section('-',2,2).toInt();
            Date outTime(date2Year,date2Month,date2Day);

            Record record(
                        query.value("guests_id").toString(),
                        query.value("guests_name").toString(),
                        query.value("room_id").toInt(),
                        query.value("room_discount").toDouble(),
                        query.value("room_cost").toDouble(),
                        query.value("room_type").toString(),
                        inTime,
                        outTime,
                        query.value("flag").toInt()
                        );
            recordVector.push_back(record);
        }
    }
    db.close();
    qDebug()<<recordVector.size();
    return recordVector;
}

std::vector<Record> RecordSql::findRecordByRoomIdAndGuestsIdAndFlag(int roomId, QString guestsId, int flag){
       QSqlDatabase db=dbutil.getDatabase();
       QString sql="select * from record where room_id=? and guests_id=? and flag=?";
       QSqlQuery query;
       std::vector<Record> recordVector;
       query.prepare(sql);
       query.addBindValue(roomId);
       query.addBindValue(guestsId);
       query.addBindValue(flag);
       if(query.exec()){
               while(query.next()){
                   QString date1=query.value("in_time").toString();
                   int date1Year=date1.section('-',0,0).toInt();
                   int date1Month=date1.section('-',1,1).toInt();
                   int date1Day=date1.section('-',2,2).toInt();
                   Date inTime(date1Year,date1Month,date1Day);

                   QString date2=query.value("in_time").toString();
                   int date2Year=date1.section('-',0,0).toInt();
                   int date2Month=date1.section('-',1,1).toInt();
                   int date2Day=date1.section('-',2,2).toInt();
                   Date outTime(date2Year,date2Month,date2Day);

                   Record record(
                               query.value("guests_id").toString(),
                               query.value("guests_name").toString(),
                               query.value("room_id").toInt(),
                               query.value("room_discount").toDouble(),
                               query.value("room_cost").toDouble(),
                               query.value("room_type").toString(),
                               inTime,
                               outTime,
                               query.value("flag").toInt()
                               );
                   recordVector.push_back(record);
           }
       }
           db.close();
           return recordVector;
}

