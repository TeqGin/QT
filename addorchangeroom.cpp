#include "addorchangeroom.h"
#include "ui_addorchangeroom.h"
#include"sql.h"
#include"domain.h"
#include"changeroomdata.h"
#include"operata.h"

AddOrChangeRoom::AddOrChangeRoom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddOrChangeRoom)
{
    ui->setupUi(this);
    connect(this->ui->submit,SIGNAL(clicked()),this,SLOT(submitMessage()));
}

AddOrChangeRoom::~AddOrChangeRoom()
{
    delete ui;
}

void AddOrChangeRoom::creatBasicMessage(const QString title){
    this->ui->title->setText(title);
}

//提交房间信息
/*
 * @Question:
 *  提交的数据分为两种
 *  @First
 *  原本已存在的数据
 *  @Second
 *  新的数据
 *  @solve
 *  判断数据库中是否存在和提交过来的数据相等的roomId
 * @Warning
 *  需要判空的数据: roomId、roomCost
*/
void AddOrChangeRoom::submitMessage(){
    int roomId =this->ui->roomId->text().toInt();
    QString roomType=this->ui->roomType->text();
    double discount=this->ui->discount->text().toDouble();
    if(discount==0.0){
        discount=1;
    }
    double roomCost=this->ui->roomCost->text().toDouble();
    //获取当前comBox的值
    QString statusStr=this->ui->status->currentText();
    int status=1;
    if(statusStr=="可入住"){
        status=1;
    }else if(statusStr=="不可入住"){
        status=0;
    }else{
        status=2;
    }
    QString guestsId=this->ui->guestsId->text();
    //查找数据库中是否有当前房间的信息
    if(roomId==0||roomCost==0.0||roomType==""){
        QMessageBox::warning(this,"错误","房号或价格或房间类型不能为空");
        return ;
    }
    RoomSql roomSql;
    Room confirm=roomSql.findRoombyId(roomId);

    if(confirm.getRoomId()==roomId){
        //更新操作
        Room room(roomId,discount,roomCost,roomType,status,guestsId);
        roomSql.update(room);
        QMessageBox::about(this,"成功","更新成功！");
        this->close();
    }else {
        //插入操作
        Room room(roomId,discount,roomCost,roomType,status,guestsId);
        roomSql.insert(room);
        QMessageBox::about(this,"成功","插入成功！");
        this->close();
    }
    return ;
}

void AddOrChangeRoom::consistUpdateRoom(Room room){
    this->ui->title->setText("修改房间信息");
    this->ui->roomId->setText(QString::number(room.getRoomId()));
    this->ui->discount->setText(QString::number(room.getDiscount()));
    this->ui->roomCost->setText(QString::number(room.getRoomCost()));
    this->ui->roomType->setText(room.getRoomType());
    QString str="";
    if(room.getStatus()==0){
        str="不可入住";
    }else if(room.getStatus()==1){
        str="可入住";
    }else{
        str="维修中";
    }
    this->ui->status->setCurrentText(str);
    this->ui->guestsId->setText(room.getGuestsId());
}
