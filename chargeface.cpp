#include "chargeface.h"
#include "ui_chargeface.h"

ChargeFace::ChargeFace(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChargeFace)
{
    ui->setupUi(this);
    connect(this->ui->searchData,SIGNAL(clicked()),this,SLOT(selectData()));
    connect(this->ui->changeData,SIGNAL(clicked()),this,SLOT(changeData()));
}

ChargeFace::~ChargeFace()
{
    delete ui;
}

/*
 *
 * */
void ChargeFace::selectData(){
    this->roomData=new RoomData();
    this->close();
    //禁用关闭按钮
    this->roomData->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinMaxButtonsHint);

    roomData->creatTable();

    this->roomData->show();
    this->roomData->exec();
}

void ChargeFace::changeData(){
    this->changeRoomData=new ChangeRoomData;
    this->close();
    changeRoomData->creatTable();

    this->changeRoomData->show();
    this->changeRoomData->exec();
}

void ChargeFace::eraseRoom(){

}

void ChargeFace::showName(QString name){
    this->ui->login_name->setText("你好,"+name+"管理员");
}
