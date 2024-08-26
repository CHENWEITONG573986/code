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
// list容器大小操作
void test01()
{
    list<int> L1;
    L1.push_back(1);
    L1.push_back(2);
    L1.push_back(3);
    L1.push_back(4);
    L1.push_back(5);
    printList(L1);
    if(!L1.empty())
    {
    }
    // 指定大小
    L1.resize(10,6);
    printList(L1);
}
int main()
{
    test01();
    return 0;
}