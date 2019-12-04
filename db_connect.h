#ifndef DB_CONNECT_H
#define DB_CONNECT_H
#include <QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql>
#include <QDebug>

class DButil{
public:
    static QSqlDatabase getDatabase();
    //对数据库进行操作
    static QSqlQuery Statement(QString sql);

};

#endif // DB_CONNECT_H
