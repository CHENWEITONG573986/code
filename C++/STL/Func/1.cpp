#include <iostream>
#include <string>
using namespace std;
// 仿函数

class MyAdd
{
public:
    int operator()(int A, int B)
    {
        return A + B;
    }
};

class MyPrint
{
public:
    void operator()(string str)
    {
        cout << str << endl;
    }
};
void test01()
{
    MyAdd myadd;
    cout << myadd(10, 10) << endl;
    string str="akhdnawyhuvdauosd";
    MyPrint print;
    print(str);
}

int main()
{
    test01();
}