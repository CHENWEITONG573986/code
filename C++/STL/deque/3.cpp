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
deque的大小操作
deque.empty(); 判断容器是否为空
deque.size(); 返回容器中元素的个数
deque.resize(num); 重新定义容器长度，边长填充默认，变短删除末尾超出元素
deque.resize(num,elem); 以elem填充
*/
void test01()
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);
    d1.clear();
    if (d1.empty())
    {
        cout << "d1为空" << endl;
    }
    d1.resize(10);
    printDeque(d1);
    d1.resize(15,10);
    printDeque(d1); 
}

int main()
{
    test01();
    return 0;
}