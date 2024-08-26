#include <iostream>
using namespace std;
int max(int a, int b, int c = 100)
{
    if (b > a)
        a = b;
    if (c > a)
        a = c;
    return a;
}
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int main()
{
    int a = 7, b = -4, c;
    cout << max(a, b, c) << endl;
    //cout << max(a, b) << endl;
    return 0;
}
