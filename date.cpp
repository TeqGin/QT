#include "date.h"
#include<time.h>
#include<QString>
#include<QDebug>

Date::Date(){
    time_t timep;
    struct tm *p;

    time(&timep);
    p=localtime(&timep);
    this->year=p->tm_year+1900;
    this->month=p->tm_mon+1;
    this->day=p->tm_mday;
}
Date::Date(int year,int month,int day){
    this->year=year;
    this->month=month;
    this->day=day;
}

//重载date>date运算
bool Date::operator>(Date &date){

    if(this->year>date.year){
        return true;
    }else{
        if(this->year==date.year&&this->month>date.month){
            return true;
        }else{
            if(this->month==date.month&&this->day>date.day){
                return true;
            }
        }
    }
    return false;
}


//重载date+day运算
Date & Date::operator+(int day){
    if(day>0){
        int months[]={31,28,31,30,31,30,31,31,30,31,30,31};
        //判断是否为闰年

        if(this->year%400==0||(this->year%4==0&&this->year%100!=0)){
            months[1]=29;
        }
        int monthNumber=months[this->month-1];

        this->day +=day;
        //循环进行的条件：this->day>monthNumber;
        while(this->day>monthNumber){
            this->day-=monthNumber;
            this->month+=1;
            //判断是否满了一年
            if(this->month>12){
                this->month-=12;
                this->year+=1;
                if(this->year%400==0||(this->year%4==0&&this->year%100!=0)){
                    months[1]=29;
                }else{
                    months[1]=28;
                }
            }
            monthNumber=months[this->month-1];
        }
        return *this;
    }else {
        if(this->day>day){
            this->day-=day;
        }else{
            this->day-=day;int months[]={31,28,31,30,31,30,31,31,30,31,30,31};
            //判断是否为闰年

            if(this->year%400==0||(this->year%4==0&&this->year%100!=0)){
                months[1]=29;
            }
            int monthNumber=months[this->month-2];
            while(this->day<=0){
                this->day+=monthNumber;
                this->month-=1;
                //获取前一个月的天数
                if(this->month==0){
                    this->month=12;
                    this->year-=1;
                    if(this->year%400==0||(this->year%4==0&&this->year%100!=0)){
                        months[1]=29;
                    }else{
                        months[1]=28;
                    }
                }
                monthNumber=months[this->month-2];
            }
    }
        return *this;
}
}
//重载date-day运算
Date & Date::operator-(int day){
    if(day<0){
        int months[]={31,28,31,30,31,30,31,31,30,31,30,31};
        //判断是否为闰年

        if(this->year%400==0||(this->year%4==0&&this->year%100!=0)){
            months[1]=29;
        }
        int monthNumber=months[this->month-1];

        this->day +=day;
        //循环进行的条件：this->day>monthNumber;
        while(this->day>monthNumber){
            this->day-=monthNumber;
            this->month+=1;
            //判断是否满了一年
            if(this->month>12){
                this->month-=12;
                this->year+=1;
                if(this->year%400==0||(this->year%4==0&&this->year%100!=0)){
                    months[1]=29;
                }else{
                    months[1]=28;
                }
            }
            monthNumber=months[this->month-1];
        }
        return *this;
    }else{
        if(this->day>day){
            this->day-=day;
        }else{
            this->day-=day;int months[]={31,28,31,30,31,30,31,31,30,31,30,31};
            //判断是否为闰年

            if(this->year%400==0||(this->year%4==0&&this->year%100!=0)){
                months[1]=29;
            }
            int monthNumber=months[this->month-2];
            while(this->day<=0){
                this->day+=monthNumber;
                this->month-=1;
                //获取前一个月的天数
                if(this->month==0){
                    this->month=12;
                    this->year-=1;
                    if(this->year%400==0||(this->year%4==0&&this->year%100!=0)){
                        months[1]=29;
                    }else{
                        months[1]=28;
                    }
                }
                monthNumber=months[this->month-2];
            }
        }
        return *this;
    }
}

/*
 * @problem
 * 如何计算相差的时间（重载(date-date)-运算符）
 * @way
 *  @one
 *  还原成距离1970-1-1的时间，然后相减。
 *  @two
 *  两个时间直接相减
 *   @how
 *    @first
 *    2019-11-21 - 2019-11-10
 *    如果年份，月份相等，this->day-date.getday();
 *
 *    @second
 *    2019-11-21 - 2019-10-1
 *    如果年份相等，但是月份不相等，把较大的那个日期逐月递减，并且定义的distance=this->day;
 *    然后distance+=months[this->month-2];
 *    最后distance+=months[this->month-2]-date->getDay();
 *
 *    @third
 *    2019-11-21 - 2018-10-1
 *    如果年份不相等，就重复上一步，并month--;如果month<=0;year--；直到月份和年份相等
 *
 *    @fourth
 *    上面三步其实可以合并，判断条件为年份和月份是否一致
 *
*/
int Date::operator-(Date &date){
    //防止修改当前的date,把当前的date复制给另外一个date
    Date big=*this;
    Date small=date;
    int flag=1;
    int distanche=0;
    int monthNumber=0;
    //令big为较大的那一个，并且用flag来标记，如果发生了交换，那么意味着减去的那个值小于被减的值，返回的差额应该为负数
    if(big.getYear()<small.getYear()){
        Date t=big;
        big=small;
        small=t;
        flag=0;
    }else if (big.getMonth()<small.getMonth()) {
        Date t=big;
        big=small;
        small=t;
        flag=0;
   }else if(big.getDay()<small.getDay()){
        Date t=big;
        big=small;
        small=t;
        flag=0;
   }

    int currentMonths[]={31,28,31,30,31,30,31,31,30,31,30,31};
    //判断是否为闰年
    //由于是使用big来逼近small（以small为参考系）所以此处要判断big是否为闰年（因为big会不断变化）
    if(big.getYear()%400==0||(big.getYear()%4==0&&big.getYear()%100!=0)){
        currentMonths[1]=29;
    }

    //处理一开始就相等的情况
    if(big.getYear()==small.getYear()&&big.getMonth()==small.getMonth()){
        distanche+=(big.getDay()-small.getDay());
    }else{
        distanche+=big.getDay();
    }

    //循环进行的条件是big的year大于small的year,或者big的month大于small的month
    while(big.getYear()>small.getYear()||big.getMonth()>small.getMonth()){
        big.setMonth(big.getMonth()-1);
        if(big.getMonth()<=0){
            big.setMonth(12);
            big.setYear(big.getYear()-1);
            if(big.getYear()%400==0||(big.getYear()%4==0&&big.getYear()%100!=0)){
                currentMonths[1]=29;
            }else{
                currentMonths[1]=28;
            }
        }
        //当月份和年份与small相等时
        if(big.getYear()==small.getYear()&&big.getMonth()==small.getMonth()){
            monthNumber=currentMonths[big.getMonth()-1];
            distanche+=(monthNumber-small.getDay());
        }else{
            monthNumber=currentMonths[big.getMonth()-1];
            distanche+=monthNumber;
        }
    }
    if(flag==0){
        distanche=-distanche;
    }
    return distanche;
}

//重载输出流运算符
 std::ostream& operator <<(std::ostream& out,Date &date){
     out<<date.year<<"-"<<date.month<<"-"<<date.day<<std::endl;
    return out;
}
 std::istream & operator>>(std::istream & in , Date &date){
     in>>date.year>>date.month>>date.day;
     return in;
 }
 int Date::getYear(){
     return this->year;
 }
 int Date::getMonth(){
     return this->month;
 }
 int Date::getDay(){
     return this->day;
 }
 void Date::setYear(int year){
     this->year=year;
 }
 void Date::setMonth(int month){
     this->month=month;
 }
 void Date::setDay(int day){
     this->day=day;
 }

 QString Date::toString(){
     return QString::number(this->year)+"年"+QString::number(this->month)+"月"+QString::number(this->day)+"日";
 }

 //把形如yyyy-mm-ddd的字符串转化成Date类型
 Date Date::toDate(QString date){

     int Year=date.section('-',0,0).toInt();
     int Month=date.section('-',1,1).toInt();
     int Day=date.section('-',2,2).toInt();

     return Date(Year,Month,Day);
 }
