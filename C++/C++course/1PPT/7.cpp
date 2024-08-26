#include <iostream>
using namespace std;
float area(float); // 先声明
int main()
{
    float radius;
    cout <<"Please input radius : ";
    cin >> radius;
    if (radius > 0)
        cout << area(radius) << endl; // 再使用
    return 0;
}
float area(float r) // 最后定义
{
    return r * r * 3.14159;
}
