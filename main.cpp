#include "mainwindow.h"
#include "db_connect.h"
#include"date.h"
#include"roomsql.h"
#include <QApplication>
#include<QMessageBox>
#include<QPushButton>
#include<vector>
#include<QDebug>
#include<QPalette>


int main(int argc, char *argv[])
{
    QApplication::addLibraryPath("./plugins");
    QApplication a(argc, argv);

    RoomSql roomSql;

    MainWindow w;

    w.show();

    return a.exec();
}
