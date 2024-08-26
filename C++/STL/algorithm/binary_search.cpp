#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
// 二分查
void test01()
{
    vector<int> V;
    for (int i = 0; i < 10; i++)
    {
        V.push_back(i);
    }
    auto ret = binary_search(V.begin(), V.end(), 9);
    if (ret)
    {
        cout << "有" << endl;
    }
    else
    {
        cout << "无" << endl;
    }
}

int main()
{
    test01();
    return 0;
}