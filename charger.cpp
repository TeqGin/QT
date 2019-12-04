#include "charger.h"

Charger::Charger(QString name,QString id,QString sex,QString passWord):Person (name,id,sex,passWord){
   Person::setRole(2);
}
