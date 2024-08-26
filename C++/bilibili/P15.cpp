#include <iostream>
using namespace std;

class Person
{
public:
    Person()
    {
    }
    Person(int a)
    {
        age = a;
    }
    Person &And(Person &p) // 返回值必须是引用，如果不是引用，返回的不是p2本身，是重新开辟的对象
    {
        this->age += p.age;
        return *this; // this指针指向调用的本体对象
    }
    // 常函数
    void show() const // const修改this指针，==const Person * const this
    {
        // this->age=100; // this指针可以修改指向的值
        //  this=NULL; this指针不可以修改指向
        this->b = 100; // mutabie可以在常函数中修改
    }
    int age;
    mutable int b;
};
void test()
{
    Person p1(10);
    Person p2(20);
    p2.And(p1).And(p1).And(p1);
    cout << p2.age << endl;
    const Person p3;
    p3.show(); // 常对象只能调用常函数
}

int main()
{
    test();
}