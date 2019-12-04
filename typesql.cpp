#include "typesql.h"

Typesql::Typesql()
{

}

std::vector<QString> Typesql::findAllType(){
    QSqlDatabase db=dbutil.getDatabase();
    QString sql="select * from type_name";
    std::vector<QString> typeNameVector;
    QSqlQuery query;
    if(query.exec(sql)){
        while(query.next()){
            typeNameVector.push_back(
                        query.value("type").toString()
                        );
        }
    }
    db.close();
    return typeNameVector;
}
