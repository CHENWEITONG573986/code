#include <iostream>
#include <string>
using namespace std;
//*******************************************************
class People
{
protected:
    string Name;
    string Sex;
    int Age;

public:
    People(){};
    People(string name, string sex, int age) : Name(name), Sex(sex), Age(age){};
    ~People(){};
    void Show();
};
void People::Show()
{
    cout << "姓名：" << this->Name << endl;
    cout << "性别：" << this->Sex << endl;
    cout << "年龄：" << this->Age << endl;
}
//*******************************************************
class Student : virtual public People
{
protected:
    int ID;
    int Scores;

public:
    Student(){};
    Student(string name, string sex, int age, int id, int scores)
        : People(name, sex, age), ID(id), Scores(scores){};
    ~Student(){};
    void Show();
};
void Student::Show()
{
    cout << "姓名：" << this->Name << endl;
    cout << "性别：" << this->Sex << endl;
    cout << "年龄：" << this->Age << endl;
    cout << "学号：" << this->ID << endl;
    cout << "分数：" << this->Scores << endl;
}
//*******************************************************
class Teacher : virtual public People
{
protected:
    string Job;
    string Department;

public:
    Teacher(){};
    Teacher(string name, string sex, int age, string job, string department)
        : People(name, sex, age), Job(job), Department(department){};
    ~Teacher(){};
    void Show();
};
void Teacher::Show()
{
    cout << "姓名：" << this->Name << endl;
    cout << "性别：" << this->Sex << endl;
    cout << "年龄：" << this->Age << endl;
    cout << "职务：" << this->Job << endl;
    cout << "部门：" << this->Department << endl;
}
//*******************************************************
class GradOnWor : public Student, public Teacher
{
protected:
    string Rresearch;
    string Mentor;

public:
    GradOnWor(){};
    GradOnWor(string name, string sex, int age, int id, int scores, string job, string department, string rresearch, string mentor)
        : People(name, sex, age), Student(name, sex, age, id, scores), Teacher(name, sex, age, job, department), Rresearch(rresearch), Mentor(mentor){};
    ~GradOnWor(){};
    void Show();
};
void GradOnWor::Show()
{
    cout << "姓名：" << this->Name << endl;
    cout << "性别：" << this->Sex << endl;
    cout << "年龄：" << this->Age << endl;
    cout << "学号：" << this->ID << endl;
    cout << "分数：" << this->Scores << endl;
    cout << "职务：" << this->Job << endl;
    cout << "部门：" << this->Department << endl;
    cout << "研究：" << this->Rresearch << endl;
    cout << "导师：" << this->Mentor << endl;
}
//*******************************************************
int main()
{
    GradOnWor gdonwk("李洛", "男", 18, 101, 750, "教导学生", "信息技术学部", "计算机", "孙小龙");
    gdonwk.Show();
}