#ifndef PERSON_H
#define PERSON_H
#include<QString>
class Person{
private:
    QString name;
    QString PersonId;
    QString sex;
    QString password;
    int role;
public:
    Person();
    Person(QString name);
    Person(QString name,QString PersonId,QString sex,QString password);
    Person(QString name,QString PersonId,QString sex,QString password,int role);
    
    QString getName();
    QString getPersonId();
    QString getSex();
    QString getPassword();
    void setPassword(QString password);
    void setName(QString name);
    void setPersonId(QString id);
    void setSex(QString sex);
    void setRole(int role);
    int getRole();
        
};

#endif // PERSON_H
