#include <iostream>
#include <string>
using namespace std;
class BirthDate
{
public:
    int year;
    int month;
    int day;

public:
    BirthDate(){};
    BirthDate(int year, int month, int day)
        : year(year), month(month), day(day){};
    ~BirthDate(){};
};
class Teacher
{
protected:
    int num;
    string name;
    string sex;

public:
    Teacher(){};
    Teacher(int num, string name, string sex)
        : num(num), name(name), sex(sex){};
    ~Teacher(){};
};
class Professor : public Teacher
{
private:
    BirthDate *B;
    string research;

public:
    Professor(){};
    Professor(int num, string name, string sex, int year, int month, int day, string research)
        : Teacher(num, name, sex), research(research) { B = new BirthDate(year, month, day); };
    void show();
    ~Professor();
};

Professor::~Professor()
{
    if (B != NULL)
    {
        delete B;
        B = NULL;
    }
}
void Professor::show()
{
    cout << "编号：" << num << endl;
    cout << "姓名：" << name << endl;
    cout << "性别：" << sex << endl;
    cout << "研究方向：" << research << endl;
    cout << "生日：" << B->year << "年 " << B->month << "月 " << B->day << "日" << endl;
}
int main()
{
    Professor prof(101, "马嘉祺", "男", 2005, 6, 21, "唱跳rap篮球");
    prof.show();
    system("pause");
    return 0;
}