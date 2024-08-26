#include <iostream>
using namespace std;
float area(float r)
{
    return r * r * 3.14159;
} // 先定义
int main()
{
    float radius;
    cout << "Please input radius : ";
    cin >> radius;
    if (radius > 0)
        cout << area(radius) << endl; // 再使用
    return 0;
}
