#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Myfind
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
    for (int i = 0; i < 10; i++)
    {
        V.push_back(i);
    }
    sort(V.begin(), V.end(), Myfind());
    for (auto c : V)
        cout << c << endl;
}

int main()
{
    test01();
}