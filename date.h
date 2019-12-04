#ifndef DATE_H
#define DATE_H

#include<iostream>
#include<QString>

class Date
{
private:
    int year;
    int month;
    int day;
public:
    Date();
    Date(int year,int month,int day);


    Date & operator +(int day);

    int operator -(Date & date);
    Date & operator -(int day);

    friend std::ostream& operator<<(std::ostream& out,Date &date);
    friend std::istream & operator>>(std::istream & in , Date &date);
    int getYear();
    int getMonth();
    int getDay();

    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);

    QString toString();
};

#endif // DATE_H
