#include <iostream>
using namespace std;
template <typename T> // 模板声明，其中T为类型参数
T max(T a, T b, T c)  // 定义一个通用函数，用T作虚拟的类型名
{
    if (b > a)
        a = b;
    if (c > a)
        a = c;
    return a;
}
int main()
{
    int i = 8, j = 3, k = 4, h;
    long m = 1, n = 2, p = 3, q;
    h = max(i, j, k); // 调用模板函数，此时T被int取代
    q = max(m, n, p); // 调用模板函数，此时T被long取代
    cout << "int_h=" << h << endl;
    cout << "long_q=" << q << endl;
    return 0;
}
