#include <iostream>
using namespace std;

class Person
{
public:
    Person operator+(Person &p)
    {
        Person temp;
        temp.a = a + p.a;
        temp.b = b + p.b;
        return temp;
    }

    int a;
    int b;
};

void test()
{
    Person p1, p2, p3;
    p1.a = 5;
    p1.b = 5;
    p2.a = 5;
    p2.b = 5;
    p3 = p1 + p2; // operator+为系统命名，可以实现直接p1+p2的调用方式
    cout << p3.a << p3.b << endl;
}

int main()
{
    test();
}