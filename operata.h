#ifndef OPERATA_H
#define OPERATA_H
#include<vector>
#include<vector>
#include"room.h"
#include"record.h"
#include<QMessageBox>
#include<QCompleter>
#include<QTableView>
#include<QItemDelegate>
#include<QPainter>
#include<QStandardItemModel>

class Operata
{
public:
    Operata();
    int showRoomData(QTableView *roomTable,std::vector<Room>roomVector,QDialog * parent,int x=0,int y=70);
    int showRrecordData(QTableView *recordTable,std::vector<Record>recordVector,QDialog * parent,int x=0,int y=70);
    bool outDataToExcel(const QAbstractItemModel * model,const QString & fileName);
    bool writeIntoTxt(const QAbstractItemModel * model,const QString & fileName);
};

#endif // OPERATA_H
