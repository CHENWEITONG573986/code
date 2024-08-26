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
    list<int> L;
    L.push_back(1);
    L.push_back(2);
    cout<< L.front()<<endl;
    cout<<L.back()<<endl;

}
int main()
{
    test01();
    return 0;
}