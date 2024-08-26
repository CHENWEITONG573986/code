#include <iostream>
#include <set>
using namespace std;
void printSet(const set<int> &S)
{
    for (set<int>::const_iterator it = S.begin(); it != S.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
// set自动排序
void test01()
{
    set<int> S;
    // 只有insert
    S.insert(3);
    S.insert(5);
    S.insert(2);
    S.insert(1);
    printSet(S);
}

int main()
{
    test01();
    return 0;
}