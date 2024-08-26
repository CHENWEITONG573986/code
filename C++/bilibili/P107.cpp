#include <iostream>
using namespace std;
class Person
{
    // 构造函数
    // 1.有参构造函数，无参构造函数
    // 2.普通构造函数，拷贝构造函数
public:
    Person() // 系统默认生成
    {
    }
    Person(int a) // 有参构造函数
    {
        age = a;
    }
    Person(const Person &p) // 拷贝构造函数
    {
        age = p.age;
    }
    int getAge()
    {
        return age;
    }
    ~Person()
    {
    }

private:
    int age;
};
// 构造函数的调用
void sss()
{
    // 括号法
    Person p1; // 不能Person p1();()不能空，不然判定为返回值为Person的函数
    Person p2(10);
    Person p3(p2);
    cout << "p2=" << p2.getAge() << endl;
    cout << "p3=" << p3.getAge() << endl;
    // 显示法
    Person p4 = Person(10); // Person(10)为匿名对象，立刻回收
    Person p5 = Person(p4); // 不要用拷贝构造函数去初始化匿名对象，Person(p3)==Person p3;
    cout << "p4=" << p4.getAge() << endl;
    cout << "p5=" << p5.getAge() << endl;
    // 隐式转换法
    Person p6 = 10; // Person P6=10;==Person p6 = Person(10);
    Person p7 = p6; // Person P7=p6;==Person p7 = Person(p6);
    cout << "p6=" << p6.getAge() << endl;
    cout << "p7=" << p7.getAge() << endl;
}

int main()
{
    sss();
    return 0;
}