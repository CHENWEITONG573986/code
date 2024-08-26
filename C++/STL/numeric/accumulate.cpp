#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
void test01()
{
    vector<int> V;
    for (int i = 0; i < 100; i++)
    {
        V.push_back(i);
    }
    int sum = accumulate(V.begin(), V.end(), 0);
    cout << sum;
}
int main()
{
    test01();
}