#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

// 输出
void print(int val)
{
    cout << val << " ";
}
class Myprint
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};
// 遍历算法for_each
void test01()
{
    vector<int> V;
    for (int i = 0; i < 10; i++)
        V.push_back(i);
    for_each(V.begin(), V.end(), print);
    cout << endl;
    for_each(V.begin(), V.end(), Myprint());
}
int main()
{
    test01();
}