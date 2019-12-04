#ifndef CHANGEROOMDATA_H
#define CHANGEROOMDATA_H

#include <QDialog>
#include<QTableView>
#include"addorchangeroom.h"
class ChargeFace;

namespace Ui {
class ChangeRoomData;
}

class ChangeRoomData : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeRoomData(QWidget *parent = nullptr);
    ~ChangeRoomData();
    void creatTable();

private slots:
    void returnMain();
    void updateRoom();
    void removeRoom();
    void addRoom();
    void outputData();

private:
    Ui::ChangeRoomData *ui;
    ChargeFace * chargeFace;
    QTableView *roomTable=new QTableView;
    AddOrChangeRoom *addOrChangeRoom;
    int x=85;
    int y=85;
};

#endif // CHANGEROOMDATA_H
