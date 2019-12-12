#include "outtoexcel.h"
#include<QFile>
#include<QDir>
//由于导出excel会直接崩溃，所以这些方法没有用到
outToExcel::outToExcel()
{

}
void outToExcel::newExcel(const QString & fileName){
    this->pApplication=new QAxObject();
    //连接EXCEL控件
    pApplication->setControl("Excel.Application");
    //false不显示窗体
    pApplication->dynamicCall("SetVisible(bool)",false);
    //不显示警告
    pApplication->setProperty("DisplayAlerts",false);
    pWorkBooks=pApplication->querySubObject("Workbooks");

    QFile file(fileName);
    //打开文件
    if(file.exists()){
        pWorkBook=pWorkBooks->querySubObject("Open(const QString &)",fileName);
    }else{
     pWorkBooks->dynamicCall("Add");
     pWorkBook=pApplication->querySubObject("ActiveWorkBook");
    }
    pSheets=pWorkBook->querySubObject("Sheets");
    pSheet=pSheets->querySubObject("Item(int)",1);

}
//增加1个Sheet
void outToExcel::appendSheet(const QString & sheetName){
    QAxObject * pLastSheet=pSheets->querySubObject("Item(int)",pSheets->property("Count").toInt());
    pSheets->querySubObject("Add(QVariant)", pLastSheet->asVariant());

    pSheet = pSheets->querySubObject("Item(int)", pSheets->property("Count").toInt());

    pLastSheet->dynamicCall("Move(QVariant)", pSheet->asVariant());

    pSheet->setProperty("Name", sheetName);
}
void outToExcel::setCellValue(int row,int column,const QString & value){
    QAxObject *pRange = pSheet->querySubObject("Cells(int,int)", row, column);

    pRange->dynamicCall("Value", value);
}
void outToExcel::saveExcel(const QString & fileName){
    pWorkBook->dynamicCall("SaveAs(const QString &)",

    QDir::toNativeSeparators(fileName));
}
void outToExcel::freeExcel(){
    if (pApplication != NULL){
    pApplication->dynamicCall("Quit()");
    delete pApplication;
    pApplication = NULL;
    }
}
