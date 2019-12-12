#include "operata.h"
#include"outtoexcel.h"
#include"date.h"
#include<QFile>
#include<QDebug>
#include<QDateTime>

//这个单词打错了。。。
Operata::Operata()
{

}
int Operata::showRoomData(QTableView *roomTable,std::vector<Room>roomVector,QDialog * parent,int x,int y){
    QStandardItemModel* model = new QStandardItemModel();

  //显示所有room数据
  QStandardItem* item = 0;
  for(int i = 0;i <roomVector.size() ;i++){

      QString roomIdStr=QString::number(roomVector[i].getRoomId());
      item = new QStandardItem(roomIdStr);
      model->setItem(i,0,item);

      QString discountStr=QString::number(roomVector[i].getDiscount(),10,2);
      item = new QStandardItem(discountStr);
      model->setItem(i,1,item);

      QString costStr=QString::number(roomVector[i].getRoomCost(),10,2);
      item = new QStandardItem(costStr);
      model->setItem(i,2,item);

      item = new QStandardItem(roomVector[i].getRoomType());
      model->setItem(i,3,item);

      QString statusStr;
      if(roomVector[i].getStatus()==1){
          statusStr="可入住";
      }else{
          statusStr="不可入住";
      }
      item = new QStandardItem(statusStr);
      model->setItem(i,4,item);

      QString guestsIdStr="无入住客户";
      if(roomVector[i].getGuestsId()!=""){
          guestsIdStr=roomVector[i].getGuestsId();
      }

      item = new QStandardItem(guestsIdStr);
      model->setItem(i,5,item);
  }
  //指定父窗口
  roomTable->setParent(parent);
  //表格横线类型
  roomTable->setShowGrid(Qt::DotLine);
  roomTable->setSelectionBehavior ( QAbstractItemView::SelectRows); //设置选择行为，以行为单位
  roomTable->setModel(model);
  roomTable->resize(parent->width(),parent->height());
  roomTable->setStyleSheet("QTableView { border: none;"
                          "selection-background-color: #8EDE21;"
                          "color: blue}");
  roomTable->setGeometry(x,y,parent->width(),parent->height());
  QItemDelegate* readOnlyDelegate = new QItemDelegate();
  roomTable->setItemDelegate(readOnlyDelegate);
  roomTable->show();
  roomTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
  QStringList labels = QObject::trUtf8("房号,折扣,价格,房间类型,房间状态,入住客户").simplified().split(",");
   model->setHorizontalHeaderLabels(labels);
   return 0;
}


bool Operata::outDataToExcel(const QAbstractItemModel *model, const QString &fileName){
    //新建excel
     outToExcel toExcel;
     toExcel.newExcel(fileName);
     toExcel.appendSheet("房间数据");
     int row =model->rowCount();
     int column=model->columnCount();
     for (int i=0;i<row;i++) {
         for(int j=0;j<column;j++){
             QModelIndex idnex=model->index(i,j);
             toExcel.setCellValue(i,j,model->data(idnex).toString());
         }
     }
     toExcel.saveExcel(fileName);
     toExcel.freeExcel();
     return true;
}

bool Operata::writeIntoTxt(const QAbstractItemModel *model, const QString &fileName){
    QFile file(fileName);
    if(file.open(QIODevice::WriteOnly|QIODevice::Text)){
        QTextStream out(&file);
        int row =model->rowCount();
        int column=model->columnCount();
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                QModelIndex index=model->index(i,j);
               out<<model->data(index).toString()<<" ";
            }
            out<<endl;
        }
        return true;
    }
    return false;
}

int Operata::showRrecordData(QTableView *recordTable,std::vector<Record> recordVector, QDialog *parent, int x, int y){
    QStandardItemModel * model= new QStandardItemModel;

    //显示所有record数据
    QStandardItem *item=nullptr;

    for(int i=0;i<recordVector.size();i++){

        QString guestsIdStr=recordVector[i].getGuestsId();
        item=new QStandardItem(guestsIdStr);
        model->setItem(i,0,item);

        QString guestsNameStr=recordVector[i].getName();
        item=new QStandardItem(guestsNameStr);
        model->setItem(i,1,item);

        QString roomIdStr=QString::number(recordVector[i].getRoomId());
        item=new QStandardItem(roomIdStr);
        model->setItem(i,2,item);

        QString roomDiscountStr=QString::number(recordVector[i].getDiscount());
        item=new QStandardItem(roomDiscountStr);
        model->setItem(i,3,item);

        QString roomCostStr=QString::number(recordVector[i].getRoomCost());
        item=new QStandardItem(roomCostStr);
        model->setItem(i,4,item);

        QString roomTypeStr=recordVector[i].getRoomType();
        item=new QStandardItem(roomTypeStr);
        model->setItem(i,5,item);

        QString inDateStr=recordVector[i].getInTime().toString();
        item=new QStandardItem(inDateStr);
        model->setItem(i,6,item);

        QString outDateStr=recordVector[i].getOutTime().toString();
        item=new QStandardItem(outDateStr);
        model->setItem(i,7,item);
    }

    recordTable->setParent(parent);
    //表格横线类型
    recordTable->setShowGrid(Qt::DotLine);
    recordTable->setSelectionBehavior ( QAbstractItemView::SelectRows); //设置选择行为，以行为单位
    recordTable->setModel(model);
    recordTable->resize(parent->width(),parent->height());
    recordTable->setStyleSheet("QTableView { border: none;"
                            "selection-background-color: #8EDE21;"
                            "color: blue}");
    recordTable->setGeometry(x,y,parent->width(),parent->height());
    QItemDelegate* readOnlyDelegate = new QItemDelegate();
    recordTable->setItemDelegate(readOnlyDelegate);
    recordTable->show();
    recordTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList labels = QObject::trUtf8("客户id,客户名,房号,房间折扣,房间价格,房间类型,入住时间,退房时间").simplified().split(",");
     model->setHorizontalHeaderLabels(labels);

     return 0;
}
