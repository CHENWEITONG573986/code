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
// empty()是否为空
// size()大小
// swap()交换
// insert()插入
// erase()删除
// clear()清空
// find()查找
// count()统计个数
class MyCompare
{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};
int main()
{
    set<int> S1;
    S1.insert(30);
    S1.insert(10);
    S1.insert(40);
    S1.insert(50);
    S1.insert(10);
    printSet(S1);
    // 通过仿函数改变排序规则
    set<int, MyCompare> S2;
    S2.insert(30);
    S2.insert(10);
    S2.insert(40);
    S2.insert(50);
    S2.insert(10);
    for (set<int, MyCompare>::const_iterator it = S2.begin(); it != S2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}