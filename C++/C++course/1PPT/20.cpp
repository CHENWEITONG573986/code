#include <iostream>
using namespace std;
float a = 1.5;
int main()
{
    int a = 5;
    cout << a << endl;   // 输出作用域为main 函数的局部变量a 的值
    cout << ::a << endl; // 输出作用域为全局的 全局变量a 的值
    return 0;
}
