#include <iostream> // 引入iostream库，用于输出
#include <vector>  // 引入vector库，用于存储二维数组
#include <algorithm> // 引入algorithm库，用于排序
#include <string> // 引入string库，用于字符串
using namespace std; // 使用std命名空间

void test01() // 定义函数test01
{
    vector<vector<int>> v; // 定义一个二维数组v
    vector<int> v1; // 定义一个一维数组v1
    vector<int> v2; // 定义一个一维数组v2
    vector<int> v3; // 定义一个一维数组v3
    vector<int> v4; // 定义一个一维数组v4
    for (int i = 0; i < 4; i++ ) // 循环，共4次
    {
        v1.push_back(i); // 将i插入v1数组
        v2.push_back(i + 1); // 将i+1插入v2数组
        v3.push_back(i + 2); // 将i+2插入v3数组
        v4.push_back(i + 3); // 将i+3插入v4数组
    }
    v.push_back(v1); // 将v1数组插入二维数组v
    v.push_back(v2); // 将v2数组插入二维数组v
    v.push_back(v3); // 将v3数组插入二维数组v
    v.push_back(v4); // 将v4数组插入二维数组v
    // 遍历二维数组
    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++ ) // 遍历二维数组v
    {
        for (vector<int>::iterator vit = it->begin(); vit != it->end(); vit++ ) // 遍历一维数组it
        {
            cout << *vit << " "; // 输出一维数组it的元素
        }
        cout << endl; // 换行
    }
}
int main() // 主函数
{
    test01(); // 调用函数test01
    system("pause"); // 暂停程序
    return 0; // 返回0
}