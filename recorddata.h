#ifndef RECORDDATA_H
#define RECORDDATA_H

#include <QDialog>
#include<QTableView>
#include"domain.h"
#include"sql.h"
#include"operata.h"

class RoomData;
class ChargeFace;
namespace Ui {
class recordData;
}

class recordData : public QDialog
{
    Q_OBJECT

public:
    explicit recordData(QWidget *parent = nullptr);
    ~recordData();
    void creatTable();

private slots:
    void on_selectRoomData_clicked();

    void on_dataOutput_clicked();

    void on_returnMain_clicked();

    void on_submit_clicked();

private:
    ChargeFace *chargeFace;
    QTableView *recordTable;
    Ui::recordData *ui;
    RoomSql roomSql;
    RecordSql recordSql;
    Operata operata;
    RoomData * roomData;


    int x=110;
    int y=85;

};

#endif // RECORDDATA_H
