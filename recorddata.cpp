#include "recorddata.h"
#include "ui_recorddata.h"
#include"roomdata.h"
#include"chargeface.h"
#include"date.h"

recordData::recordData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::recordData)
{
    this->recordTable=new QTableView;
    ui->setupUi(this);
}

recordData::~recordData()
{
    delete ui;
}

void recordData::creatTable(){
    std::vector<Record> recordVector=recordSql.findAllRecord();
    operata.showRrecordData(this->recordTable,recordVector,this,x,y);
}
//查找房间信息
void recordData::on_selectRoomData_clicked()
{
    this->roomData=new RoomData;
    this->close();
    roomData->creatTable();
    roomData->show();
}
//数据导出
void recordData::on_dataOutput_clicked()
{
    if(operata.writeIntoTxt(this->recordTable->model(),"../"+Date().toString()+"导出的报表数据"+".txt")){
        QMessageBox::about(this,"成功","导出成功");
    }else{
        QMessageBox::warning(this,"失败","导出失败");
    }
}

void recordData::on_returnMain_clicked()
{
    this->close();
    this->chargeFace=new ChargeFace;
    chargeFace->show();
}
//条件查询
void recordData::on_submit_clicked()
{
    QString select=this->ui->find->currentText();
    if("全部数据"==select){
        this->creatTable();
    }else if("近一周"==select){
        std::vector<Record> recordVector=recordSql.findAllRecord();
        std::vector<Record> recordVectorRear;
         Date weekBefore=Date()-7;
        for(int i=0;i<recordVector.size();i++){
            Date coml=recordVector[i].getOutTime();
            if(coml>weekBefore){
                recordVectorRear.push_back(recordVector[i]);
            }
        }
        operata.showRrecordData(this->recordTable,recordVectorRear,this,x,y);
    }else if("近一月"==select){
        std::vector<Record> recordVector=recordSql.findAllRecord();
        std::vector<Record> recordVectorRear;

        Date monthBefore=Date()-31;
        for(int i=0;i<recordVector.size();i++){
            Date coml=recordVector[i].getOutTime();
            if(coml>monthBefore){
                recordVectorRear.push_back(recordVector[i]);
            }
        }
        operata.showRrecordData(this->recordTable,recordVectorRear,this,x,y);
    }else{
        QMessageBox::warning(this,"出错了","出错了！");
        return ;
    }
    QMessageBox::about(this,"查找成功","查找成功！");
    return ;
}
