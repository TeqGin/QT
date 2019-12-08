#include "roomdata.h"
#include "ui_roomdata.h"
#include"chargeface.h"
#include"whole.h"
#include<QInputDialog>

RoomData::RoomData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RoomData)
{
    ui->setupUi(this);
    connect(this->ui->returnMain,SIGNAL(clicked()),this,SLOT(returnMain()));
    connect(this->ui->submit,SIGNAL(clicked()),this,SLOT(submitSelect()));
    connect(this->ui->dataOutput,SIGNAL(clicked()),this,SLOT(outputData()));
}

RoomData::~RoomData()
{
    delete ui;
}

void RoomData::returnMain(){
    chargeFace=new ChargeFace;
    this->close();
    UserSql userSql;
    chargeFace->showName(userSql.findUserById(Whole::id).getName());
    chargeFace->show();
    chargeFace->exec();
    chargeFace->close();
}
void RoomData::creatTable(){
    Operata operata;
    RoomSql roomSql;
    std::vector<Room> roomVector=roomSql.findAllRoom();
    operata.showRoomData(roomTable,roomVector,this,x,y);
}


void RoomData::submitSelect(){
    QString select=this->ui->find->currentText();
    if(select=="根据房号"){
        bool roomIdOk;
        int roomId = QInputDialog::getText(this, "根据房号查找","请输入房号",QLineEdit::Normal,"",&roomIdOk).toInt();
        if(!roomIdOk) return;
        RoomSql roomSql;
        std::vector<Room> roomVector;
        if(roomSql.findRoombyId(roomId).getRoomId()==roomId)
        roomVector.push_back(roomSql.findRoombyId(roomId));
        Operata operata;
        operata.showRoomData(roomTable,roomVector,this,x,y);
    }else if(select=="根据房间类型"){
        bool roomTypeOk;
        std::string roomTypeStr = QInputDialog::getText(this, "根据房间类型","请输入房间类型",QLineEdit::Normal,"根据房间类型",&roomTypeOk).toStdString();
        if(!roomTypeOk) return;
        RoomSql roomSql;

        QString roomType=QString::fromStdString(roomTypeStr);
        std::vector<Room> roomVector=roomSql.findRoomByRoomType(roomType);
        Operata operata;
        operata.showRoomData(roomTable,roomVector,this,x,y);
    }else if(select=="根据房间价格"){
        bool roomCostMinOk;
        double roomCostMin = QInputDialog::getText(this, "根据房间价格","请输入价格最小值",QLineEdit::Normal,"",&roomCostMinOk).toDouble();
        if(!roomCostMinOk) return;
        bool roomCostMaxOk;
        double roomCostMax = QInputDialog::getText(this, "根据房间价格","请输入价格最大值",QLineEdit::Normal,"",&roomCostMaxOk).toDouble();
        if(!roomCostMaxOk) return;
        RoomSql roomSql;
        std::vector<Room> roomVector=roomSql.findRoomByRoomCost(roomCostMax,roomCostMin);

        Operata operata;
        operata.showRoomData(roomTable,roomVector,this,x,y);
    }else if(select=="根据房间状态"){
        bool roomStatsOk;
        std::string roomStats = QInputDialog::getText(this, "根据房间状态","请输入房间状态",QLineEdit::Normal,"",&roomStatsOk).toStdString();
        if(!roomStatsOk) return;

        int status;
        if(roomStats=="可入住"){
            status=1;
        }else if(roomStats=="不可入住"){
            status=0;
        }else if(roomStats=="维修中"){
            status=2;
        }else{
            QMessageBox::warning(this,"警告","输入的状态不存在!");
            return ;
        }

        RoomSql roomSql;
        std::vector<Room> roomVector=roomSql.findRoomByStatus(status);

        Operata operata;
        operata.showRoomData(roomTable,roomVector,this,x,y);
    }else if(select=="根据折扣"){
        bool roomDiscountMinOk;
        double roomDiscountMin = QInputDialog::getText(this, "根据折扣查找","请输入折扣最小值",QLineEdit::Normal,"",&roomDiscountMinOk).toDouble();
        if(!roomDiscountMinOk) return;

        bool roomDiscountMaxOk;
        double roomDiscountMax = QInputDialog::getText(this, "根据折扣查找","请输入折扣最大值",QLineEdit::Normal,"",&roomDiscountMaxOk).toDouble();
        if(!roomDiscountMaxOk) return;
        RoomSql roomSql;
        std::vector<Room> roomVector=roomSql.findRoomByDiscount(roomDiscountMax,roomDiscountMin);


        Operata operata;
        operata.showRoomData(roomTable,roomVector,this,x,y);
    }else if(select=="查询全部"){
        RoomSql roomSql;
        std::vector<Room> roomVector=roomSql.findAllRoom();

        Operata operata;
        operata.showRoomData(roomTable,roomVector,this,x,y);
    }else{
        QMessageBox::warning(this,"出错了","出错了！");
        return ;
    }
    QMessageBox::about(this,"查找成功","查找成功！");
    return ;
}

void RoomData::outputData(){
    QAbstractItemModel * model=roomTable->model();
    Operata operata;

    //把文件导出到上一级目录中（到当前目录失败）
    QString fileName="../"+Date().toString()+"导出的房间数据"+".txt";
    bool isSuccess=operata.writeIntoTxt(model,fileName);
    if(isSuccess){
        QMessageBox::about(this,"成功","导出成功");
    }else{
        QMessageBox::warning(this,"失败","导出失败");
    }
}

void RoomData::on_selectReport_clicked()
{
    this->recordDataPtr=new recordData;
    this->close();
    recordDataPtr->creatTable();
    recordDataPtr->show();
    recordDataPtr->exec();
}
