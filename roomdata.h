#ifndef ROOMDATA_H
#define ROOMDATA_H

#include <QDialog>
#include<QTableView>
class ChargeFace;

namespace Ui {
class RoomData;
}

class RoomData : public QDialog
{
    Q_OBJECT

public:
    explicit RoomData(QWidget *parent = nullptr);
    ~RoomData();
    void creatTable();
private slots:
    void returnMain();
    void submitSelect();


private:
    QTableView *roomTable=new QTableView;
    Ui::RoomData *ui;
    ChargeFace *chargeFace;
    int x=110;
    int y=85;
};

#endif // ROOMDATA_H
