#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

void print(int val)
{
    cout << val << " ";
}
void test01()
{
    vector<int> V1, V2, V3, V4;
    for (int i = 0; i < 10; i++)
    {
        V1.push_back(i);
        V2.push_back(i + 5);
    }
    V3.resize(max(V1.size(),V2.size()));
    V4.resize(max(V1.size(), V2.size()));
    auto itEnd = set_difference(V1.begin(), V1.end(), V2.begin(), V2.end(), V3.begin());
    for_each(V3.begin(), itEnd, print);
    cout << endl;
    itEnd = set_difference(V2.begin(), V2.end(), V1.begin(), V1.end(), V4.begin());
    for_each(V4.begin(), itEnd, print);
}
int main()
{
    test01();
}