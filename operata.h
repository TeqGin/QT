#ifndef OPERATA_H
#define OPERATA_H
#include<vector>
#include<vector>
#include"room.h"
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
};

#endif // OPERATA_H
