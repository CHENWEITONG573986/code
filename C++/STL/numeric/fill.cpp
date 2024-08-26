#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
void test01()
{
    vector<int> V;
    V.resize(10);
    fill(V.begin(), V.end(), 10);
    for (int c : V)
        cout << c << " ";
    cout << endl;
    int sum = accumulate(V.begin(), V.end(), 0);
    cout << sum;
}
int main()
{
    test01();
}