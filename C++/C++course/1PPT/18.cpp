#include <iostream>
using namespace std;
inline int power(int x) // 定义一个内联函数
{
    return x * x;
}
int main()
{
    cout << power(2) << endl;     // 编译系统展开为{x=2;x*x;}
    cout << power(1 + 2) << endl; // 编译系统展开为{x=1+2;x*x;}
    return 0;
}
