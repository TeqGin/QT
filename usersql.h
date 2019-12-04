#ifndef USERSQL_H
#define USERSQL_H
#include"db_connect.h"
#include"person.h"


class UserSql
{
private:
   DButil dbutil;
public:
    UserSql();
    bool insert(Person person);
    bool update(Person person);
    std::vector<Person> findAllUser();
    Person findUserById(QString id);
};

#endif // USERSQL_H

