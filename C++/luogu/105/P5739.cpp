#include <iostream>
using namespace std;

void factorial(int n, int &x)
{
    x *= n;
    n--;
    if (n > 1)
        factorial(n, x);
}

int main()
{
    int n;
    cin >> n;
    int x = 1;
    factorial(n, x);
    cout << x;
    return 0;
}