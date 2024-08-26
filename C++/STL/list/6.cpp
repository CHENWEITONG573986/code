#include <iostream>
#include <list>
using namespace std;
void printList(const list<int> &L)
{
    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
// list反转和排序

// 反转
void test01()
{
    list<int> L;
    for (int i = 0; i < 10; i++)
    {
        L.push_back(i);
    }
    printList(L);
    L.reverse();
    printList(L);
}

// 降序
bool myCompare(int a, int b)
{
    return a > b;
}

// 排序
void test02()
{
    list<int> L;
    L.push_back(30);
    L.push_back(20);
    L.push_back(50);
    L.push_back(10);
    L.push_back(40);
    printList(L);
    // list自带sort,list的迭代器不支持随机访问，所以不能用公用sort。
    L.sort();
    printList(L);
    // 降序
    L.sort(myCompare);
    printList(L);
}

int main()
{
    test01();
    test02();
    return 0;
}