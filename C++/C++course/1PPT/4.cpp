#include <iostream>
using namespace std;
int max(int a, int b); // 声明一个整型函数max，有两个整型参数a，b
int main()
{
    int x, y, z;
    cout << "input two numbers:\n";
    cin >> x >> y; // 从键盘输入两个整型值到变量x，y
    z = max(x, y); // 调用max函数，并传递参数x,y。然后将返回值赋给z
    cout << "max=" << z << endl;
    return 0;
}
int max(int a, int b) // 定义max函数，有两个整型参数a，b
{
    if (a > b)
        return a;
    else
        return b;
}
