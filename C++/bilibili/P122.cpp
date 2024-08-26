#include <iostream>
using namespace std;
class Person
{
public:
    Person()
    {
    }
    Person(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    Person &operator++() // 前置++
    {
        a++;
        b++;
        return *this;
    }
    Person operator++(int) // 后置++
    {
        Person w(*this);
        a++;
        b++;
        return w;
    }
    int a;
    int b;
};

ostream &operator<<(ostream &cout, Person p) // ostream 标准输出流
{
    cout << "a=" << p.a << " b=" << p.b;
    return cout; // 链式编程思想
}

void test()
{
    Person p1(10, 20);
    cout << p1 << endl; // cout << p1的返回值为cout 所以可无限追加<<, 链式编程思想
    cout << ++p1 << endl;
}

void test2()
{
    Person p2(10, 20);
    cout << p2++ << endl;
    cout << p2 << endl;
}

int main()
{
    // 左移运算符重载
    test2();
    return 0;
}