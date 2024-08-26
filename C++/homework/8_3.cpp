#include <iostream>
#include <string>
using namespace std;
//**************************************
class BirthDate
{
public:
    int year;
    int month;
    int day;
};
//**************************************
class Teacher
{
protected:
    int num;
    string name;
    string sex;

public:
};
//**************************************
class Professor : public Teacher
{
private:
    string rresearch;
    BirthDate B;

public:
    Professor(){};
    Professor(int num, string name, string sex, string rresearch, int year, int month, int day);
    void Show();
};
//**************************************
Professor::Professor(int num, string name, string sex, string rresearch, int year, int month, int day)
{
    this->num = num;
    this->name = name;
    this->sex = sex;
    this->rresearch = rresearch;
    this->B.year = year;
    this->B.month = month;
    this->B.day = day;
}
void Professor::Show()
{
    cout << "编号：" << this->num << endl;
    cout << "姓名：" << this->name << endl;
    cout << "性别：" << this->sex << endl;
    cout << "研究：" << this->rresearch << endl;
    cout << "生日：" << this->B.year << "年" << this->B.month << "月" << this->B.day << "日" << endl;
}
//**************************************
int main()
{
    Professor prof(101,"孙小龙","男","计算机",1998,11,11);
    prof.Show();
    return 0;
}
