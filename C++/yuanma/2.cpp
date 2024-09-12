#include <iostream>
using namespace std;
class A
{
public:
    A(int x = 10) { a = x; }
    A(const A &p)
    {
        a = p.a + 2;
        cout << "拷贝构造函数被调用，" << a << endl;
    }
    void display() { cout << a << endl; }

private:
    int a;
};
A f(A a)
{
    return a;
}
int main()
{
    A a1;
    A a2 = a1;
    a2.display();
    a1 = f(a2);
    a1.display();
    return 0;
}