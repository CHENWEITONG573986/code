#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 二元谓词

class MyCompare
{
public:
    bool operator()(int A, int B)
    {
        return A > B;
    }
};

void test01()
{
    vector<int> V;
    V.push_back(3);
    V.push_back(1);
    V.push_back(4);
    V.push_back(2);
    V.push_back(5);
    // 排序
    sort(V.begin(), V.end());
    for (auto c : V)
        cout << c << endl;
    //
    sort(V.begin(), V.end(), MyCompare());
    for (auto c : V)
        cout << c << endl;
}
int main()
{
    test01();
}