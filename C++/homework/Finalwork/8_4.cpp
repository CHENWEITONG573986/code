#include <iostream>
#include <string>
using namespace std;
class Student
{
protected:
    int snum;
    string name;
    int age;

public:
    Student(){};
    Student(int snum, string name, int age)
        : snum(snum), name(name), age(age){};
    ~Student(){};
};
class Teacher
{
protected:
    int tnum;
    string name;
    string department;

public:
    Teacher(){};
    Teacher(int tnum, string name, string department)
        : tnum(tnum), name(name), department(department){};
    ~Teacher(){};
};
class GradOnWork : public Student, public Teacher
{
private:
    string research;
    string mentor;

public:
    GradOnWork(){};
    GradOnWork(int snum, int tnum, string name, int age, string department, string research, string mentor)
        : Student(snum, name, age), Teacher(tnum, name, department), research(research), mentor(mentor){};
    void show();
    ~GradOnWork(){};
};
void GradOnWork::show()
{
    cout << "学号：" << snum << endl;
    cout << "教师编号：" << tnum << endl;
    cout << "姓名：" << Student::name << endl;
    cout << "年龄：" << age << endl;
    cout << "部门：" << department << endl;
    cout << "研究方向：" << research << endl;
    cout << "导师：" << mentor << endl;
}
int main()
{
    GradOnWork gdonwk(10086, 101, "马嘉祺", 18, "信息技术学部", "嵌入式人工智能", "蔡徐坤");
    gdonwk.show();
}