#include <iostream>
#include <deque>
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
deque容器的数据存取
at(int idx); 返回索引idx的数据
operator[];  返回索引idx的数据
front();     返回容器中第一个数据元素
back();      返回容器中最后一个数据元素
*/
void test01()
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    for (int i = 0; i < 10; i++)
    {
        cout << d1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << d1.at(i) << " ";
    }
    cout << endl;
    cout << d1.front() << endl;
    cout << d1.back() << endl;
}

int main()
{
    test01();
    return 0;
}