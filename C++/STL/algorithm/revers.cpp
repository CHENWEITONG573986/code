#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
void test01()
{
    vector<int> V1;
    string S;
    for (int i = 0; i < 10; i++)
    {
        V1.push_back(i);
    }
    for (char i = 'A'; i <= 'Z'; i++)
        S.push_back(i);
    reverse(V1.begin(), V1.end());
    for (auto c : V1)
        cout << c << " ";
    reverse(S.begin(), S.end());
    cout << S;
}
int main()
{
    test01();
}