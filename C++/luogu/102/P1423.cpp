#include <iostream>
using namespace std;
int main()
{
    double s;
    cin >> s;
    double x = 0, L = 2;
    int num = 0;
    while (x <= s)
    {
        x += L;
        L *= 0.98;
        num++;
    }
    cout << num;
}