#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
// 内建函数对象

// negate 一元 取反
void test01()
{
    negate<int> n;
    cout << n(50) << endl;
}
// plus 二元 加法
void test02()
{
    plus<int> p;
    cout << p(2,2) << endl;
}
int main()
{
    test01();
    test02();
}