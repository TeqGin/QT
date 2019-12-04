#ifndef CHARGEFACE_H
#define CHARGEFACE_H
#include <QDialog>
#include"roomdata.h"
#include"domain.h"
#include"sql.h"
#include"changeroomdata.h"

namespace Ui {
class ChargeFace;
}

class ChargeFace : public QDialog
{
    Q_OBJECT

public:
    explicit ChargeFace(QWidget *parent = nullptr);
    ~ChargeFace();
    void eraseRoom();


private slots:
    void selectData();
    void changeData();
private:
    Ui::ChargeFace *ui;
    RoomData *roomData;
    ChangeRoomData *changeRoomData;

    Operata operata;
    RoomSql roomSql;

};

#endif // CHARGEFACE_H
