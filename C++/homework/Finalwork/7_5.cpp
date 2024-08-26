#include <iostream>
using namespace std;
class Date;
class Time
{
private:
    int hour;
    int minute;
    int sec;
    Date *D;

public:
    void display();
    Time(int hour, int minute, int sec);
};
class Date
{
private:
    int month;
    int day;
    int year;

public:
    void display();
    Date(int year, int month, int day):year(year),month(month),day(day){};
    friend class Time;
};
Time::Time(int hour, int minute, int sec)
{
    this->hour = hour;
    this->minute = minute;
    this->sec = sec;
    D = new Date(2005, 6, 21);
}
void Time::display()
{
    cout << D->year << "年" << D->month << "月" << D->day << "日" << endl;
    cout << this->hour << "时" << this->minute << "分" << this->sec << "秒" << endl;
}
void Date::display()
{
    cout << this->year << "年" << this->month << "月" << this->day << "日" << endl;
}

int main()
{
    Time T(11, 11, 11);
    T.display();
}