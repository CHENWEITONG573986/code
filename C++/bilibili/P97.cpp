#include <iostream>
using namespace std;
// 函数重载
// 1.在同一作用域
// 2.函数名相同
// 3.函数参数类型不同，个数不同，顺序不同
// 空形参
void func()
{
    cout << "1" << endl;
}
// 一个整数形参
void func(int a)
{
    cout << "2" << endl;
}
// 一个高精度浮点形参
void func(double a)
{
    cout << "3" << endl;
}
// 一个整数形参一个高精度浮点形参
void func(int a, double b)
{
    cout << "4" << endl;
}
// 一个高精度浮点形参一个整数形参
void func(double a, int b)
{
    cout << "5" << endl;
}
// 注意事项
// 函数的返回值不可以作为函数重载的条件
// int func()

int main()
{
    func();
    // 函数重载
    func(1);
    // 类型不同
    func(3.14);
    // 个数不同
    func(1, 3.14);
    // 顺序不同
    func(3.14, 1);
    return 0;
}