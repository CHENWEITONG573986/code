#include<iostream>
#define PI 3.14
using namespace std;
// 设计封装一个类
class Circle // 圆类
{
public: // 访问权限，公共权限
    // 属性
    int r; // 半径
    // 行为
    double circumference() // 求圆的周长
    {
        return 2*PI*r;
    }
};

int main()
{
    // 创建圆类的对象
    Circle c1;
    c1.r=10; // 给圆c1的属性r赋值为10
    cout << c1.circumference() << endl; // 使用圆c1的求周长行为
    return 0;
}