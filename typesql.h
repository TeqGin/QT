#ifndef TYPESQL_H
#define TYPESQL_H
#include<vector>
#include<QString>
#include"db_connect.h"

class Typesql
{
private:
    DButil dbutil;
public:
    Typesql();
    std::vector<QString> findAllType();
};

#endif // TYPESQL_H
