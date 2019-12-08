#include "operata.h"
#include"outtoexcel.h"
#include"date.h"
#include<QFile>
#include<QDebug>
#include<QDateTime>


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
