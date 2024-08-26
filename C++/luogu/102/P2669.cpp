#include <iostream>
using namespace std;
int main()
{
    int k;
    cin >> k;
    int n = 0, i = 0, num = 0;
    while (n <= k)
    {
        i++;
        n += i;
        num += i*i;
    }
    num -= i*i;
    n -= i;
    num += (k - n) * i;
    cout << num;
}