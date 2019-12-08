#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"loginface.h"
#include"chargeface.h"
#include"dialog.h"
#include"guests.h"

#include"domain.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //声明这是槽函数
private slots:
    void login();
    void registered();

private:
    Ui::MainWindow *ui;
    Dialog dialog;
    LoginFace loginFace;
    ChargeFace chargeFace;
    Operata operata;
};

#endif // MAINWINDOW_H
