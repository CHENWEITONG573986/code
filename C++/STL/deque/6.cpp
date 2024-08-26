#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void printDeque(const deque<int> &d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
/*
deque容器的排序
sort(iterator beg,iterator end) 对[beg,end]区间元素排序
*/
void test01()
{
    deque<int> d;
    d.push_back(20);
    d.push_back(40);
    d.push_back(10);
    d.push_back(30);
    d.push_back(90);
    d.push_back(50);
    printDeque(d);
    // 排序 sort默认从小到大
    sort(d.begin(),d.end());
    printDeque(d);
}
int main()
{
    test01();
    return 0;
}