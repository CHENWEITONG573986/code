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
void test01()
{
    list<int> L1;
    L1.push_back(1);
    L1.pop_back();
    L1.push_front(1);
    L1.pop_front();
    L1.insert(L1.begin(), 1);
    L1.insert(L1.begin(), 6, 6);
    L1.insert(L1.begin(), L1.begin(), L1.end());
    printList(L1);
    L1.remove(1);
    printList(L1);
    L1.erase(L1.begin(), ++L1.begin());
    printList(L1);
    L1.erase(L1.begin());
    printList(L1);
    L1.clear();
    cout << L1.size() << endl;
}
int main()
{
    test01();
    return 0;
}