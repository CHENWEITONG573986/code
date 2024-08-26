#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, num = 1;
    cin >> n;
    for (int i = 1; i < n; i++)
        num = (num + 1) * 2;
    cout << num;
    return 0;
}