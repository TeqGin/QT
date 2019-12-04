#include "usersql.h"

UserSql::UserSql()
{

}

bool UserSql::insert(Person person){
    QSqlDatabase db=dbutil.getDatabase();
    QString sql="insert into user(id,name,password,role,sex) values(?,?,?,?,?)";
    QSqlQuery query;
    query.prepare(sql);
    query.addBindValue(person.getPersonId());
    query.addBindValue(person.getName());
    query.addBindValue(person.getPassword());
    query.addBindValue(person.getRole());
    query.addBindValue(person.getSex());
    if(query.exec()){
        return true;
    }else{
        return false;
    }
}

bool UserSql::update(Person person){
    QSqlDatabase db=dbutil.getDatabase();
    QString sql="update user set name=?,password=?,role=?,sex=? where id=?";
    QSqlQuery query;
    query.prepare(sql);

    query.addBindValue(person.getName());
    query.addBindValue(person.getPassword());
    query.addBindValue(person.getRole());
    query.addBindValue(person.getSex());
    query.addBindValue(person.getPersonId());

    if(query.exec()){
        return true;
    }else{
        return false;
    }
}

std::vector<Person> UserSql::findAllUser(){
    QSqlDatabase db=dbutil.getDatabase();
    QString sql="select * from user";
    QSqlQuery query;
    std::vector<Person> userVector;
    if(query.exec(sql)){
        while(query.next()){
            Person person(
                        query.value("name").toString(),
                        query.value("id").toString(),
                        query.value("sex").toString(),
                        query.value("password").toString(),
                        query.value("role").toInt()
                        );
            userVector.push_back(person);
        }
    }
    db.close();
    return userVector;
}

Person UserSql::findUserById(QString id){
    QSqlDatabase db=dbutil.getDatabase();
    QString sql="select * from user where id=?";
    QSqlQuery query;
    query.prepare(sql);
    query.addBindValue(id);
    if(query.exec()){
        if(query.next()){
            Person person(
                        query.value("name").toString(),
                        query.value("id").toString(),
                        query.value("sex").toString(),
                        query.value("password").toString(),
                        query.value("role").toInt()
                        );
            db.close();
            return person;
        }
    }
    db.close();
    return Person();
}
