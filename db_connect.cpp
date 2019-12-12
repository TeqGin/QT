#include"db_connect.h"
#include<exception>

/*
 * 在Qt上使用SQLite的时候(我的程序是使用QMYSQL时会出现这个问题)，如果第二次使用QSqlDatabase::addDatabase()方式时，就会出现以下错误提示：
 *
 * QSqlDatabasePrivate::addDatabase: duplicate connection name 'qt_sql_default_connection', old connection removed.
 *
 * 解决方法是：先判断一下这个默认的连接名是否存在，如果不存在才使用addDatabase()方法，如果存在则使用database()方法。
*/
   QSqlDatabase DButil::getDatabase(){
        QSqlDatabase db;
        try {
            if(!db.open()){
                if(QSqlDatabase::contains("qt_sql_default_connection"))
                  db = QSqlDatabase::database("qt_sql_default_connection");
                else
                  db = QSqlDatabase::addDatabase("QMYSQL");

                db.setHostName("localhost");
                db.setPort(3306);
                db.setDatabaseName("home_work_cpp");
                db.setUserName("root");
                db.setPassword("60870736a");

                if(!db.open()){
                     std::exception r;
                     throw  r;
                }else{
                    qDebug()<<"打开QSqlDatabase(MySQL)成功";
                }
                return db;
            }
        } catch (std::exception e) {
            qDebug() << "打开QSqlDatabase(MySQL)失败";
            qDebug() <<e.what();
        }
        return db;
    }
   //传入sql以查询数据库，然后返回query，该方法适用于不需要其他参数的查询语句
   //对于传入sql的方法，由于有时需要用?来占位，导致参数长度不一致，所以这个方法用的不多
    QSqlQuery DButil::Statement(QString sql){
            QSqlDatabase db= getDatabase();
            QSqlQuery query;
            if(!query.exec(sql)){
                qDebug()<<"query from home_work_cpp error";
                qDebug()<<query.lastError();
            }
            db.close();
            return query;
    }
