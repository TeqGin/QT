#ifndef OUTTOEXCEL_H
#define OUTTOEXCEL_H

//原本是使用#include<QAxObject>但是无法找到，所以替换成了下面这个
#include<ActiveQt/QAxObject>

class outToExcel
{
private:
    QAxObject * pApplication=NULL;
    QAxObject * pWorkBooks=NULL;
    QAxObject * pWorkBook=NULL;
    QAxObject * pSheets=NULL;
    QAxObject * pSheet=NULL;
public:
    outToExcel();
    void newExcel(const QString & fileName);
    void appendSheet(const QString & sheetName);
    void setCellValue(int row,int column,const QString & value);
    void saveExcel(const QString & fileName);
    void freeExcel();

};

#endif // OUTTOEXCEL_H
