#include <iostream>
using namespace std;

int main()
{
    long long a, b, x;
    cin >> a >> b >> x;
    if (float(b) / 3 < a)
    {
        if (b > x % 3 * a)
            cout << x / 3 * b + x % 3 * a << endl;
        else
            cout << x / 3 * b + b << endl;
    }
    else
        cout << x * a << endl;
    return 0;
}