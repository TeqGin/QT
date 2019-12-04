#ifndef ADDORCHANGEROOM_H
#define ADDORCHANGEROOM_H

#include <QDialog>
#include"domain.h"
class ChangeRoomData;

namespace Ui {
class AddOrChangeRoom;
}

class AddOrChangeRoom : public QDialog
{
    Q_OBJECT

public:
    explicit AddOrChangeRoom(QWidget *parent = nullptr);
    ~AddOrChangeRoom();
    void creatBasicMessage(const QString title);
    void consistUpdateRoom(Room room);

private slots:
    void submitMessage();
private:
    Ui::AddOrChangeRoom *ui;
    ChangeRoomData *changeRoomData;
};

#endif // ADDORCHANGEROOM_H
