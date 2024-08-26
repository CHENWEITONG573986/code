#include <iostream>
#include <string>
using namespace std;
class People
{
protected:
    string name;
    string sex;
    int age;

public:
    People(){};
    People(string name, string sex, int age)
        : name(name), sex(sex), age(age){};
    ~People(){};
};
class Student : virtual public People
{
protected:
    int num;
    int scores;

public:
    Student(){};
    Student(string name, string sex, int age, int num, int scores)
        : People(name, sex, age), num(num), scores(scores){};
    ~Student(){};
};
class Teacher : virtual public People
{
protected:
    string job;
    string department;

public:
    Teacher(){};
    Teacher(string name, string sex, int age, string job, string department)
        : People(name, sex, age), job(job), department(department){};
    ~Teacher(){};
};
class GradOnWork : public Student, public Teacher
{
private:
    string research;
    string mentor;

public:
    GradOnWork(){};
    GradOnWork(string name, string sex, int age, int num, int scores, string job, string department, string research, string mentor)
        : People(name, sex, age), Student(name, sex, age, num, scores), Teacher(name, sex, age, job, department), research(research), mentor(mentor){};
    void show();
    ~GradOnWork(){};
};
void GradOnWork::show()
{
    cout << "姓名：" << name << endl;
    cout << "性别：" << sex << endl;
    cout << "年龄：" << age << endl;
    cout << "学号：" << num << endl;
    cout << "分数：" << scores << endl;
    cout << "职务：" << job << endl;
    cout << "部门：" << department << endl;
    cout << "研究方向：" << research << endl;
    cout << "导师：" << mentor << endl;
}
int main()
{
    GradOnWork gdonwk("马嘉祺", "女", 18, 10086, 250, "健身教练", "信息技术学部", "唱跳rap篮球", "蔡徐坤");
    gdonwk.show();
    system("pause");
    return 0;
}