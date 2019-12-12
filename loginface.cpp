#include "loginface.h"
#include "ui_loginface.h"
#include"sql.h"
#include"operata.h"

LoginFace::LoginFace(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginFace)
{
    ui->setupUi(this);
}

LoginFace::~LoginFace()
{
    delete ui;
}
//实例化tableView
void LoginFace::creatTable(){
    Operata operata;
    RoomSql roomSql;
    std::vector<Room> roomVector=roomSql.findAllRoom();
   operata.showRoomData(roomTable,roomVector,this);
}
