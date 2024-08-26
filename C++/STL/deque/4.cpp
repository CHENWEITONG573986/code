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
deque容器的插入和删除
两端插入操作
push_back(elem); 尾部插入
push_front(elem); 头部插入
pop_back(); 尾部删除
pop_front(); 头部删除
指定位置操作
insert(pos,elem); 在pos位置插入一个elem元素
insert(pos,n,elem); 在pos位置插入n个elem元素
insert(pos,beg,end); 在pos位置插入[beg.end]区间的元素
clear(); 清空数据
erase(beg,end); 删除[beg.end]区间的元素
erase(pos); 删除pos位置的元素
*/
void test01()
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
        d1.push_front(i);
    }
    printDeque(d1);

    for (int i = 0; i < 5; i++)
    {
        d1.pop_back();
        d1.pop_front();
    }
    printDeque(d1);

    d1.insert(d1.begin()+5,3,6);
    printDeque(d1);

    deque<int> d2;
    d2.insert(d2.begin(),d1.begin(),d1.end());
    printDeque(d2);

    d2.clear();
    printDeque(d2);

    d1.erase(d1.begin());
    printDeque(d1);

    d1.erase(d1.begin()+5,d1.end());
    printDeque(d1);

}

int main()
{
    test01();
    return 0;
}