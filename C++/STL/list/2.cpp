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
// list容器的赋值和交换
// 赋值
void test01()
{
    list<int> L1;
    for (int i = 0; i < 10; i++)
    {
        L1.push_back(i);
    }
    printList(L1);
    // 1
    list<int> L2;
    L2 = L1;
    printList(L2);
    // 2
    list<int> L3;
    L3.assign(L2.begin(), L2.end());
    printList(L3);
    // 3
    list<int> L4;
    L4.assign(10, 100);
    printList(L4);
}
// 交换
void test02()
{
    list<int> L1;
    for (int i = 0; i < 10; i++)
    {
        L1.push_back(i);
    }
    list<int> L2;
    L2.assign(10,100);
    printList(L1);
    printList(L2);
    L1.swap(L2);
    printList(L1);
    printList(L2);
}
int main()
{
    test01();
    test02();
    return 0;
}