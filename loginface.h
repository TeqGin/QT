#ifndef LOGINFACE_H
#define LOGINFACE_H

#include <QDialog>
#include<QTableView>

namespace Ui {
class LoginFace;
}

class LoginFace : public QDialog
{
    Q_OBJECT

public:
    explicit LoginFace(QWidget *parent = nullptr);
    ~LoginFace();
    void creatTable();

private:
    QTableView *roomTable=new QTableView;
    Ui::LoginFace *ui;
};

#endif // LOGINFACE_H
