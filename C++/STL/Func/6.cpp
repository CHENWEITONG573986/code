#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
// 逻辑仿函数
void test01()
{
    vector<bool> V, V2;
    V.push_back(false);
    V.push_back(true);
    V.push_back(false);
    V.push_back(true);
    V.push_back(true);
    V.push_back(false);
    V.push_back(true);
    V.push_back(false);
    for (auto c : V)
        cout << c << endl;
    // 取反
    V2.resize(V.size());
    // 搬运
    transform(V.begin(), V.end(), V2.begin(), logical_not<bool>());
    for (auto c : V2)
        cout << c << endl;
}
int main()
{
    test01();
}