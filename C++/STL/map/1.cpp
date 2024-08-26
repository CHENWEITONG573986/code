#include <iostream>
#include <map>
using namespace std;
class MyCompare
{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};
void printMap(const map<int, int> &m)
{
    for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key:" << it->first << "\tvalue:" << it->second << endl;
    }
}
void printMap(const map<int, int, MyCompare> &m)
{
    for (map<int, int, MyCompare>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key:" << it->first << "\tvalue:" << it->second << endl;
    }
}
void test01()
{
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(4, 40));
    m.insert(pair<int, int>(5, 50));
    printMap(m);
}
void test02()
{
    map<int, int, MyCompare> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(4, 40));
    m.insert(pair<int, int>(5, 50));
    printMap(m);
}
int main()
{
    test01();
    test02();
    return 0;
}