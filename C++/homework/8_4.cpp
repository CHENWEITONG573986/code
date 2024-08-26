#include <iostream>
#include <string>
using namespace std;
//**************************************
class Student
{
protected:
    int sID;
    string name;
    int age;

public:
    Student(){};
    Student(int sID, string name, int age);
    ~Student(){};
    void putsID(int sID);
    void putname(string name);
    void putage(int age);
    void ShowsID();
    void Showname();
    void Showage();
};
//**************************************
class Teacher
{
protected:
    int tID;
    string name;
    string department;

public:
    Teacher(){};
    Teacher(int tID, string name, string department);
    ~Teacher(){};
    void puttID(int tID);
    void putname(string name);
    void putdepartment(string department);
    void ShowtID();
    void Showname();
    void Showdepartment();
};
//**************************************
class GradOnwork : public Student, public Teacher
{
private:
    string rresearch;
    string teacher;

public:
    GradOnwork(){};
    GradOnwork(int sID, int tID, string name, int age, string department, string rresearch, string Teacher);
    ~GradOnwork(){};
    void Show();
};
//**************************************
Student::Student(int sID, string name, int age)
{
    this->sID = sID;
    this->name = name;
    this->age = age;
}
void Student::putsID(int sID)
{
    this->sID=sID;
}
void Student::putname(string name)
{
    this->name=name;
}
void Student::putage(int age)
{
    this->age=age;
}
void Student::ShowsID()
{
    cout << "学号：" << this->sID << endl;
}
void Student::Showname()
{
    cout << "姓名：" << this->name << endl;
}
void Student::Showage()
{
    cout << "年龄：" << this->age << endl;
}
//**************************************
Teacher::Teacher(int tID, string name, string department)
{
    this->tID = tID;
    this->name = name;
    this->department = department;
}
void Teacher::puttID(int tID)
{
    this->tID = tID;
}
void Teacher::putname(string name)
{
    this->name = name;
}
void Teacher::putdepartment(string department)
{
    this->department = department;
}
void Teacher::ShowtID()
{
    cout << "教师编号：" << this->tID << endl;
}
void Teacher::Showname()
{
    cout << "姓名：" << this->name << endl;
}
void Teacher::Showdepartment()
{
    cout << "部门：" << this->department << endl;
}
//**************************************
GradOnwork::GradOnwork(int sID, int tID, string name, int age, string department, string rresearch, string teacher)
{
    this->sID = sID;
    this->tID = tID;
    this->Student::name = this->Teacher::name = name;
    this->age = age;
    this->department = department;
    this->rresearch = rresearch;
    this->teacher = teacher;
}
void GradOnwork::Show()
{
    cout << "学号：" << this->sID << endl;
    cout << "教师编号：" << this->tID << endl;
    cout << "姓名：" << this->Student::name << endl;
    cout << "年龄：" << this->age << endl;
    cout << "部门：" << this->department << endl;
    cout << "研究：" << this->rresearch << endl;
    cout << "导师：" << this->teacher << endl;
}
//**************************************
int main()
{
    GradOnwork gdonwk(8848, 101, "吴彦祖", 18, "信息技术部", "计算机", "孙小龙");
    gdonwk.Show();
}
