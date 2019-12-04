#include "changeroomdata.h"
#include "ui_changeroomdata.h"
#include"chargeface.h"

ChangeRoomData::ChangeRoomData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeRoomData)
{
    ui->setupUi(this);
    connect(this->ui->back,SIGNAL(clicked()),this,SLOT(returnMain()));
    connect(this->ui->change,SIGNAL(clicked()),this,SLOT(updateRoom()));
    connect(this->ui->remove,SIGNAL(clicked()),this,SLOT(removeRoom()));
    connect(this->ui->addRoom,SIGNAL(clicked()),this,SLOT(addRoom()));
    connect(this->ui->dataOutput,SIGNAL(clicked()),this,SLOT(outputData()));
}

ChangeRoomData::~ChangeRoomData()
{
    delete ui;
}

void ChangeRoomData::returnMain(){
    chargeFace=new ChargeFace;
    this->close();
    chargeFace->show();

}

void ChangeRoomData::creatTable(){
    Operata operata;
    RoomSql roomSql;
    std::vector<Room> roomVector=roomSql.findAllRoom();
   operata.showRoomData(roomTable,roomVector,this,x,y);
}

void ChangeRoomData::updateRoom(){
    int row=this->roomTable->currentIndex().row();
    QAbstractItemModel *model = roomTable->model ();
    QModelIndex index = model->index(row,0);//选中行第一列的内容
    int roomId = model->data(index).toInt();
    qDebug()<<row;

    if(row==-1){
        QMessageBox::warning(this,"警告","请选择一条记录");
    }else{
        RoomSql roomSql;
        Room room=roomSql.findRoombyId(roomId);
        addOrChangeRoom=new AddOrChangeRoom;
        addOrChangeRoom->consistUpdateRoom(room);
        addOrChangeRoom->show();
        addOrChangeRoom->exec();
        Operata operata;
        std::vector<Room> roomVector=roomSql.findAllRoom();
        operata.showRoomData(roomTable,roomVector,this,x,y);
    }
}
void ChangeRoomData::removeRoom(){

    int row=this->roomTable->currentIndex().row();
    //获取roomTable的model
    QAbstractItemModel * model=roomTable->model();
    QModelIndex index=model->index(row,0);

    //获取roomId
    int roomId=model->data(index).toInt();

    //如果没有选择任何一条记录则row的值为-1
    if(row!=-1){
    RoomSql roomSql;
    Operata operata;
    roomSql.deleteById(roomId);
    //QString和int相互转换使用QString的静态方法
    QMessageBox::about(this,"删除成功","删除"+QString::number(roomId)+"房间成功");
    std::vector<Room> roomVector=roomSql.findAllRoom();
    operata.showRoomData(roomTable,roomVector,this,x,y);
    }else{
    QMessageBox::warning(this,"删除失败","请选择一条记录");
    }
}

void ChangeRoomData::addRoom(){
    this->addOrChangeRoom=new AddOrChangeRoom;
    addOrChangeRoom->creatBasicMessage("添加房间信息");
    addOrChangeRoom->show();
    addOrChangeRoom->exec();
    RoomSql roomSql;
    Operata operata;
    std::vector<Room> roomVector=roomSql.findAllRoom();
    operata.showRoomData(roomTable,roomVector,this,x,y);
}
void ChangeRoomData::outputData(){

}
