#include <iostream>
using namespace std;

class Person
{
public:
    // 静态成员变量
    // 1.所有对象共享同一份数据
    // 2.编译阶段就分配内存
    // 3.类内声明，类外初始化
    static int m;
    int n;
    // 静态成员函数
    // 1.所有成员共享
    // 只能调用静态成员变量
    static void sss()
    {
        m = 100;
        // n=100;
    }
};
int Person::m = 100;
void test()
{
}

int main()
{
    Person p1;
    Person p2;
    cout << p1.m << endl;
    p2.m = 200;
    cout << p1.m << endl;      // 对象访问
    cout << Person::m << endl; // 类名访问
    Person::sss();             // 类名调用函数
}