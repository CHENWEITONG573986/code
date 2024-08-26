#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// vector存放内置数据类型
int a = 0;
void MyPrint(int val)
{
    cout << val << endl;
    a += val;
}

void test01()
{
    // 创建一个vector容器
    vector<int> v;
    // 插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    // itBegin 是一个指针，通过begin()函数获取指向第一个元素
    // itEnd 是一个指针，通过end()函数获取指向最后一个元素的下一个位置
    vector<int>::iterator itBegin = v.begin(); // 起始迭代器
    vector<int>::iterator itEnd = v.end();     // 结束迭代器
    // 第一种遍历
    while (itBegin != itEnd)
    {
        cout << *itBegin << endl;
        itBegin++;
    }
    // 第二种遍历
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
    // 第三种遍历
    for_each(v.begin(), v.end(), MyPrint);
    cout << "a=" << a << endl;
}
int main()
{
    test01();
    return 0;
}