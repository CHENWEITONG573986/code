#include<iostream>
using namespace std;

int& test1()
{
    static int a=10;//ststic把a的内存从栈区转换到全局区
    return a;
}

int main()
{
    //不要返回局部变量的引用
    int& ref=test1();
    cout << "ref=" << ref << endl;
    cout << "ref=" << ref << endl;
    test1()=1000;//引用可以做左值
    cout << "ref=" << ref << endl;
    cout << "ref=" << ref << endl;;
    system("pause");
    return 0;
}