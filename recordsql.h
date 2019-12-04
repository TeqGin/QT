#ifndef RECORDSQL_H
#define RECORDSQL_H
#include"domain.h"


class RecordSql
{
private:
    DButil dbutil;
public:
    RecordSql();

    std::vector<Record> findAllRecord();
    std::vector<Record> findRecordByRoomIdAndGuestsIdAndFlag(int roomId,QString guestsId,int flag);
    bool insert(Record record);
    bool update(Record record);

};

#endif // RECORDSQL_H
