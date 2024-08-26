#include <iostream>                    //文件包含
using namespace std;                   // 定义命名空间
int main()                             // 主函数头
{                                      // 主函数体
    double x, y;                       // 变量说明
    cout << "Enter two float number:"; // 输出数据
    cin >> x >> y;                     // 输入数据
    double z = x + y;                  // 定义并赋值
    cout << "x+y= " << z << endl;      // 输出数据
    return 0;
}
