#include <iostream>
#include <deque>
using namespace std;
// deque的赋值
void printDeque(const deque<int> &d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);

    // =号赋值
    deque<int> d2;
    d2 = d1;
    printDeque(d2);

    // assign
    deque<int> d3;
    d3.assign(d2.begin(),d2.end());
    printDeque(d3);

    // n个数
    deque<int> d4;
    d4.assign(10,100);
    printDeque(d4);
}

int main()
{
    test01();
    return 0;
}